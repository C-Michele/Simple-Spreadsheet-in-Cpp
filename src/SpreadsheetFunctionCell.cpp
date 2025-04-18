#include <stdexcept>

#include "SpreadsheetFunctionCell.h"

void Spreadsheet::FunctionCell::addArgument(Spreadsheet::Cell* const argumentToAdd) {
    if ( argumentToAdd != nullptr ) {
        if ( dynamic_cast<Spreadsheet::FunctionCell*>(argumentToAdd) != nullptr ) {
            if (dynamic_cast<Spreadsheet::FunctionCell*>(argumentToAdd) == dynamic_cast<Spreadsheet::FunctionCell*>(this) ) {
                // This prevents the circular reference of a cell
                throw std::invalid_argument(" "); //TODO: add error message
            }
        }
        cellsArguments.emplace(argumentToAdd);
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

void Spreadsheet::FunctionCell::removeArgument(Spreadsheet::Cell* const argumentToRemove) {
    cellsArguments.erase(argumentToRemove);
    this->update();
}

std::set<Spreadsheet::Cell*> Spreadsheet::FunctionCell::getArguments() const {
    return cellsArguments;
}
