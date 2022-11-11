cmake_minimum_required(VERSION 3.22.1)

project(gl_bindings)

set(CMAKE_CXX_STANDARD, 17)

add_library(gl_bindings main.cpp glb/Shader.cpp glb/Exception.h)

set(EXT_DEPS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extDeps)

# Configuring glfw and glad
set(GLFW_DIR ${EXT_DEPS_DIR}/glfw-3.3.8)
set(GLAD_DIR ${EXT_DEPS_DIR}/glad)
add_subdirectory(${GLFW_DIR})
add_subdirectory(${GLAD_DIR})
find_package(OpenGL REQUIRED)
target_link_libraries(gl_bindings PRIVATE glfw OpenGL::GL glad)
target_include_directories(gl_bindings PRIVATE ${GLFW_DIR}/include ${GLAD_DIR}/include)




