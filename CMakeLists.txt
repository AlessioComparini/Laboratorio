cmake_minimum_required(VERSION 3.13)
project(LaboratorioDiProgrammazione)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(test)
set (SOURCE_FILES Activity.cpp Activity.h Date.cpp Date.h TodoList.cpp TodoList.h ListOfLists.cpp ListOfLists.h)
add_executable(LaboratorioDiProgrammazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(LaboratorioDiProgrammazione core)
