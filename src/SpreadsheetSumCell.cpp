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
    const auto cellsArguments = getArguments();
    double newSumResult = 0;
    for (auto itr = cellsArguments.cbegin(); itr != cellsArguments.cend(); ++itr ) {
        SpreadsheetNumericCell* const convertedPointer = dynamic_cast<SpreadsheetNumericCell*>((*itr));
        if ( convertedPointer != nullptr) {
            newSumResult = newSumResult + convertedPointer->getAsNumericValue();
        }
    }
    sumResult = newSumResult;
}
