#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <ostream>
class AForm;

class Intern
{
	private:
		std::string keys[3];
		AForm *(Intern::*functions[3])(const std::string &target);
		AForm *spawnRobotomy(const std::string &target);
		AForm *spawnShrubbery(const std::string &target);
		AForm *spawnPardon(const std::string &target);
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm *makeForm(std::string &name, std::string &target);
		class FormNotFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	};
#endif
