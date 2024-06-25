#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{ {
		Bureaucrat *john = NULL;
		try
		{
			john = new Bureaucrat("John", 2);
			std::cout << *john << std::endl;
			john->incrementGrade();
			std::cout << *john << std::endl;
			john->decrementGrade();
			std::cout << *john << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		if (john != NULL)
			delete john;
	} {
		try
		{
			Bureaucrat lennon("Lennon");
			std::cout << lennon << std::endl;
			lennon.incrementGrade();
			std::cout << lennon << std::endl;
			lennon.decrementGrade();
			std::cout << lennon << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	} {
		try
		{
			Bureaucrat lennon("Lennon 2", 100);
			PresidentialPardonForm presidential("SKAH");
			lennon.signForm(presidential);
			presidential.execute(lennon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	} {
		try
		{
			Bureaucrat lennon("Lennon 3", 1);
			RobotomyRequestForm form("TA");
			lennon.signForm(form);
			form.execute(lennon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	} {
		try
		{
			Bureaucrat lennon("Lennon 4", 1);
			ShrubberyCreationForm form("MA");
			lennon.signForm(form);
			form.execute(lennon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	} {
		try
		{
			RobotomyRequestForm form("Robotomy");
			Bureaucrat officer("Offier", 1);
			form.execute(officer);
			officer.executeForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
