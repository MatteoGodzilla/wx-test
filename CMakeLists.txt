project(WX-test)

cmake_minimum_required(VERSION 3.15)

add_subdirectory("wxWidgets")

add_executable(${CMAKE_PROJECT_NAME} "src/main.cpp")

target_link_libraries(${CMAKE_PROJECT_NAME} wx::net wx::core wx::base)