#ifndef SPREADSHEETCONTROLLER_H
#define SPREADSHEETCONTROLLER_H

#include "Spreadsheet.h"
#include "SpreadsheetCellCoordinates.h"
#include <utility>

class SpreadsheetController {
    public:
        SpreadsheetController(Spreadsheet* spreadsheet);

        void deleteCellContentAt(const std::string& cellCoordinatesAsString) const;
        void deleteCellContentAt(const SpreadsheetCellCoordinates& coordinates) const;
        void setCellAt(const std::string& cellCoordinatesAsString, const std::string& string) const;
        void setCellAt(const SpreadsheetCellCoordinates& coordinates, const std::string& string) const;
        void setSumCellAt(const std::string& cellCoordinatesAsString, const std::set<std::string>& argumentsCoordinatesAsString) const;
        void setSumCellAt(const SpreadsheetCellCoordinates& coordinates, const std::set<SpreadsheetCellCoordinates>& argumentsCoordinates) const;
    private:
        Spreadsheet* spreadsheet;

        static std::pair<bool,double> parseAsDouble(const std::string& string);
        static std::pair<bool,SpreadsheetCellCoordinates> parseAsCellCoordinates(const std::string& string);
};

#endif //SPREADSHEETCONTROLLER_H