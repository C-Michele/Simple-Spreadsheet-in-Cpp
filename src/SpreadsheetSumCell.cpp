#include "SpreadsheetSumCell.h"
#include "SpreadsheetNumericFunctionCell.h"

Spreadsheet::SumCell::SumCell() : Spreadsheet::NumericFunctionCell() {}

Spreadsheet::SumCell::SumCell(Spreadsheet::Cell* const argument) : Spreadsheet::NumericFunctionCell(argument) {}

Spreadsheet::SumCell::SumCell(const std::set<Spreadsheet::Cell*>& args) : Spreadsheet::NumericFunctionCell(args) {}

void Spreadsheet::SumCell::update() {
    const auto cellsArguments = getArguments();
    double newSumResult = 0;
    for (auto itr = cellsArguments.cbegin(); itr != cellsArguments.cend(); ++itr ) {
        Spreadsheet::NumericCell* const convertedPointer = dynamic_cast<Spreadsheet::NumericCell*>((*itr));
        if ( convertedPointer != nullptr) {
            newSumResult = newSumResult + convertedPointer->getAsNumericValue();
        }
    }
    sumResult = newSumResult;
}

double Spreadsheet::SumCell::getAsNumericValue() const {
    return sumResult;
}

Spreadsheet::Function Spreadsheet::SumCell::getFunction() const {
    return Spreadsheet::Function::sum;
}