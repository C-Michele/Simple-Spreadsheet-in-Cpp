#include <stdexcept>

#include "SpreadsheetCell.h"
#include "SpreadsheetFunctionCell.h"

SpreadsheetCell::~SpreadsheetCell() {
    for ( auto itr = functionCellsObservers.begin(); itr != functionCellsObservers.end(); ++itr ) {
        dynamic_cast<SpreadsheetFunctionCell*>(*itr)->removeArgument(this); //TODO: check the correctness of this line
    }
}

void SpreadsheetCell::notify() {
    for ( auto itr = functionCellsObservers.begin(); itr != functionCellsObservers.end(); ++itr ) {
        (*itr)->update();
    }
}

void SpreadsheetCell::addObserver(Observer* const observer) {
    SpreadsheetFunctionCell* const convertedPointer = dynamic_cast<SpreadsheetFunctionCell*>(observer);
    if ( convertedPointer == nullptr ) {
        // The object pointed from the 'observer' pointer must be a SpreadsheetFunctionCell object (or derived)
        throw std::invalid_argument(" "); //TODO: add error message
    }
    if ( dynamic_cast<SpreadsheetFunctionCell*>(this) != nullptr ) {
        if ( dynamic_cast<SpreadsheetFunctionCell*>(this) == convertedPointer ) {
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

void SpreadsheetCell::removeObserver(Observer* const observer) {
    SpreadsheetFunctionCell* const convertedPointer = dynamic_cast<SpreadsheetFunctionCell*>(observer);
    if ( convertedPointer == nullptr ) {
        // The object pointed from the 'observer' pointer must be a SpreadsheetFunctionCell object (or derived)
        throw std::invalid_argument(" "); //TODO: add error message
    }
    if ( functionCellsObservers.erase(convertedPointer) == 1 ) { //This if prevent a circle infinite loop with removeArgument method
        convertedPointer->removeArgument(this);
    }
}
