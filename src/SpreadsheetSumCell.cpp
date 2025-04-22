#include "SpreadsheetCell.h"
#include "SpreadsheetNumericCell.h"
#include "SpreadsheetNumericFunctionCell.h"
#include "SpreadsheetSumCell.h"

SpreadsheetSumCell::SpreadsheetSumCell(SpreadsheetCell* const argument) : SpreadsheetNumericFunctionCell(argument) {}

SpreadsheetSumCell::SpreadsheetSumCell(const std::set<SpreadsheetCell*>& args) : SpreadsheetNumericFunctionCell(args) {}

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
