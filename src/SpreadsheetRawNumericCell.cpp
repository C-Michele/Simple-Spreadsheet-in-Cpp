//
// Created by michele on 22/04/25.
//

#include "SpreadsheetRawNumericCell.h"

SpreadsheetRawNumericCell::SpreadsheetRawNumericCell(double const value) : cellValue(value) {}

double SpreadsheetRawNumericCell::getAsNumericValue() const {
    return cellValue;
}

void SpreadsheetRawNumericCell::setNumericValue(double const value) {
    double oldCellValue = cellValue;
    cellValue = value;
    if (cellValue != oldCellValue) {
        this->notify();
    }
}
