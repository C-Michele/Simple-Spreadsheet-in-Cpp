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
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_NO_THROW(spreadsheet.emptyCellAt(SpreadsheetCellCoordinates(k,l)));
                    }
                    else {
                        EXPECT_THROW(spreadsheet.emptyCellAt(SpreadsheetCellCoordinates(k,l)),std::out_of_range);
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
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_NO_THROW(spreadsheet.deleteCellContentAt(SpreadsheetCellCoordinates(k,l)));
                    }
                    else {
                        EXPECT_THROW(spreadsheet.deleteCellContentAt(SpreadsheetCellCoordinates(k,l)),std::out_of_range);
                    }
                }
            }
        }
    }
}

TEST(Spreadsheet,getCellAsTextAt_out_of_range_exception) {
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
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_NO_THROW(spreadsheet.getCellAsTextAt(SpreadsheetCellCoordinates(k,l)));
                    }
                    else {
                        EXPECT_THROW(spreadsheet.getCellAsTextAt(SpreadsheetCellCoordinates(k,l)),std::out_of_range);
                    }
                }
            }
        }
    }
}

TEST(Spreadsheet,getCellAsNumericValueAt_out_of_range_exception) {
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
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_NO_THROW(
                            spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),123.456);
                            spreadsheet.getCellAsNumericValueAt(SpreadsheetCellCoordinates(k,l));
                        );
                    }
                    else {
                        EXPECT_THROW(
                            spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),123.456);
                            spreadsheet.getCellAsNumericValueAt(SpreadsheetCellCoordinates(k,l));
                            ,
                            std::out_of_range
                        );
                    }
                }
            }
        }
    }
}

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
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_NO_THROW(spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),0.5));
                    }
                    else {
                        EXPECT_THROW(spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),0.5),std::out_of_range);
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
                    if ( k <= numberOfColumns && l <= numberOfRows) {
                        EXPECT_NO_THROW(spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),std::string("string")));
                    }
                    else {
                        EXPECT_THROW(spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),std::string("string")),std::out_of_range);
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

    EXPECT_THROW(
        spreadsheet.setFunctionAt(
            SpreadsheetCellCoordinates(2,1),
            Spreadsheet::Function::sum,
            {
                SpreadsheetCellCoordinates(1,1),
                SpreadsheetCellCoordinates(2,1), //These coordinates are the problem
                SpreadsheetCellCoordinates(3,1)
            });
        ,
        std::invalid_argument
    );
}

TEST(Spreadsheet,setFunctionAt__avg__invalid_argument_exception_after_circular_reference) {
    Spreadsheet spreadsheet(4,4);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    EXPECT_THROW(
        spreadsheet.setFunctionAt(
            SpreadsheetCellCoordinates(2,1),
            Spreadsheet::Function::avg,
            {
                SpreadsheetCellCoordinates(1,1),
                SpreadsheetCellCoordinates(2,1), //These coordinates are the problem
                SpreadsheetCellCoordinates(3,1)
            });
            ,
            std::invalid_argument
    );
}

TEST(Spreadsheet,setFunctionAt__min__invalid_argument_exception_after_circular_reference) {
    Spreadsheet spreadsheet(4,4);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    EXPECT_THROW(
        spreadsheet.setFunctionAt(
            SpreadsheetCellCoordinates(2,1),
            Spreadsheet::Function::min,
            {
                SpreadsheetCellCoordinates(1,1),
                SpreadsheetCellCoordinates(2,1), //These coordinates are the problem
                SpreadsheetCellCoordinates(3,1)
            });
        ,
        std::invalid_argument
    );
}

TEST(Spreadsheet,setFunctionAt__max__invalid_argument_exception_after_circular_reference) {
    Spreadsheet spreadsheet(4,4);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    EXPECT_THROW(
        spreadsheet.setFunctionAt(
            SpreadsheetCellCoordinates(2,1),
            Spreadsheet::Function::max,
            {
                SpreadsheetCellCoordinates(1,1),
                SpreadsheetCellCoordinates(2,1), //These coordinates are the problem
                SpreadsheetCellCoordinates(3,1)
            });
            ,
            std::invalid_argument
    );
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
            if ( k <= numberOfColumns && l <= numberOfRows) {
                EXPECT_NO_THROW(
                    spreadsheet.setFunctionAt(
                        SpreadsheetCellCoordinates(k,l),
                        Spreadsheet::Function::sum,
                        {});
                );
            }
            else {
                EXPECT_THROW(
                    spreadsheet.setFunctionAt(
                        SpreadsheetCellCoordinates(k,l),
                        Spreadsheet::Function::sum,
                        {});
                    ,
                    std::out_of_range
                );
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
            if ( ! ( ( k==1 && l==1 ) || ( k==3 && l==1 ) ) ) {
                if ( k <= numberOfColumns && l <= numberOfRows) {
                    EXPECT_NO_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(k,l),
                            Spreadsheet::Function::avg,
                            {
                                SpreadsheetCellCoordinates(1,1),
                                SpreadsheetCellCoordinates(3,1)
                            });
                    );
                }
                else {
                    EXPECT_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(k,l),
                            Spreadsheet::Function::avg,
                            {
                                SpreadsheetCellCoordinates(1,1),
                                SpreadsheetCellCoordinates(3,1)
                            });
                        ,
                        std::out_of_range
                    );
                }
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
            if ( ! ( ( k==1 && l==1 ) || ( k==3 && l==1 ) ) ) {
                if ( k <= numberOfColumns && l <= numberOfRows) {
                    EXPECT_NO_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(k,l),
                            Spreadsheet::Function::min,
                            {
                                SpreadsheetCellCoordinates(1,1),
                                SpreadsheetCellCoordinates(3,1)
                            });
                    );
                }
                else {
                    EXPECT_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(k,l),
                            Spreadsheet::Function::min,
                            {
                                SpreadsheetCellCoordinates(1,1),
                                SpreadsheetCellCoordinates(3,1)
                            });
                            ,
                            std::out_of_range
                    );
                }
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
            if ( ! ( ( k==1 && l==1 ) || ( k==3 && l==1 ) ) ) {
                if ( k <= numberOfColumns && l <= numberOfRows) {
                    EXPECT_NO_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(k,l),
                            Spreadsheet::Function::max,
                            {
                                SpreadsheetCellCoordinates(1,1),
                                SpreadsheetCellCoordinates(3,1)
                            });
                    );
                }
                else {
                    EXPECT_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(k,l),
                            Spreadsheet::Function::max,
                            {
                                SpreadsheetCellCoordinates(1,1),
                                SpreadsheetCellCoordinates(3,1)
                            });
                        ,
                        std::out_of_range
                    );
                }
            }
        }
    }
}

TEST(Spreadsheet,setFunctionAt__sum__out_of_range_exception__function_arguments) {
    const std::size_t numberOfColumns = 8;
    const std::size_t numberOfRows = 8;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            if ( ! ( k==1 && l==1 ) ) {
                if ( k <= numberOfColumns && l <= numberOfRows) {
                    EXPECT_NO_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(1,1),
                            Spreadsheet::Function::sum,
                            {SpreadsheetCellCoordinates(k,l)});
                            );
                }
                else {
                    EXPECT_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(1,1),
                            Spreadsheet::Function::sum,
                            {SpreadsheetCellCoordinates(k,l)});
                        ,
                        std::out_of_range
                    );
                }
            }
        }
    }
}

TEST(Spreadsheet,setFunctionAt__avg__out_of_range_exception__function_arguments) {
    const std::size_t numberOfColumns = 3;
    const std::size_t numberOfRows = 3;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(2,1),2.1);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),3.1);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,2),1.2);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(2,2),2.2);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,2),3.2);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,3),1.3);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(2,3),2.3);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,3),3.3);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            if ( ! ( k==1 && l==1 ) ) {
                if ( k <= numberOfColumns && l <= numberOfRows) {
                    EXPECT_NO_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(1,1),
                            Spreadsheet::Function::avg,
                            {SpreadsheetCellCoordinates(k,l)});
                    );
                }
                else {
                    EXPECT_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(1,1),
                            Spreadsheet::Function::avg,
                            {SpreadsheetCellCoordinates(k,l)});
                        ,
                        std::out_of_range
                    );
                }
            }
        }
    }
}

TEST(Spreadsheet,setFunctionAt__min__out_of_range_exception__function_arguments) {
    const std::size_t numberOfColumns = 8;
    const std::size_t numberOfRows = 8;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            if ( ! ( k==1 && l==1 ) ) {
                if ( k <= numberOfColumns && l <= numberOfRows) {
                    EXPECT_NO_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(1,1),
                            Spreadsheet::Function::min,
                            {SpreadsheetCellCoordinates(k,l)});
                    );
                }
                else {
                    EXPECT_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(1,1),
                            Spreadsheet::Function::min,
                            {SpreadsheetCellCoordinates(k,l)});
                            ,
                            std::out_of_range
                    );
                }
            }
        }
    }
}

TEST(Spreadsheet,setFunctionAt__max__out_of_range_exception__function_arguments) {
    const std::size_t numberOfColumns = 8;
    const std::size_t numberOfRows = 8;
    const std::size_t columnsIndexesOuterRange = 20;
    const std::size_t rowsIndexesOuterRange = 20;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,1),1.0);
    spreadsheet.setValueAt(SpreadsheetCellCoordinates(3,1),2.0);

    for (std::size_t k = 1; k <= numberOfColumns + columnsIndexesOuterRange; ++k) {
        for (std::size_t l = 1; l <= numberOfRows + rowsIndexesOuterRange; ++l) {
            if ( ! ( k==1 && l==1 ) ) {
                if ( k <= numberOfColumns && l <= numberOfRows) {
                    EXPECT_NO_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(1,1),
                            Spreadsheet::Function::max,
                            {SpreadsheetCellCoordinates(k,l)});
                    );
                }
                else {
                    EXPECT_THROW(
                        spreadsheet.setFunctionAt(
                            SpreadsheetCellCoordinates(1,1),
                            Spreadsheet::Function::max,
                            {SpreadsheetCellCoordinates(k,l)});
                        ,
                        std::out_of_range
                    );
                }
            }
        }
    }
}

TEST(Spreadsheet,deleteCellContentAt) {
    const std::size_t numberOfColumns = 8;
    const std::size_t numberOfRows = 8;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);

    for (std::size_t k = 1; k <= numberOfColumns; ++k) {
        for (std::size_t l = 1; l <= numberOfRows; ++l) {
            spreadsheet.deleteCellContentAt(SpreadsheetCellCoordinates(k,l));
            EXPECT_TRUE( spreadsheet.emptyCellAt(SpreadsheetCellCoordinates(k,l)) );
        }
    }
}

TEST(Spreadsheet,setValueAt_double) {
    const std::size_t numberOfColumns = 8;
    const std::size_t numberOfRows = 8;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);

    for (std::size_t k = 1; k <= numberOfColumns; ++k) {
        for (std::size_t l = 1; l <= numberOfRows; ++l) {
            const double value = 5873849.0;
            spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),value);
            EXPECT_EQ( spreadsheet.getCellAsNumericValueAt(SpreadsheetCellCoordinates(k,l)) , value );
        }
    }
}

TEST(Spreadsheet,setValueAt_string) {
    const std::size_t numberOfColumns = 8;
    const std::size_t numberOfRows = 8;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);

    for (std::size_t k = 1; k <= numberOfColumns; ++k) {
        for (std::size_t l = 1; l <= numberOfRows; ++l) {
            const std::string value = "Hello, world!";
            spreadsheet.setValueAt(SpreadsheetCellCoordinates(k,l),value);
            EXPECT_EQ( spreadsheet.getCellAsTextAt(SpreadsheetCellCoordinates(k,l)) , value );
        }
    }
}

TEST(Spreadsheet,setFunctionAt_sum_correct_behavior) {
    const std::size_t numberOfColumns = 2;
    const std::size_t numberOfRows = 2;

    Spreadsheet spreadsheet(numberOfColumns,numberOfRows);

    spreadsheet.setFunctionAt(
        SpreadsheetCellCoordinates(1,1),
        Spreadsheet::Function::sum,
        {
            SpreadsheetCellCoordinates(2,1),
            SpreadsheetCellCoordinates(2,2),
            SpreadsheetCellCoordinates(1,2)
        } );

    EXPECT_EQ(spreadsheet.getCellAsNumericValueAt(SpreadsheetCellCoordinates(1,1)), 0.0);

    spreadsheet.setValueAt(SpreadsheetCellCoordinates(2,1),"Ignored text");

    EXPECT_EQ(spreadsheet.getCellAsNumericValueAt(SpreadsheetCellCoordinates(1,1)), 0.0);

    spreadsheet.setValueAt(SpreadsheetCellCoordinates(2,1), 2.1);

    EXPECT_EQ(spreadsheet.getCellAsNumericValueAt(SpreadsheetCellCoordinates(1,1)), 2.1);

    spreadsheet.setValueAt(SpreadsheetCellCoordinates(2,2),2.2);

    EXPECT_EQ(spreadsheet.getCellAsNumericValueAt(SpreadsheetCellCoordinates(1,1)), 2.1+2.2); //The summation is performed in ascending order of values

    spreadsheet.deleteCellContentAt(SpreadsheetCellCoordinates(2,2));

    EXPECT_EQ(spreadsheet.getCellAsNumericValueAt(SpreadsheetCellCoordinates(1,1)), 2.1);

    spreadsheet.setValueAt(SpreadsheetCellCoordinates(2,2),2.2);

    EXPECT_EQ(spreadsheet.getCellAsNumericValueAt(SpreadsheetCellCoordinates(1,1)), 2.1+2.2); //The summation is performed in ascending order of values

    spreadsheet.setValueAt(SpreadsheetCellCoordinates(1,2),1.2);

    EXPECT_EQ(spreadsheet.getCellAsNumericValueAt(SpreadsheetCellCoordinates(1,1)), (1.2+2.1)+2.2 ); //The summation is performed in ascending order of values
}