project(RevolutionBMS)


if(test)
    add_subdirectory(gtest)

    enable_testing()

    include_directories(${PROJECT_SOURCE_DIR}/../include)
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

    add_executable(
        RunAllTests
        ./BMS/FilenameCompleteTest.cpp
        ./BMS/FilenameNopathTest.cpp
        ./BMS/FilenameNoextTest.cpp
        ./BMS/FilenameBaseonlyTest.cpp
        ./BMS/FilenameChangepathTest.cpp
        ./BMS/FilenameChangebaseTest.cpp
        ./BMS/FilenameChangeextTest.cpp
        ./BMS/FilenameRootTest.cpp
    )
    target_link_libraries(RunAllTests gtest gtest_main)
    target_link_libraries(RunAllTests SDLlib)
    target_link_libraries(RunAllTests BMSlib)
endif()
