cmake_minimum_required(VERSION 3.27)
project(05)

set(CMAKE_CXX_STANDARD 98)
add_compile_options(-Wall -Wextra -Werror -g3 -std=c++98)

add_executable(05 ex03/Bureaucrat.cpp
        ex03/Bureaucrat.hpp
        ex03/main.cpp
        ex03/AForm.cpp
        ex03/AForm.hpp
        ex03/PresidentialPardonForm.cpp
        ex03/PresidentialPardonForm.hpp
        ex03/RobotomyRequestForm.cpp
        ex03/ShrubberyCreationForm.cpp
        ex03/ShrubberyCreationForm.hpp
        ex03/Intern.hpp
        ex03/Intern.cpp)
