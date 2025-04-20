#include "SpreadsheetNumericCell.h"

std::string Spreadsheet::NumericCell::getAsText() const {
    return std::to_string(getAsNumericValue());
}
