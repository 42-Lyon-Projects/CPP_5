#ifndef INC_05_BUREAUCRAT_HPP
#define INC_05_BUREAUCRAT_HPP
#include <string>
#include <ostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		class GradeTooHighException : public std::exception
		{
		public:
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
		public:
			const char *what() const throw();
		};

		Bureaucrat(const std::string name = "Default Value", int grade = 2);

		Bureaucrat(const Bureaucrat &other);

		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &other);

		const std::string &getName() const;

		int getGrade() const;

		void incrementGrade() throw(GradeTooHighException);

		void decrementGrade() throw(GradeTooLowException);

		void signForm(AForm &form);
		void executeForm(const AForm &form);

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
#endif
