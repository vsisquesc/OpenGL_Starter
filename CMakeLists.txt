cmake_minimum_required(VERSION 3.14)
project(OpenGL_Starter)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

# --- Opciones de backends ---
option(USE_WAYLAND "Use Wayland backend for GLFW" OFF)
option(USE_X11 "Use X11 backend for GLFW" ON)

# --- Configurar GLFW según opciones ---
if (USE_WAYLAND)
    message(STATUS "Using Wayland backend for GLFW")
    set(GLFW_BUILD_WAYLAND ON CACHE BOOL "Build Wayland backend" FORCE)
    set(GLFW_BUILD_X11 OFF CACHE BOOL "Do not build X11 backend" FORCE)
elseif(USE_X11)
    message(STATUS "Using X11 backend for GLFW")
    set(GLFW_BUILD_X11 ON CACHE BOOL "Build X11 backend" FORCE)
    set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Do not build Wayland backend" FORCE)
else()
    message(STATUS "No backend selected explicitly. Building both X11 and Wayland for GLFW.")
    set(GLFW_BUILD_X11 ON CACHE BOOL "Build X11 backend" FORCE)
    set(GLFW_BUILD_WAYLAND ON CACHE BOOL "Build Wayland backend" FORCE)
endif()

add_subdirectory(lib/OpenGL_Boilerplate) 

list(APPEND SOURCES
    src/main.cpp  )
add_executable(OpenGL_Starter ${SOURCES})

target_include_directories(OpenGL_Starter PUBLIC
    OpenGL_Boilerplate
    glfw
    glad
    imgui
    lib/linalg)

target_link_libraries(OpenGL_Starter PUBLIC OpenGL_Boilerplate
glfw
glad
imgui )