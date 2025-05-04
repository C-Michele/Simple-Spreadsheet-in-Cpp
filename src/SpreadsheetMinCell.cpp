#include "SpreadsheetMinCell.h"

#include <stdexcept>

SpreadsheetMinCell::SpreadsheetMinCell(SpreadsheetCell* const argument) : SpreadsheetNumericFunctionCell(argument), minResult(0) {
    const auto cellsArguments = getArguments();
    if ( cellsArguments.empty() ) {
        throw std::runtime_error(""); // TODO: add error message
    }
    update();
}

SpreadsheetMinCell::SpreadsheetMinCell(const std::set<SpreadsheetCell*>& args) : SpreadsheetNumericFunctionCell(args), minResult(0) {
    const auto cellsArguments = getArguments();
    if ( cellsArguments.empty() ) {
        throw std::runtime_error(""); // TODO: add error message
    }
    update();
}

SpreadsheetMinCell::~SpreadsheetMinCell() {
    isInDestruction.setOn();
}

Spreadsheet::Function SpreadsheetMinCell::getFunction() const {
    return Spreadsheet::Function::min;
}

double SpreadsheetMinCell::getAsNumericValue() const {
    return minResult;
}

void SpreadsheetMinCell::removeArgument(SpreadsheetCell* const argumentToRemove) {
    if (isInDestruction) {
        const auto cellsArguments = getArguments();
        if ( cellsArguments.size() == 1 ) {
            if ( cellsArguments.find( argumentToRemove ) != cellsArguments.cend() ) {
                throw std::runtime_error(""); // TODO: add error message
            }
        }
    }
    SpreadsheetNumericFunctionCell::removeArgument(argumentToRemove);
}

void SpreadsheetMinCell::update() {
    if (!isInDestruction) {
        const auto oldMinResult = minResult;
        const auto cellsArguments = getArguments();
        std::set<double> allNumericCellsArgumentsValues;
        for (auto itr = cellsArguments.cbegin(); itr != cellsArguments.cend(); ++itr ) {
            if ( dynamic_cast<SpreadsheetNumericCell*>( *itr ) != nullptr ) {
                allNumericCellsArgumentsValues.emplace( dynamic_cast<SpreadsheetNumericCell*>( *itr )->getAsNumericValue() );
            }
        }
        minResult =
            allNumericCellsArgumentsValues.empty() ?
            0.0 :
            *allNumericCellsArgumentsValues.cbegin()
        ;
        if (minResult != oldMinResult) {
            this->notify();
        }
    }
}