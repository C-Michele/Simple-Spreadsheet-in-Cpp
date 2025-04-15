#include "SpreadsheetCellCoordinates.h"

#include <stdexcept>

SpreadsheetCellCoordinates::SpreadsheetCellCoordinates(const std::string& columnIndex, const std::size_t rowIndex) :
SpreadsheetCellCoordinates(columnIndexConversion(columnIndex), rowIndex) {}

SpreadsheetCellCoordinates::SpreadsheetCellCoordinates(const std::size_t columnIndex, const std::size_t rowIndex) :
columnIndex(columnIndex), rowIndex(rowIndex) {
    if ( columnIndex == 0 || rowIndex == 0 ) {
        throw std::invalid_argument(" "); //TODO: insert error message
    }
}

std::size_t SpreadsheetCellCoordinates::getRowIndex() const {
    return rowIndex;
}

std::size_t SpreadsheetCellCoordinates::getColumnIndexAsInteger() const {
    return columnIndex;
}

std::string SpreadsheetCellCoordinates::getColumnIndexAsString() const {
    return columnIndexConversion(columnIndex);
}

bool SpreadsheetCellCoordinates::operator<(const SpreadsheetCellCoordinates& toCompare) const {
    if ( this->getRowIndex() < toCompare.getRowIndex() ) {
        return true;
    }
    if ( this->getRowIndex() == toCompare.getRowIndex() ) {
        if ( this->getColumnIndexAsInteger() < toCompare.getColumnIndexAsInteger() ) {
            return true;
        }
        return false;
    }
    return false;
}

std::size_t SpreadsheetCellCoordinates::columnIndexConversion(const std::string& stringVersion) {
    return 0; //TODO: implementation
}

std::string SpreadsheetCellCoordinates::columnIndexConversion(const std::size_t integerVersion) {
    return std::string(""); //TODO: implementation
}