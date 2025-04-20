#include "SpreadsheetCell.h"

#include <stdexcept>

#include "SpreadsheetFunctionCell.h"

Spreadsheet::Cell::~Cell() {
    for ( auto itr = functionCellsObservers.begin(); itr != functionCellsObservers.end(); ++itr ) {
        (*itr)->removeArgument(this);
    }
}


void Spreadsheet::Cell::notify() {
    for ( auto itr = functionCellsObservers.begin(); itr != functionCellsObservers.end(); ++itr ) {
        (*itr)->update();
    }
}

void Spreadsheet::Cell::addObserver(Observer* const observer) {
    Spreadsheet::FunctionCell* const convertedPointer = dynamic_cast<Spreadsheet::FunctionCell*>(observer);
    if ( convertedPointer == nullptr ) {
        // The object pointed from the 'observer' pointer must be a Spreadsheet::FunctionCell object (or derived)
        throw std::invalid_argument(" "); //TODO: add error message
    }
    if ( dynamic_cast<Spreadsheet::FunctionCell*>(this) != nullptr ) {
        if ( dynamic_cast<Spreadsheet::FunctionCell*>(this) == convertedPointer ) {
            // This prevents the circular reference of a cell
            throw std::invalid_argument(" "); //TODO: add error message
        }
    }
    if ( (functionCellsObservers.emplace(convertedPointer)).second ) { //This if prevent a circle infinite loop with addArgument method
        try {
            convertedPointer->addArgument(this);
        }
        catch (...) {
            functionCellsObservers.erase(convertedPointer);
        }
    }
}

void Spreadsheet::Cell::removeObserver(Observer* const observer) {
    Spreadsheet::FunctionCell* const convertedPointer = dynamic_cast<Spreadsheet::FunctionCell*>(observer);
    if ( convertedPointer == nullptr ) {
        // The object pointed from the 'observer' pointer must be a Spreadsheet::FunctionCell object (or derived)
        throw std::invalid_argument(" "); //TODO: add error message
    }
    if ( functionCellsObservers.erase(convertedPointer) == 1 ) { //This if prevent a circle infinite loop with removeArgument method
        convertedPointer->removeArgument(this);
    }
}


