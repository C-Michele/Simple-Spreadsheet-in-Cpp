#include <stdexcept>

#include "Spreadsheet.h"
#include "SpreadsheetEmptyCell.h"

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
    //TODO: Continue implementation from here
}

void Spreadsheet::setValueAt(const SpreadsheetCellCoordinates& coordinates, double value) {
    outOfRangeCheck(coordinates);
    //TODO: Continue implementation from here
}

void Spreadsheet::setValueAt(const SpreadsheetCellCoordinates& coordinates, const std::string& value) {
    outOfRangeCheck(coordinates);
    //TODO: Continue implementation from here
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
