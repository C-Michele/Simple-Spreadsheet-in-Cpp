#include "gtest/gtest.h"
#include <cstdint>

#include "../src/Spreadsheet.h"

TEST(Spreadsheet, getNumberOfColumns) {
    const std::size_t numberOfColumnsMax = 20;
    const std::size_t numberOfRowsMax = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            const Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            EXPECT_EQ(spreadsheet.getNumberOfColumns(),numberOfColumns);
        }
    }
}

TEST(Spreadsheet, getNumberOfRows) {
    const std::size_t numberOfColumnsMax = 20;
    const std::size_t numberOfRowsMax = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            const Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            EXPECT_EQ(spreadsheet.getNumberOfRows(),numberOfRows);
        }
    }
}