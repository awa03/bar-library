cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source files
set(SOURCES
    main.cpp
    include/Bar.hpp
    include/Color.hpp
    include/Animation.hpp
    include/Symbols.hpp
)

# Add the executable
add_executable(executable ${SOURCES})

