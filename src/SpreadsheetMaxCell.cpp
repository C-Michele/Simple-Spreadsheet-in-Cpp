#include "SpreadsheetMaxCell.h"

#include <stdexcept>

SpreadsheetMaxCell::SpreadsheetMaxCell(SpreadsheetCell* const argument) : SpreadsheetNumericFunctionCell(argument), maxResult(0) {
    const auto cellsArguments = getArguments();
    if ( cellsArguments.empty() ) {
        throw std::runtime_error(""); // TODO: add error message
    }
    update();
}

SpreadsheetMaxCell::SpreadsheetMaxCell(const std::set<SpreadsheetCell*>& args) : SpreadsheetNumericFunctionCell(args), maxResult(0) {
    const auto cellsArguments = getArguments();
    if ( cellsArguments.empty() ) {
        throw std::runtime_error(""); // TODO: add error message
    }
    update();
}

SpreadsheetMaxCell::~SpreadsheetMaxCell() {
    isInDestruction.setOn();
}

Spreadsheet::Function SpreadsheetMaxCell::getFunction() const {
    return Spreadsheet::Function::max;
}

double SpreadsheetMaxCell::getAsNumericValue() const {
    return maxResult;
}

void SpreadsheetMaxCell::removeArgument(SpreadsheetCell* const argumentToRemove) {
    if (!isInDestruction) {
        const auto cellsArguments = getArguments();
        if ( cellsArguments.size() == 1 ) {
            if ( cellsArguments.find( argumentToRemove ) != cellsArguments.cend() ) {
                throw std::runtime_error(""); // TODO: add error message
            }
        }
    }
    SpreadsheetNumericFunctionCell::removeArgument(argumentToRemove);
}

void SpreadsheetMaxCell::update() {
    if (!isInDestruction) {
        const auto oldMaxResult = maxResult;
        const auto cellsArguments = getArguments();
        std::set<double> allNumericCellsArgumentsValues;
        for (auto itr = cellsArguments.cbegin(); itr != cellsArguments.cend(); ++itr ) {
            if ( dynamic_cast<SpreadsheetNumericCell*>( *itr ) != nullptr ) {
                allNumericCellsArgumentsValues.emplace( dynamic_cast<SpreadsheetNumericCell*>( *itr )->getAsNumericValue() );
            }
        }
        maxResult =
            allNumericCellsArgumentsValues.empty() ?
            0.0 :
            *allNumericCellsArgumentsValues.crbegin()
        ;
        if (maxResult != oldMaxResult) {
            this->notify();
        }
    }
}