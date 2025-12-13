cmake_minimum_required(VERSION 3.20)
project(MyWebSocketApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server server.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(unofficial-uwebsockets CONFIG REQUIRED)


target_link_libraries(server PRIVATE unofficial::uwebsockets::uwebsockets)

