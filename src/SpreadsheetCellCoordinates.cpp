#include "SpreadsheetCellCoordinates.h"

SpreadsheetCellCoordinates::SpreadsheetCellCoordinates(const std::string& columnIndex, std::size_t rowIndex) {
    //TODO: implementation
}

SpreadsheetCellCoordinates::SpreadsheetCellCoordinates(std::size_t columnIndex, std::size_t rowIndex) {
    //TODO: implementation
}

std::size_t SpreadsheetCellCoordinates::getRowIndex() const {
    return 0; //TODO: implementation
}

std::size_t SpreadsheetCellCoordinates::getColumnIndexAsInteger() const {
    return 0; //TODO: implementation
}

std::string SpreadsheetCellCoordinates::getColumnIndexAsString() const {
    return ""; //TODO: implementation
}

bool SpreadsheetCellCoordinates::operator<(const SpreadsheetCellCoordinates& toCompare) const {
    return true; //TODO: implementation
}
