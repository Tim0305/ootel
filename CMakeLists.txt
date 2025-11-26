cmake_minimum_required(VERSION 4.2)
project(ootel CXX)

# compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# standard C++ 23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Creamos el ejecutable como target
add_executable(${PROJECT_NAME})

# Includes (modern CMake)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# GLOB + RECURSIVO + CONFIGURE_DEPENDS (automatico)
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/include/*.h
)

# Asignamos las fuentes al target
target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
