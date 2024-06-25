#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("28B", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("28B", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const throw(GradeTooLowException, FormNotSignedException)
{
	AForm::execute(executor);
	std::srand(std::time(NULL));
	double randomNumber = static_cast<double>(std::rand()) / RAND_MAX;
	if (randomNumber < 0.5)
		std::cout << this->target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}
