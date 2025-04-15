cmake_minimum_required(VERSION 3.30)
project(Project_3)

set(CMAKE_CXX_STANDARD 20)

# compile flags to match Gradescope test environment
# Check if we are on a Windows platform
if (WIN32)
    # No /Werror flag for Windows compilers
else()
    # Add /Werror flag for non-Windows platforms
    set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror") # remove -Wall if you don't want as many warnings treated as errors
    # gradescope does use -Werror, so if you remove it here you may run into issues when trying to submit
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

# pull in desired version of catch through cmake automatically, make it available
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.5.2 # if you run into issues, try updating your editor or downgrading to a lower version of catch v3
)
FetchContent_MakeAvailable(Catch2)

add_executable(Project_3
        main.cpp
        # add your own header files below - should be automatically added in CLion
        # example (can also separate with newlines):
        # src/AVL.h src/AVL.cpp
)

# These tests can use the Catch2-provided main
add_executable(Tests
        Tests/test.cpp
        Tests/test-sfml.cpp # main test file
        # add your own header files below - should be automatically added in CLion
        # example (can also separate with newlines):
        # src/AVL.h src/AVL.cpp
)

target_compile_features(Project_3 PRIVATE cxx_std_17)
target_link_libraries(Project_3 PRIVATE SFML::Graphics)
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain) # link catch to test.cpp file
target_link_libraries(Tests PRIVATE SFML::Graphics) # link sfml to test.cpp file
# the name here must match that of your testing executable (the one that has test.cpp)

# comment everything below out if you are using CLion
# include(CTest)
# include(Catch)
# catch_discover_tests(Tests) # must be named the same as your test executable