#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();

		ShrubberyCreationForm(const std::string &name);

		ShrubberyCreationForm(const ShrubberyCreationForm &other);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const throw(GradeTooLowException, FormNotSignedException);

	private:
		const std::string target;
};
#endif //SHRUBBERYCREATIONFORM_HPP
