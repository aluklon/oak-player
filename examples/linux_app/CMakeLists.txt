cmake_minimum_required(VERSION 3.1)

set(_NAME linux_app)

project(${_NAME})

add_executable(${_NAME} main.cpp)
target_compile_features(${_NAME} PRIVATE cxx_std_11)
target_link_libraries(${_NAME} oakplayer)
