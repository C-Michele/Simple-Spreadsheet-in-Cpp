#include <stdexcept>

#include "SpreadsheetRawTextualCell.h"

SpreadsheetRawTextualCell::SpreadsheetRawTextualCell(const std::string& text) : cellText(text) {
    if ( text.empty() ) {
        throw std::invalid_argument(" "); //TODO: add error message
    }
}

std::string SpreadsheetRawTextualCell::getAsText() const {
    return cellText;
}

void SpreadsheetRawTextualCell::setText(const std::string& text) {
    if ( text.empty() ) {
        throw std::invalid_argument(" "); //TODO: add error message
    }
    cellText = text;
}
