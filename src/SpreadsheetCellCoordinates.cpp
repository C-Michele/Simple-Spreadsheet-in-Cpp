#include "SpreadsheetCellCoordinates.h"

#include <stdexcept>

SpreadsheetCellCoordinates::SpreadsheetCellCoordinates(const std::string& columnIndex, std::size_t rowIndex) {
    //TODO: implementation
}

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
    return ""; //TODO: implementation
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
