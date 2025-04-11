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
)

add_executable(${PROJECT_NAME} main.cpp
        ${SIMPLE_SPREADSHEET_SRC})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})