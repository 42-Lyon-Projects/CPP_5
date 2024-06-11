#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();

		PresidentialPardonForm(const std::string &name);

		PresidentialPardonForm(const PresidentialPardonForm &other);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const throw(GradeTooLowException, FormNotSignedException);

	private:
		const std::string target;
};
#endif //PRESIDENTIALPARDONFORM_HPP
