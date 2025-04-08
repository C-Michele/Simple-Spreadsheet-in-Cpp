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
        SpreadsheetTests.cpp)

add_executable(runAllTests ${UNIT_TEST_SRC}
        ../src/Spreadsheet.cpp
        ../src/Spreadsheet.h
        ../src/utility/Observer.cpp
        ../src/utility/Observer.h
        ../src/utility/Subject.cpp
        ../src/utility/Subject.h)
target_link_libraries(runAllTests gtest_main)

target_include_directories(runAllTests
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${gtest_SOURCE_DIR}/include
        ../src
)
