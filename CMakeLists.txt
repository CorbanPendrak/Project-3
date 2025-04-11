cmake_minimum_required(VERSION 3.30)
project(Project_3)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(Project_3 main.cpp)
target_compile_features(Project_3 PRIVATE cxx_std_17)
target_link_libraries(Project_3 PRIVATE SFML::Graphics)