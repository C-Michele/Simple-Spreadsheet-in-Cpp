#include "SpreadsheetRawTextualCell.h"

#include <stdexcept>

Spreadsheet::RawTextualCell::RawTextualCell(const std::string& text) : cellText(text) {
    if ( text.empty() ) {
        throw std::invalid_argument(" "); //TODO: add error message
    }
}

std::string Spreadsheet::RawTextualCell::getAsText() const {
    return cellText;
}

void Spreadsheet::RawTextualCell::setText(const std::string& text) {
    if ( text.empty() ) {
        throw std::invalid_argument(" "); //TODO: add error message
    }
    cellText = text;
    this->notify();
}
