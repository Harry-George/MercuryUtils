cmake_minimum_required(VERSION 3.23)
project(MercuryUtils)

include(FetchContent)

option(BUILD_TESTING "If enabled will build all the tests" ON)
include(CTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if (BUILD_TESTING)

    FetchContent_Declare(
            googletest
            URL "https://github.com/google/googletest/archive/refs/tags/release-1.12.1.tar.gz"
            URL_HASH SHA256=81964fe578e9bd7c94dfdb09c8e4d6e6759e19967e397dbea48d1c10e45d0df2
    )

    SET(before-CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
    SET(CMAKE_CXX_FLAGS "")
    SET(BUILD_TESTING OFF)

    # Disable checks for gtest

    FetchContent_MakeAvailable(googletest)

    include_directories(SYSTEM
            "${googletest_SOURCE_DIR}/googletest/include"
            "${googletest_SOURCE_DIR}/googlemock/include"
            )

    # re-enable original before-
    SET(CMAKE_CXX_FLAGS ${before-CMAKE_CXX_FLAGS})
    SET(BUILD_TESTING ON)

    add_subdirectory(StaticMock/test)

endif ()

