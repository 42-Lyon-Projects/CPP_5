#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#include "iostream"

PresidentialPardonForm::PresidentialPardonForm() : AForm("28A", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("28A", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const throw(GradeTooLowException, FormNotSignedException)
{
	AForm::execute(executor);
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}
