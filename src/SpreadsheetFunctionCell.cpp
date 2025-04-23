#include "SpreadsheetCell.h"
#include "SpreadsheetFunctionCell.h"

#include <stdexcept>

SpreadsheetFunctionCell::SpreadsheetFunctionCell(SpreadsheetCell* const argument) {
    addArgumentWithoutUpdate(argument); // It is the responsibility of the constructors of classes derived from this one to call the "update()" method.
}

SpreadsheetFunctionCell::SpreadsheetFunctionCell(const std::set<SpreadsheetCell*>& args) {
    for (auto itr = args.cbegin(); itr != args.cend(); ++itr ) {
        addArgumentWithoutUpdate(*itr); // It is the responsibility of the constructors of classes derived from this one to call the "update()" method.
    }
}

SpreadsheetFunctionCell::~SpreadsheetFunctionCell() {
    while (!cellsArguments.empty()) {
        removeArgumentWithoutUpdate(*(cellsArguments.begin()));
    }
}

std::set<SpreadsheetCell*> SpreadsheetFunctionCell::getArguments() const {
    return cellsArguments;
}

void SpreadsheetFunctionCell::addArgument(SpreadsheetCell* const argumentToAdd) {
    if ( argumentToAdd != nullptr ) {
        if ( dynamic_cast<SpreadsheetFunctionCell*>(argumentToAdd) != nullptr ) {
            if (dynamic_cast<SpreadsheetFunctionCell*>(argumentToAdd) == dynamic_cast<SpreadsheetFunctionCell*>(this) ) {
                // This prevents the circular reference of a cell
                //TODO: Implement a system to detect more complex circular references
                throw std::invalid_argument(" "); //TODO: add error message
            }
        }
        if ( (cellsArguments.emplace(argumentToAdd)).second ) { //This if prevent a circle infinite loop with addObserver method
            try {
                argumentToAdd->addObserver(this);
            }
            catch (...) {
                cellsArguments.erase(argumentToAdd);
                throw std::runtime_error(" "); // TODO: add error message
            }
            this->update();
        }
    }
}

void SpreadsheetFunctionCell::removeArgument(SpreadsheetCell* const argumentToRemove) {
    if ( cellsArguments.erase(argumentToRemove) == 1 && argumentToRemove != nullptr ) { //This if prevent a circle infinite loop with removeObserver method
        argumentToRemove->removeObserver(this);
        this->update();
    }
}

void SpreadsheetFunctionCell::addArgumentWithoutUpdate(SpreadsheetCell* const argumentToAdd) {
    if ( argumentToAdd != nullptr ) {
        if ( dynamic_cast<SpreadsheetFunctionCell*>(argumentToAdd) != nullptr ) {
            if (dynamic_cast<SpreadsheetFunctionCell*>(argumentToAdd) == dynamic_cast<SpreadsheetFunctionCell*>(this) ) {
                // This prevents the circular reference of a cell
                throw std::invalid_argument(" "); //TODO: add error message
            }
        }
        if ( (cellsArguments.emplace(argumentToAdd)).second ) { //This if prevent a circle infinite loop with addObserver method
            try {
                argumentToAdd->addObserver(this);
            }
            catch (...) {
                cellsArguments.erase(argumentToAdd);
                throw std::runtime_error(" "); // TODO: add error message
            }
        }
    }
}

void SpreadsheetFunctionCell::removeArgumentWithoutUpdate(SpreadsheetCell* const argumentToRemove) {
    if ( cellsArguments.erase(argumentToRemove) == 1 && argumentToRemove != nullptr ) { //This if prevent a circle infinite loop with removeObserver method
        argumentToRemove->removeObserver(this);
    }
}
