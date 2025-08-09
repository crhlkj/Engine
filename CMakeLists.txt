cmake_minimum_required(VERSION 3.31)
project(Engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLAD_DIR ${CMAKE_SOURCE_DIR}/include/glad)

add_library(glad STATIC ${GLAD_DIR}/src/glad.c)

include(FetchContent)

FetchContent_Declare(
	glfw
	GIT_REPOSITORY https://github.com/GLFW/GLFW.git
	GIT_TAG 3.4
)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.1
)

FetchContent_MakeAvailable(glfw glm)

find_package(OpenGL REQUIRED)

target_include_directories(glad PUBLIC ${GLAD_DIR}/include)

file(GLOB SOURCE_DIR 
	${CMAKE_SOURCE_DIR}/src/*.cpp
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/core/*.cppw
	${CMAKE_SOURCE_DIR}/src/core/*.h
	${CMAKE_SOURCE_DIR}/src/core/object/*.cpp
	${CMAKE_SOURCE_DIR}/src/core/object/*.h
)

add_executable(Engine 
	${SOURCE_DIR}
)

target_link_libraries(Engine PRIVATE glm glfw glad OpenGL::GL)