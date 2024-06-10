#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	{
		Bureaucrat *john = NULL;
		try {
			john = new Bureaucrat("John", 0);
			std::cout << *john << std::endl;
			john->incrementGrade();
			std::cout << *john << std::endl;
			john->decrementGrade();
			std::cout << *john << std::endl;
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		if (john != NULL)
			delete john;
	}
	{
		try {
			Bureaucrat lennon("Lennon");
			std::cout << lennon << std::endl;
			lennon.incrementGrade();
			std::cout << lennon << std::endl;
			lennon.decrementGrade();
			std::cout << lennon << std::endl;
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}