#include "Intern.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	this->keys[0] = "robotomy request";
	this->keys[1] = "presidential pardon";
	this->keys[2] = "shrubbery creation";

	this->functions[0] = &Intern::spawnRobotomy;
	this->functions[1] = &Intern::spawnPardon;
	this->functions[2] = &Intern::spawnShrubbery;
}

AForm *Intern::spawnPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::spawnRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::spawnShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;
}

Intern::~Intern()
{
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Sorry, the form doesn't exists !";
}

AForm *Intern::makeForm(std::string &name, std::string &target)
{
	size_t i = 0;

	while (i < 3 && this->keys[i] != name)
		i++;
	if (this->keys[i] != name)
	{
		std::cout << "Intern creates " << name << std::endl;
		return (this->*functions[i])(target);
	}
	throw FormNotFoundException();
}
