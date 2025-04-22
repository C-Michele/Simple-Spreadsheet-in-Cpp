#include "SpreadsheetCell.h"
#include "SpreadsheetFunctionCell.h"

#include <stdexcept>

SpreadsheetFunctionCell::SpreadsheetFunctionCell(SpreadsheetCell* const argument) {
    addArgument(argument);
}

SpreadsheetFunctionCell::SpreadsheetFunctionCell(const std::set<SpreadsheetCell*>& args) {
    for (auto itr = args.cbegin(); itr != args.cend(); ++itr ) {
        addArgument(*itr);
    }
}

SpreadsheetFunctionCell::~SpreadsheetFunctionCell() {
    for (auto itr = cellsArguments.begin(); itr != cellsArguments.end(); ++itr ) {
        (*itr)->removeObserver(this);
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
                throw std::invalid_argument(" "); //TODO: add error message
            }
        }
        if ( (cellsArguments.emplace(argumentToAdd)).second ) { //This if prevent a circle infinite loop with addObserver method
            bool exceptionThrown = false;
            try {
                argumentToAdd->addObserver(this);
            }
            catch (...) {
                exceptionThrown = true;
            }
            if (exceptionThrown) {
                cellsArguments.erase(argumentToAdd);
            }
            else {
                this->update();
            }
        }
    }
}

void SpreadsheetFunctionCell::removeArgument(SpreadsheetCell* const argumentToRemove) {
    if ( cellsArguments.erase(argumentToRemove) == 1 && argumentToRemove != nullptr ) { //This if prevent a circle infinite loop with removeObserver method
        argumentToRemove->removeObserver(this);
        this->update();
    }
}