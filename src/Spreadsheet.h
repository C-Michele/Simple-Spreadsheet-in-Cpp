#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <cstddef>

class Spreadsheet {
    public:
        Spreadsheet(std::size_t numberOfColumns, std::size_t numberOfRows);
        std::size_t getNumberOfColumns() const;
        std::size_t getNumberOfRows() const;
};

#endif //SPREADSHEET_H