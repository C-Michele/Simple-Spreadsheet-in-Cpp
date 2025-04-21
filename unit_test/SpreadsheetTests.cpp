#include "gtest/gtest.h"
#include <cstdint>
#include <exception>
#include <string>

#include "../src/Spreadsheet.h"
#include "../src/SpreadsheetAllCellsDefinitions.h"
/* The last include should not be necessary: TODO:: reorganize the code */

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

TEST(Spreadsheet,all_empty_cells_after_instantiation) {
    const std::size_t numberOfColumnsMax = 20;
    const std::size_t numberOfRowsMax = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            const Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            for (std::size_t k = 1; k <= numberOfColumns; ++k) {
                for (std::size_t l = 1; l <= numberOfRows; ++l) {
                    EXPECT_TRUE(spreadsheet.emptyCellAt(SpreadsheetCellCoordinates(k,l)));
                }
            }
        }
    }
}

TEST(Spreadsheet,not_empty_cell_after_double_value_setting) {
    const std::size_t numberOfColumnsMax = 20;
    const std::size_t numberOfRowsMax = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            for (std::size_t k = 1; k <= numberOfColumns; ++k) {
                for (std::size_t l = 1; l <= numberOfRows; ++l) {
                    spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),1.0);
                    EXPECT_FALSE(spreadsheet.emptyCellAt(SpreadsheetCellCoordinates(k,l)));
                }
            }
        }
    }
}

TEST(Spreadsheet,not_empty_cell_after_string_value_setting) {
    const std::size_t numberOfColumnsMax = 20;
    const std::size_t numberOfRowsMax = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            for (std::size_t k = 1; k <= numberOfColumns; ++k) {
                for (std::size_t l = 1; l <= numberOfRows; ++l) {
                    spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),std::string("string"));
                    EXPECT_FALSE(spreadsheet.emptyCellAt(SpreadsheetCellCoordinates(k,l)));
                }
            }
        }
    }
}

TEST(Spreadsheet,empty_cell_after_double_value_deletion) {
    const std::size_t numberOfColumnsMax = 20;
    const std::size_t numberOfRowsMax = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            for (std::size_t k = 1; k <= numberOfColumns; ++k) {
                for (std::size_t l = 1; l <= numberOfRows; ++l) {
                    spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),1.0);
                    spreadsheet.deleteCellContentAt(SpreadsheetCellCoordinates(k,l));
                    EXPECT_TRUE(spreadsheet.emptyCellAt(SpreadsheetCellCoordinates(k,l)));
                }
            }
        }
    }
}

TEST(Spreadsheet,empty_cell_after_string_value_deletion) {
    const std::size_t numberOfColumnsMax = 20;
    const std::size_t numberOfRowsMax = 20;

    for (std::size_t i = 0; i <= numberOfColumnsMax; ++i) {
        const auto numberOfColumns = i;
        for (std::size_t j = 0; j <= numberOfRowsMax; ++j) {
            const auto numberOfRows = j;
            Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
            for (std::size_t k = 1; k <= numberOfColumns; ++k) {
                for (std::size_t l = 1; l <= numberOfRows; ++l) {
                    spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),"string");
                    spreadsheet.deleteCellContentAt(SpreadsheetCellCoordinates(k,l));
                    EXPECT_TRUE(spreadsheet.emptyCellAt(SpreadsheetCellCoordinates(k,l)));
                }
            }
        }
    }
}

TEST(Spreadsheet,setFunctionAt__sum__invalid_argument_exception_after_circular_reference) {
    Spreadsheet spreadsheet(4,4);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    bool exceptionThrown = false;
    try {
        spreadsheet.setFunctionAt(
            SpreadsheetCellCoordinates(2,1),
            Spreadsheet::Function::sum,
            {
                SpreadsheetCellCoordinates(1,1),
                SpreadsheetCellCoordinates(2,1), //These coordinates are the problem
                SpreadsheetCellCoordinates(3,1)
            });
    }
    catch (const std::invalid_argument& e) {
        bool exceptionThrown = true;
    }

    EXPECT_TRUE(exceptionThrown);
}

TEST(Spreadsheet,setFunctionAt__avg__invalid_argument_exception_after_circular_reference) {
    Spreadsheet spreadsheet(4,4);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    bool exceptionThrown = false;
    try {
        spreadsheet.setFunctionAt(
            SpreadsheetCellCoordinates(2,1),
            Spreadsheet::Function::avg,
            {
                SpreadsheetCellCoordinates(1,1),
                SpreadsheetCellCoordinates(2,1), //These coordinates are the problem
                SpreadsheetCellCoordinates(3,1)
            });
    }
    catch (const std::invalid_argument& e) {
        bool exceptionThrown = true;
    }

    EXPECT_TRUE(exceptionThrown);
}

TEST(Spreadsheet,setFunctionAt__min__invalid_argument_exception_after_circular_reference) {
    Spreadsheet spreadsheet(4,4);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    bool exceptionThrown = false;
    try {
        spreadsheet.setFunctionAt(
            SpreadsheetCellCoordinates(2,1),
            Spreadsheet::Function::min,
            {
                SpreadsheetCellCoordinates(1,1),
                SpreadsheetCellCoordinates(2,1), //These coordinates are the problem
                SpreadsheetCellCoordinates(3,1)
            });
    }
    catch (const std::invalid_argument& e) {
        bool exceptionThrown = true;
    }

    EXPECT_TRUE(exceptionThrown);
}

TEST(Spreadsheet,setFunctionAt__max__invalid_argument_exception_after_circular_reference) {
    Spreadsheet spreadsheet(4,4);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    bool exceptionThrown = false;
    try {
        spreadsheet.setFunctionAt(
            SpreadsheetCellCoordinates(2,1),
            Spreadsheet::Function::max,
            {
                SpreadsheetCellCoordinates(1,1),
                SpreadsheetCellCoordinates(2,1), //These coordinates are the problem
                SpreadsheetCellCoordinates(3,1)
            });
    }
    catch (const std::invalid_argument& e) {
        bool exceptionThrown = true;
    }

    EXPECT_TRUE(exceptionThrown);
}

TEST(Spreadsheet,setFunctionAt__sum__out_of_range_exception__function_cell) {
    const std::size_t numberOfColumns = 4;
    const std::size_t numberOfRows = 4;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            bool exceptionThrown = false;
            try {
                spreadsheet.setFunctionAt(
                    SpreadsheetCellCoordinates(k,l),
                    Spreadsheet::Function::sum,
                    {});
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

TEST(Spreadsheet,setFunctionAt__avg__out_of_range_exception__function_cell) {
    const std::size_t numberOfColumns = 4;
    const std::size_t numberOfRows = 4;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            bool exceptionThrown = false;
            try {
                spreadsheet.setFunctionAt(
                    SpreadsheetCellCoordinates(k,l),
                    Spreadsheet::Function::avg,
                    {});
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

TEST(Spreadsheet,setFunctionAt__min__out_of_range_exception__function_cell) {
    const std::size_t numberOfColumns = 4;
    const std::size_t numberOfRows = 4;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            bool exceptionThrown = false;
            try {
                spreadsheet.setFunctionAt(
                    SpreadsheetCellCoordinates(k,l),
                    Spreadsheet::Function::min,
                    {});
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

TEST(Spreadsheet,setFunctionAt__max__out_of_range_exception__function_cell) {
    const std::size_t numberOfColumns = 4;
    const std::size_t numberOfRows = 4;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            bool exceptionThrown = false;
            try {
                spreadsheet.setFunctionAt(
                    SpreadsheetCellCoordinates(k,l),
                    Spreadsheet::Function::max,
                    {});
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

TEST(Spreadsheet,setFunctionAt__sum__out_of_range_exception__function_arguments) {
    const std::size_t numberOfColumns = 4;
    const std::size_t numberOfRows = 4;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            bool exceptionThrown = false;
            try {
                spreadsheet.setFunctionAt(
                    SpreadsheetCellCoordinates(1,1),
                    Spreadsheet::Function::sum,
                    {SpreadsheetCellCoordinates(k,l)});
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

TEST(Spreadsheet,setFunctionAt__avg__out_of_range_exception__function_arguments) {
    const std::size_t numberOfColumns = 4;
    const std::size_t numberOfRows = 4;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            bool exceptionThrown = false;
            try {
                spreadsheet.setFunctionAt(
                    SpreadsheetCellCoordinates(1,1),
                    Spreadsheet::Function::avg,
                    {SpreadsheetCellCoordinates(k,l)});
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

TEST(Spreadsheet,setFunctionAt__min__out_of_range_exception__function_arguments) {
    const std::size_t numberOfColumns = 4;
    const std::size_t numberOfRows = 4;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            bool exceptionThrown = false;
            try {
                spreadsheet.setFunctionAt(
                    SpreadsheetCellCoordinates(1,1),
                    Spreadsheet::Function::min,
                    {SpreadsheetCellCoordinates(k,l)});
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

TEST(Spreadsheet,setFunctionAt__max__out_of_range_exception__function_arguments) {
    const std::size_t numberOfColumns = 4;
    const std::size_t numberOfRows = 4;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            bool exceptionThrown = false;
            try {
                spreadsheet.setFunctionAt(
                    SpreadsheetCellCoordinates(1,1),
                    Spreadsheet::Function::max,
                    {SpreadsheetCellCoordinates(k,l)});
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