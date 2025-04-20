#include <stdexcept>

#include "SpreadsheetFunctionCell.h"

Spreadsheet::FunctionCell::~FunctionCell() {
    for (auto itr = cellsArguments.begin(); itr != cellsArguments.end(); ++itr ) {
        (*itr)->removeObserver(this);
    }
}

Spreadsheet::FunctionCell::FunctionCell(Spreadsheet::Cell* const argument) {
    addArgument(argument);
}

Spreadsheet::FunctionCell::FunctionCell(const std::set<Spreadsheet::Cell*>& args) {
    for (auto itr = args.cbegin(); itr != args.cend(); ++itr ) {
        addArgument(*itr);
    }
}

void Spreadsheet::FunctionCell::addArgument(Spreadsheet::Cell* const argumentToAdd) {
    if ( argumentToAdd != nullptr ) {
        if ( dynamic_cast<Spreadsheet::FunctionCell*>(argumentToAdd) != nullptr ) {
            if (dynamic_cast<Spreadsheet::FunctionCell*>(argumentToAdd) == dynamic_cast<Spreadsheet::FunctionCell*>(this) ) {
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

void Spreadsheet::FunctionCell::removeArgument(Spreadsheet::Cell* const argumentToRemove) {
    if ( cellsArguments.erase(argumentToRemove) == 1 && argumentToRemove != nullptr ) { //This if prevent a circle infinite loop with removeObserver method
        argumentToRemove->removeObserver(this);
        this->update();
    }
}

std::set<Spreadsheet::Cell*> Spreadsheet::FunctionCell::getArguments() const {
    return cellsArguments;
}
