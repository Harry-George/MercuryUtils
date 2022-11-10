
add_library(
        sleep STATIC
        Sleep.cpp
)

add_executable(
    testSleepExe testSleep.cpp
)

target_link_libraries(
        testSleepExe gtest_main gmock_main ${CMAKE_THREAD_LIBS_INIT} sleep
)

add_test(
    NAME testSleep COMMAND testSleepExe
)

add_executable(
    testMockedSleepExe testMockedSleep.cpp
)

target_link_libraries(
        testMockedSleepExe gtest_main gmock_main ${CMAKE_THREAD_LIBS_INIT} sleep
)

add_test(
    NAME testMockedSleep COMMAND testMockedSleepExe
)