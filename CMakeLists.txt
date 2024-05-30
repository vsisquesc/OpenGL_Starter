cmake_minimum_required(VERSION 3.14)
project(OpenGL_Starter)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

 
add_subdirectory(lib/OpenGL_Boilerplate) 
list(APPEND SOURCES
    src/main.cpp  )
add_executable(OpenGL_Starter ${SOURCES})

target_include_directories(OpenGL_Starter PUBLIC
    OpenGL_Boilerplate
    glfw
    glad
    imgui)

target_link_libraries(OpenGL_Starter PUBLIC OpenGL_Boilerplate
glfw
glad
imgui )