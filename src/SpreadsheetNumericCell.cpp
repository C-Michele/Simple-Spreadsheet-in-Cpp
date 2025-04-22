#include "SpreadsheetNumericCell.h"

std::string SpreadsheetNumericCell::getAsText() const {
    return std::to_string(getAsNumericValue());
}
