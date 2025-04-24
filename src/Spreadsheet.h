#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <memory>
#include <set>
#include <vector>

#include "SpreadsheetCellCoordinates.h"
#include "SpreadsheetCell.h"

class Spreadsheet {
    public:
        enum Function {
            max,
            min,
            avg,
            sum
        };
        Spreadsheet(std::size_t numberOfColumns, std::size_t numberOfRows);
        std::size_t getNumberOfColumns() const;
        std::size_t getNumberOfRows() const;
        bool emptyCellAt(const SpreadsheetCellCoordinates& coordinates) const;
        void deleteCellContentAt(const SpreadsheetCellCoordinates& coordinates);
        template <typename T>
        T getCellValueAt(const SpreadsheetCellCoordinates& coordinates) const;
        void setValueAt(const SpreadsheetCellCoordinates& coordinates, double value);
        void setValueAt(const SpreadsheetCellCoordinates& coordinates, const std::string& value);
        void setFunctionAt(const SpreadsheetCellCoordinates& coordinates, Function function, const std::set<SpreadsheetCellCoordinates>& functionArguments);
    private:
        std::vector< std::vector< std::unique_ptr<SpreadsheetCell> > > cells;
        std::size_t numberOfColumns;
        SpreadsheetCell* getCellAt(const SpreadsheetCellCoordinates& coordinates) const;
        void outOfRangeCheck(const SpreadsheetCellCoordinates& coordinates) const;
        void outOfRangeCheck(const std::set<SpreadsheetCellCoordinates>& coordinatesSet) const;
        static bool isFunctionCell(const SpreadsheetCell* cell);
        bool isFunctionCell(const SpreadsheetCellCoordinates& coordinates) const;
        static bool isNumericCell(const SpreadsheetCell* cell);
        bool isNumericCell(const SpreadsheetCellCoordinates& coordinates) const;
        static bool isOnlyTextualCell(const SpreadsheetCell* cell);
        bool isOnlyTextualCell(const SpreadsheetCellCoordinates& coordinates) const;
        static bool isRawNumericCell(const SpreadsheetCell* cell);
        bool isRawNumericCell(const SpreadsheetCellCoordinates& coordinates) const;
        static bool isRawOnlyTextualCell(const SpreadsheetCell* cell);
        bool isRawOnlyTextualCell(const SpreadsheetCellCoordinates& coordinates) const;
};

/* TODO: implementation
template<typename T>
T Spreadsheet::getCellValueAt(const SpreadsheetCellCoordinates& coordinates) const {
}
*/

#endif //SPREADSHEET_H