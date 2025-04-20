#include "SpreadsheetRawNumericCell.h"

Spreadsheet::RawNumericCell::RawNumericCell(double value) : cellValue(value) {}

double Spreadsheet::RawNumericCell::getAsNumericValue() const {
    return cellValue;
}

void Spreadsheet::RawNumericCell::setNumericValue(double value) {
    cellValue = value;
    this->notify();
}
