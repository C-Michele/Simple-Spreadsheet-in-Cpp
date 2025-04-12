#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(std::size_t numberOfColumns, std::size_t numberOfRows) {
    //TODO: implementation
}

std::size_t Spreadsheet::getNumberOfColumns() const {
    return 0; //TODO: implementation
}

std::size_t Spreadsheet::getNumberOfRows() const {
    return 0; //TODO: implementation
}

bool Spreadsheet::emptyCellAt(const SpreadsheetCellCoordinates& coordinates) const {
    return true; //TODO: implementation
}

void Spreadsheet::deleteCellContentAt(const SpreadsheetCellCoordinates& coordinates) {
    //TODO: implementation
}

void Spreadsheet::setValueAt(const SpreadsheetCellCoordinates& coordinates, double value) {
    //TODO: implementation
}

void Spreadsheet::setValueAt(const SpreadsheetCellCoordinates& coordinates, uint64_t) {
    //TODO: implementation
}

void Spreadsheet::setValueAt(const SpreadsheetCellCoordinates& coordinates, int64_t) {
    //TODO: implementation
}

void Spreadsheet::setValueAt(const SpreadsheetCellCoordinates& coordinates, const std::string& value) {
    //TODO: implementation
}

void Spreadsheet::setFunctionAt(
    const SpreadsheetCellCoordinates& coordinates,
    Function function,
    const std::set<SpreadsheetCellCoordinates>& functionArguments ) {
    //TODO: implementation
}
