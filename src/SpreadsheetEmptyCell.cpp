#include "SpreadsheetEmptyCell.h"

bool SpreadsheetEmptyCell::isEmpty() const {
    return true;
}

std::string SpreadsheetEmptyCell::getAsText() const {
    return "";
}
