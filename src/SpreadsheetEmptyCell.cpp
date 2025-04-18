#include "SpreadsheetEmptyCell.h"

std::string Spreadsheet::EmptyCell::getAsText() const {
    return "";
}

bool Spreadsheet::EmptyCell::isEmpty() const {
    return true;
}