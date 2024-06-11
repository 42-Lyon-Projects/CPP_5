#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm(const std::string formName, int gradeToSign, int gradeToExecute) : name(formName),
	isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
                                   gradeToExecute(other.gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	isSigned = other.isSigned;
	return *this;
}

const std::string &AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const throw(GradeTooLowException, FormNotSignedException)
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	if (!this->getIsSigned())
		throw FormNotSignedException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << form.getName() << ", form is signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign()
	<< ", grade to execute: " << form.getGradeToExecute();
	return os;
}
