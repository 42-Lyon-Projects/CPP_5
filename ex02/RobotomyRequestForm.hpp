#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();

		RobotomyRequestForm(const std::string &name);

		RobotomyRequestForm(const RobotomyRequestForm &other);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const throw(GradeTooLowException, FormNotSignedException);

	private:
		const std::string target;
};
#endif //ROBOTOMYREQUESTFORM_HPP
