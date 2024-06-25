#ifndef INC_05_FORM_HPP
#define INC_05_FORM_HPP
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		explicit AForm(const std::string name = "Default Value", int gradeToSign = 2, int gradeToExecute = 2);

		AForm(const AForm &other);

		virtual ~AForm();

		AForm &operator=(const AForm &other);

		const std::string &getName() const;

		bool getIsSigned() const;

		int getGradeToSign() const;

		int getGradeToExecute() const;

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

		class FormNotSignedException : public std::exception
		{
		public:
			const char *what() const throw();
		};

		void beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException);

		virtual void execute(Bureaucrat const &executor) const throw(GradeTooLowException, FormNotSignedException);
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
#endif
