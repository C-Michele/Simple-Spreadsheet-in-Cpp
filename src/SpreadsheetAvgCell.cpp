#include "SpreadsheetAvgCell.h"

#include <stdexcept>

SpreadsheetAvgCell::SpreadsheetAvgCell(SpreadsheetCell* const argument) : SpreadsheetNumericFunctionCell(argument), avgResult(0) {
    const auto cellsArguments = getArguments();
    if ( cellsArguments.empty() ) {
        throw std::runtime_error("Errore avg 5"); // TODO: add error message
    }
    bool argumentsAreAllNotNumeric = true;
    for (auto itr = cellsArguments.cbegin(); argumentsAreAllNotNumeric && itr != cellsArguments.cend(); ++itr) {
        if ( dynamic_cast<SpreadsheetNumericCell*>(*itr) != nullptr ) {
            argumentsAreAllNotNumeric = false;
        }
    }
    if (argumentsAreAllNotNumeric) {
        throw std::runtime_error("Errore avg 6"); // TODO: add error message
    }
    update();
}

SpreadsheetAvgCell::SpreadsheetAvgCell(const std::set<SpreadsheetCell*>& args) : SpreadsheetNumericFunctionCell(args), avgResult(0) {
    const auto cellsArguments = getArguments();
    if ( cellsArguments.empty() ) {
        throw std::runtime_error("Errore avg 3"); // TODO: add error message
    }
    bool argumentsAreAllNotNumeric = true;
    for (auto itr = cellsArguments.cbegin(); argumentsAreAllNotNumeric && itr != cellsArguments.cend(); ++itr) {
        if ( dynamic_cast<SpreadsheetNumericCell*>(*itr) != nullptr ) {
            argumentsAreAllNotNumeric = false;
        }
    }
    if (argumentsAreAllNotNumeric) {
        throw std::runtime_error("Errore avg 4"); // TODO: add error message
    }
    update();
}

SpreadsheetAvgCell::~SpreadsheetAvgCell() {
    isInDestruction.setOn();
}

Spreadsheet::Function SpreadsheetAvgCell::getFunction() const {
    return Spreadsheet::Function::avg;
}

double SpreadsheetAvgCell::getAsNumericValue() const {
    return avgResult;
}

void SpreadsheetAvgCell::removeArgument(SpreadsheetCell* const argumentToRemove) {
    if (!isInDestruction) {
        const auto cellsArguments = getArguments();
        if ( cellsArguments.size() == 1 ) {
            if ( cellsArguments.find( argumentToRemove ) != cellsArguments.cend() ) {
                throw std::runtime_error("Errore avg 1"); // TODO: add error message
            }
        }
        bool remainingArgumentsAreAllNotNumeric = true;
        for (auto itr = cellsArguments.cbegin(); remainingArgumentsAreAllNotNumeric && itr != cellsArguments.cend(); ++itr) {
            if ( (*itr) != argumentToRemove ) {
                if ( dynamic_cast<SpreadsheetNumericCell*>(*itr) != nullptr ) {
                    remainingArgumentsAreAllNotNumeric = false;
                }
            }
        }
        if (remainingArgumentsAreAllNotNumeric) {
            throw std::runtime_error("Errore avg 2"); // TODO: add error message
        }
    }
    SpreadsheetNumericFunctionCell::removeArgument(argumentToRemove);
}

void SpreadsheetAvgCell::update() {
    if (!isInDestruction) {
        const auto oldAvgResult = avgResult;
        const auto cellsArguments = getArguments();
        std::multiset<double> allNumericCellsArgumentsValues;
        for (auto itr = cellsArguments.cbegin(); itr != cellsArguments.cend(); ++itr ) {
            if ( dynamic_cast<SpreadsheetNumericCell*>( *itr ) != nullptr ) {
                allNumericCellsArgumentsValues.emplace( dynamic_cast<SpreadsheetNumericCell*>( *itr )->getAsNumericValue() );
            }
        }
        double newAvgResult = 0.0;
        for (auto itr = allNumericCellsArgumentsValues.cbegin(); itr != allNumericCellsArgumentsValues.cend(); ++itr) {
            newAvgResult = newAvgResult + (*itr);
        }
        newAvgResult = newAvgResult / ( allNumericCellsArgumentsValues.size() );
        avgResult = newAvgResult;
        if (avgResult != oldAvgResult) {
            this->notify();
        }
    }
}
