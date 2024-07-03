cmake_minimum_required(VERSION 3.26)
project(containers)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS --coverage)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(containers
        ./sources/set/capacity.hpp
        ./sources/set/iterators.hpp
        ./sources/set/lookup.hpp
        ./sources/set/member_functions.hpp
        ./sources/set/modifiers.hpp
        ./sources/set/set.hpp

        ./sources/RedBlackTree/delete.hpp
        ./sources/RedBlackTree/finders.hpp
        ./sources/RedBlackTree/getters.hpp
        ./sources/RedBlackTree/insert.hpp
        ./sources/RedBlackTree/printers.hpp
        ./sources/RedBlackTree/rbt.hpp
        ./sources/RedBlackTree/rotations.hpp
        ./sources/RedBlackTree/tree_walkers.hpp

        ./sources/map/capacity.hpp
        ./sources/map/iterators.hpp
        ./sources/map/lookup.hpp
        ./sources/map/map.hpp
        ./sources/map/member_functions.hpp
        ./sources/map/modifiers.hpp

        ./tests/header.h
        ./tests/set.cc
        ./tests/map.cc
)

target_link_libraries(
        containers
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(containers)