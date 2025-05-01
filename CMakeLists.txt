cmake_minimum_required(VERSION 3.30)

project(Simple_Spreadsheet)

set(CMAKE_CXX_STANDARD 17)

find_package(wxWidgets REQUIRED COMPONENTS net core base)

if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

add_subdirectory(unit_test)

set(SIMPLE_SPREADSHEET_SRC src/Spreadsheet.cpp
        src/Spreadsheet.h
        src/utility/Observer.cpp
        src/utility/Observer.h
        src/utility/Subject.cpp
        src/utility/Subject.h
        src/SpreadsheetCellCoordinates.cpp
        src/SpreadsheetCellCoordinates.h
        src/SpreadsheetCell.cpp
        src/SpreadsheetCell.h
        src/SpreadsheetEmptyCell.cpp
        src/SpreadsheetEmptyCell.h
        src/SpreadsheetNotEmptyCell.cpp
        src/SpreadsheetNotEmptyCell.h
        src/SpreadsheetFunctionCell.cpp
        src/SpreadsheetFunctionCell.h
        src/SpreadsheetNumericCell.cpp
        src/SpreadsheetNumericCell.h
        src/SpreadsheetNumericFunctionCell.cpp
        src/SpreadsheetNumericFunctionCell.h
        src/SpreadsheetRawNumericCell.cpp
        src/SpreadsheetRawNumericCell.h
        src/SpreadsheetRawTextualCell.cpp
        src/SpreadsheetRawTextualCell.h
        src/SpreadsheetSumCell.cpp
        src/SpreadsheetSumCell.h
        src/SpreadsheetController.cpp
        src/SpreadsheetController.h
        src/View.cpp
        src/View.h
)

add_executable(${PROJECT_NAME} main.cpp
        ${SIMPLE_SPREADSHEET_SRC})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})