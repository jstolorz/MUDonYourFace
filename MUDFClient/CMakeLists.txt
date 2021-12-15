cmake_minimum_required(VERSION 3.21)
project(MUDFClient)

set(CMAKE_CXX_STANDARD 20)

if(MINGW)
    target_link_libraries(MUDFNetworking ws2_32)
endif()

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC MUDFNetworking)

target_link_libraries(${PROJECT_NAME} PUBLIC MUDFNetworking)
