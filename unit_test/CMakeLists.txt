include(FetchContent)

FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/releases/download/v1.16.0/googletest-1.16.0.tar.gz
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

set(UNIT_TEST_SRC runAllTests.cpp
        SpreadsheetTests.cpp
        SpreadsheetCellCoordinatesTests.cpp
        SpreadsheetRawNumericCellTests.cpp
        SpreadsheetRawTextualCell.cpp
        SpreadsheetEmptyCellTests.cpp
        SpreadsheetSumCellTests.cpp
)

add_executable(runAllTests ${UNIT_TEST_SRC}
        ../src/Spreadsheet.cpp
        ../src/Spreadsheet.h
        ../src/utility/Observer.cpp
        ../src/utility/Observer.h
        ../src/utility/Subject.cpp
        ../src/utility/Subject.h
        ../src/SpreadsheetCellCoordinates.cpp
        ../src/SpreadsheetCellCoordinates.h
        ../src/SpreadsheetCell.cpp
        ../src/SpreadsheetCell.h
        ../src/SpreadsheetEmptyCell.cpp
        ../src/SpreadsheetEmptyCell.h
        ../src/SpreadsheetNotEmptyCell.cpp
        ../src/SpreadsheetNotEmptyCell.h
        ../src/SpreadsheetFunctionCell.cpp
        ../src/SpreadsheetFunctionCell.h
        ../src/SpreadsheetNumericCell.cpp
        ../src/SpreadsheetNumericCell.h
        ../src/SpreadsheetNumericFunctionCell.cpp
        ../src/SpreadsheetNumericFunctionCell.h
        ../src/SpreadsheetRawNumericCell.cpp
        ../src/SpreadsheetRawNumericCell.h
        ../src/SpreadsheetRawTextualCell.cpp
        ../src/SpreadsheetRawTextualCell.h
        ../src/SpreadsheetSumCell.cpp
        ../src/SpreadsheetSumCell.h
        ../src/SpreadsheetController.cpp
        ../src/SpreadsheetController.h
)
target_link_libraries(runAllTests gtest_main)

target_include_directories(runAllTests
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${gtest_SOURCE_DIR}/include
        ../src
)
