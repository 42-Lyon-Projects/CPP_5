#ifndef INC_05_BUREAUCRAT_HPP
#define INC_05_BUREAUCRAT_HPP

#include <string>
#include <ostream>
class Bureaucrat {
	private:
        const std::string name;
		int grade;
	public:
		Bureaucrat(const std::string name = "Default Value", int grade = 2);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &other);

		const std::string& getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

		void incrementGrade() throw(Bureaucrat::GradeTooHighException);
		void decrementGrade() throw(Bureaucrat::GradeTooLowException);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
