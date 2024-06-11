#ifndef INC_05_FORM_HPP
#define INC_05_FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
	class Form {
		private:
			const std::string name;
			bool isSigned;
			const int gradeToSign;
			const int gradeToExecute;
		public:
			Form(const std::string name = "Default Value", bool isSigned = false, int gradeToSign = 2, int gradeToExecute = 2);
			Form(const Form &other);
			~Form();
			Form &operator=(const Form &other);

			const std::string& getName() const;
			bool getIsSigned() const;
			int getGradeToSign() const;
			int getGradeToExecute() const;

			class GradeTooHighException : public std::exception {
				public:
					virtual const char *what() const throw();
			};
			class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
			};

			void beSigned(Bureaucrat &bureaucrat) throw(Form::GradeTooLowException);
	};

	std::ostream& operator<<(std::ostream& os, const Form& form);
#endif
