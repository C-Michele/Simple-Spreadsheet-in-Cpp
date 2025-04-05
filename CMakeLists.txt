cmake_minimum_required(VERSION 3.30)
project(Simple_Spreadsheet)

set(CMAKE_CXX_STANDARD 17)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

add_subdirectory(unit_test)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
