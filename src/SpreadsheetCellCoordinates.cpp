#include "SpreadsheetCellCoordinates.h"

#include <stdexcept>
#include <cmath>

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
    if ( integerVersion == 0 ) {
        throw std::invalid_argument(" "); //TODO: insert error message
    }
    const std::size_t numberOfAlphabetLetters = 26;
    std::string toReturn;
    toReturn.insert(
        0,
        1,
        ( integerVersion % numberOfAlphabetLetters == 0 ) ?
        'Z' : static_cast<char>( '@' + ( integerVersion % numberOfAlphabetLetters ) )
    );
    std::size_t exponent = 1;
    while ( static_cast<std::size_t>( static_cast<long double>(integerVersion-1) / std::pow(static_cast<long double>(numberOfAlphabetLetters),exponent) ) != 0 ) {
        toReturn.insert(
            0,
            1,
            static_cast<char>( '@' + static_cast<std::size_t>( static_cast<long double>(integerVersion-1) / std::pow(static_cast<long double>(numberOfAlphabetLetters),exponent) ) )
        );
        ++exponent;
    }
    return toReturn;
}