#include "SpreadsheetCell.h"
#include "SpreadsheetNumericCell.h"
#include "SpreadsheetNumericFunctionCell.h"
#include "SpreadsheetSumCell.h"

SpreadsheetSumCell::SpreadsheetSumCell() : sumResult(0) {}

SpreadsheetSumCell::SpreadsheetSumCell(SpreadsheetCell* const argument) : SpreadsheetNumericFunctionCell(argument), sumResult(0) {
    update();
}

SpreadsheetSumCell::SpreadsheetSumCell(const std::set<SpreadsheetCell*>& args) : SpreadsheetNumericFunctionCell(args), sumResult(0) {
    update();
}

Spreadsheet::Function SpreadsheetSumCell::getFunction() const {
    return Spreadsheet::Function::sum;
}

double SpreadsheetSumCell::getAsNumericValue() const {
    return sumResult;
}

void SpreadsheetSumCell::update() {
    const auto oldSumResult = sumResult;
    const auto cellsArguments = getArguments();
    std::multiset<double> allNumericCellsArgumentsValues;
    for (auto itr = cellsArguments.cbegin(); itr != cellsArguments.cend(); ++itr ) {
        if ( dynamic_cast<SpreadsheetNumericCell*>( *itr ) != nullptr ) {
            allNumericCellsArgumentsValues.emplace( dynamic_cast<SpreadsheetNumericCell*>( *itr )->getAsNumericValue() );
        }
    }
    double newSumResult = 0.0;
    for (auto itr = allNumericCellsArgumentsValues.cbegin(); itr != allNumericCellsArgumentsValues.cend(); ++itr) {
        newSumResult = newSumResult + (*itr);
    }
    sumResult = newSumResult;
    if (sumResult != oldSumResult) {
        this->notify();
    }
}
