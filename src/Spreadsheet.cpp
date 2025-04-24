#include <stdexcept>

#include "Spreadsheet.h"
#include "SpreadsheetEmptyCell.h"
#include "SpreadsheetFunctionCell.h"
#include "SpreadsheetNumericCell.h"
#include "SpreadsheetRawNumericCell.h"
#include "SpreadsheetRawTextualCell.h"

Spreadsheet::Spreadsheet(std::size_t const numberOfColumns, std::size_t const numberOfRows) : numberOfColumns(numberOfColumns) {
    if ( numberOfRows != 0 ) {
        cells.reserve(numberOfRows);
        while ( cells.size() != numberOfRows ) {
            cells.emplace_back();
            if (numberOfColumns != 0) {
                auto& rowToPopulate = cells.back();
                try {
                    rowToPopulate.reserve(numberOfColumns);
                } catch (...) {
                    cells.clear();
                    this->numberOfColumns = 0;
                    throw;
                }
                while ( rowToPopulate.size() != numberOfColumns ) {
                    rowToPopulate.emplace_back( new SpreadsheetEmptyCell() );
                }
            }
        }
    }
}

std::size_t Spreadsheet::getNumberOfColumns() const {
    return numberOfColumns;
}

std::size_t Spreadsheet::getNumberOfRows() const {
    return cells.size();
}

bool Spreadsheet::emptyCellAt(const SpreadsheetCellCoordinates& coordinates) const {
    return getCellAt(coordinates)->isEmpty();
}

void Spreadsheet::deleteCellContentAt(const SpreadsheetCellCoordinates& coordinates) {
    outOfRangeCheck(coordinates);
    if ( ! emptyCellAt(coordinates) ) {
        auto& rowContainingTheCellToDelete = cells[coordinates.getRowIndex()-1];
        auto itrPointingTheCellToDelete = rowContainingTheCellToDelete.begin();
        for (std::size_t j = 1; j != coordinates.getColumnIndexAsInteger(); ++j) {
            ++itrPointingTheCellToDelete;
        }
        rowContainingTheCellToDelete.emplace( rowContainingTheCellToDelete.erase(itrPointingTheCellToDelete) , new SpreadsheetEmptyCell() );
        //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
    }
}

void Spreadsheet::setValueAt(const SpreadsheetCellCoordinates& coordinates, double const value) {
    outOfRangeCheck(coordinates);
    if ( isRawNumericCell(coordinates) ) {
        const auto oldNumericValue = dynamic_cast<SpreadsheetRawNumericCell*>(getCellAt(coordinates))->getAsNumericValue();
        if (value != oldNumericValue) {
            dynamic_cast<SpreadsheetRawNumericCell*>(getCellAt(coordinates))->setNumericValue( value );
            //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
        }
    }
    else {
        auto& rowContainingTheCellToDelete = cells[coordinates.getRowIndex()-1];
        auto itrPointingTheCellToDelete = rowContainingTheCellToDelete.begin();
        for (std::size_t j = 1; j != coordinates.getColumnIndexAsInteger(); ++j) {
            ++itrPointingTheCellToDelete;
        }
        if ( isNumericCell(coordinates) ) {
            const auto oldNumericValue = dynamic_cast<SpreadsheetNumericCell*>(getCellAt(coordinates))->getAsNumericValue();
            rowContainingTheCellToDelete.emplace( rowContainingTheCellToDelete.erase(itrPointingTheCellToDelete) , new SpreadsheetRawNumericCell(value) );
            if ( value != oldNumericValue ) {
                //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
            }
        }
        else {
            rowContainingTheCellToDelete.emplace( rowContainingTheCellToDelete.erase(itrPointingTheCellToDelete) , new SpreadsheetRawNumericCell(value) );
            //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
        }
    }
}

void Spreadsheet::setValueAt(const SpreadsheetCellCoordinates& coordinates, const std::string& value) {
    outOfRangeCheck(coordinates);
    const auto oldTextualValue = getCellAt(coordinates)->getAsText();
    if ( isRawOnlyTextualCell(coordinates) ) {
        if ( value != oldTextualValue ) {
            dynamic_cast<SpreadsheetRawTextualCell*>(getCellAt(coordinates))->setText( value );
            //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
        }
    }
    else {
        auto& rowContainingTheCellToDelete = cells[coordinates.getRowIndex()-1];
        auto itrPointingTheCellToDelete = rowContainingTheCellToDelete.begin();
        for (std::size_t j = 1; j != coordinates.getColumnIndexAsInteger(); ++j) {
            ++itrPointingTheCellToDelete;
        }
        rowContainingTheCellToDelete.emplace( rowContainingTheCellToDelete.erase(itrPointingTheCellToDelete) , new SpreadsheetRawTextualCell(value) );
        //TODO: Once this class will be a derivative of the "Subject" class, insert the "this->notify()" call here
    }
}

void Spreadsheet::setFunctionAt(
    const SpreadsheetCellCoordinates& coordinates,
    Function function,
    const std::set<SpreadsheetCellCoordinates>& functionArguments ) {
    outOfRangeCheck(coordinates);
    outOfRangeCheck(functionArguments);
    //TODO: Continue implementation from here
}

SpreadsheetCell* Spreadsheet::getCellAt(const SpreadsheetCellCoordinates& coordinates) const {
    outOfRangeCheck(coordinates);
    return ( ( cells[coordinates.getRowIndex()-1] )[coordinates.getColumnIndexAsInteger()-1] ).get();
}

void Spreadsheet::outOfRangeCheck(const SpreadsheetCellCoordinates& coordinates) const {
    if ( coordinates.getRowIndex() > getNumberOfRows() || coordinates.getColumnIndexAsInteger() > getNumberOfColumns() ) {
        throw std::out_of_range(" "); //TODO: insert an error message
    }
}

void Spreadsheet::outOfRangeCheck(const std::set<SpreadsheetCellCoordinates>& coordinatesSet) const {
    for (auto itr = coordinatesSet.cbegin(); itr != coordinatesSet.cend(); ++itr) {
        outOfRangeCheck(*itr);
    }
}

bool Spreadsheet::isFunctionCell(const SpreadsheetCell* const cell) {
    return dynamic_cast<const SpreadsheetFunctionCell*>(cell) != nullptr;
}

bool Spreadsheet::isFunctionCell(const SpreadsheetCellCoordinates& coordinates) const {
    return isFunctionCell(getCellAt(coordinates));
}

bool Spreadsheet::isNumericCell(const SpreadsheetCell* const cell) {
    return dynamic_cast<const SpreadsheetNumericCell*>(cell) != nullptr;
}

bool Spreadsheet::isNumericCell(const SpreadsheetCellCoordinates& coordinates) const {
    return isNumericCell(getCellAt(coordinates));
}

bool Spreadsheet::isOnlyTextualCell(const SpreadsheetCell* const cell) {
    return !isNumericCell(cell);
}

bool Spreadsheet::isOnlyTextualCell(const SpreadsheetCellCoordinates& coordinates) const {
    return isOnlyTextualCell(getCellAt(coordinates));
}

bool Spreadsheet::isRawNumericCell(const SpreadsheetCell* const cell) {
    return dynamic_cast<const SpreadsheetRawNumericCell*>(cell) != nullptr;
}

bool Spreadsheet::isRawNumericCell(const SpreadsheetCellCoordinates& coordinates) const {
    return isRawNumericCell(getCellAt(coordinates));
}

bool Spreadsheet::isRawOnlyTextualCell(const SpreadsheetCell* const cell) {
    return dynamic_cast<const SpreadsheetRawTextualCell*>(cell) != nullptr;
}

bool Spreadsheet::isRawOnlyTextualCell(const SpreadsheetCellCoordinates& coordinates) const {
    return isRawOnlyTextualCell(getCellAt(coordinates));
}
