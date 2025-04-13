#include "gtest/gtest.h"
#include <cstdint>
#include <exception>
#include <string>

#include "../src/Spreadsheet.h"

TEST(Spreadsheet,getNumberOfColumns) {
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

TEST(Spreadsheet,getNumberOfRows) {
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

TEST(Spreadsheet,emptyCellAt_out_of_range_exception) {
    const std::size_t numberOfColumnsMax = 5;
    const std::size_t numberOfRowsMax = 5;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            const Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
                for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
                    bool exceptionThrown = false;
                    try {
                        spreadsheet.emptyCellAt(SpreadsheetCellCoordinates(k,l));
                    }
                    catch (const std::out_of_range& e) {
                        exceptionThrown = true;
                    }
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_FALSE(exceptionThrown);
                    }
                    else {
                        EXPECT_TRUE(exceptionThrown);
                    }
                }
            }
        }
    }
}

TEST(Spreadsheet,deleteCellContentAt_out_of_range_exception) {
    const std::size_t numberOfColumnsMax = 5;
    const std::size_t numberOfRowsMax = 5;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
                for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
                    bool exceptionThrown = false;
                    try {
                        spreadsheet.deleteCellContentAt(SpreadsheetCellCoordinates(k,l));
                    }
                    catch (const std::out_of_range& e) {
                        exceptionThrown = true;
                    }
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_FALSE(exceptionThrown);
                    }
                    else {
                        EXPECT_TRUE(exceptionThrown);
                    }
                }
            }
        }
    }
}

/* TODO: Remove the comment after method implementation
TEST(Spreadsheet,getCellValueAt__string__out_of_range_exception) {
    const std::size_t numberOfColumnsMax = 5;
    const std::size_t numberOfRowsMax = 5;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            const Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
                for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
                    bool exceptionThrown = false;
                    try {
                        spreadsheet.getCellValueAt<std::string>(SpreadsheetCellCoordinates(k,l));
                    }
                    catch (const std::out_of_range& e) {
                        exceptionThrown = true;
                    }
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_FALSE(exceptionThrown);
                    }
                    else {
                        EXPECT_TRUE(exceptionThrown);
                    }
                }
            }
        }
    }
}
*/

TEST(Spreadsheet,setValueAt__double__out_of_range_exception) {
    const std::size_t numberOfColumnsMax = 5;
    const std::size_t numberOfRowsMax = 5;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
                for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
                    bool exceptionThrown = false;
                    try {
                        spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),0.5);
                    }
                    catch (const std::out_of_range& e) {
                        exceptionThrown = true;
                    }
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_FALSE(exceptionThrown);
                    }
                    else {
                        EXPECT_TRUE(exceptionThrown);
                    }
                }
            }
        }
    }
}

TEST(Spreadsheet,setValueAt__string__out_of_range_exception) {
    const std::size_t numberOfColumnsMax = 5;
    const std::size_t numberOfRowsMax = 5;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
                for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
                    bool exceptionThrown = false;
                    try {
                        spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),std::string("string"));
                    }
                    catch (const std::out_of_range& e) {
                        exceptionThrown = true;
                    }
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_FALSE(exceptionThrown);
                    }
                    else {
                        EXPECT_TRUE(exceptionThrown);
                    }
                }
            }
        }
    }
}