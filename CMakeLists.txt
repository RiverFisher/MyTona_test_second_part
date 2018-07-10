cmake_minimum_required(VERSION 3.8)
project(MyTonaTest)

set(CMAKE_CXX_STANDARD 11)

include_directories(./descriptions)
include_directories(./solutions)

set(SOURCE_FILES main.cpp
        Task.h Task.cpp
        Task_1/Task_1.cpp Task_1/Task_1.h
        Task_2/Task_2.cpp Task_2/Task_2.h
        Task_3/Task_3.cpp Task_3/Task_3.h
        Task_4/Task_4.cpp Task_4/Task_4.h
        Task_5/Task_5.cpp Task_5/Task_5.h
        Task_3/src/List.h config.h Task_5/Point2d.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(MyTonaTest ${SOURCE_FILES} Task.h)
