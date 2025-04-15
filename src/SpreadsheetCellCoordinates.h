#ifndef SPREADSHEETCELLCOORDINATES_H
#define SPREADSHEETCELLCOORDINATES_H

#include <string>

class SpreadsheetCellCoordinates {
    public:
        SpreadsheetCellCoordinates(const std::string& columnIndex, std::size_t rowIndex);
        SpreadsheetCellCoordinates(std::size_t columnIndex, std::size_t rowIndex);

        std::size_t getRowIndex() const;
        std::size_t getColumnIndexAsInteger() const;
        std::string getColumnIndexAsString() const;

        bool operator<(const SpreadsheetCellCoordinates& toCompare) const;
    private:
        static inline std::size_t columnIndexConversion(const std::string& stringVersion);
        static inline std::string columnIndexConversion(std::size_t integerVersion);

        std::size_t columnIndex;
        std::size_t rowIndex;
};

#endif //SPREADSHEETCELLCOORDINATES_H
