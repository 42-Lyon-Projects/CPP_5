cmake_minimum_required(VERSION 3.27)
project(05)

set(CMAKE_CXX_STANDARD 98)
add_compile_options(-Wall -Wextra -Werror -g3 -std=c++98)

add_executable(05 ex01/Bureaucrat.cpp
        ex01/Bureaucrat.hpp
        ex01/main.cpp
        ex01/Form.cpp
        ex01/Form.hpp)
