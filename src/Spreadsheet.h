#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <cstddef>
#include <set>

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
};

/* TODO: implementation
template<typename T>
T Spreadsheet::getCellValueAt(const SpreadsheetCellCoordinates& coordinates) const {
}
*/

#endif //SPREADSHEET_H