#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "iostream"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("28C", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("28C", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(
	Bureaucrat const &executor) const throw(GradeTooLowException, FormNotSignedException)
{
	AForm::execute(executor);
	std::string tree = "          .     .  .      +     .      .          .\n"
	"	 .       .      .     #       .           .\n"
	"		.      .         ###            .      .      .\n"
	"	  .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
	"		  .      . \"####\"###\"####\"  .\n"
	"	   .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
	"  .             \"#########\"#########\"        .        .\n"
	"		.    \"#:.  \"####\"###\"####\"  .:\"   .       .\n"
	"	 .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
	"				.\"##\"#####\"#####\"##\"           .      .\n"
	"	.   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
	"	  .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
	"	.    .     \"#####\"\"#######\"\"#####\"    .      .\n"
	"			.     \"      000      \"    .     .\n"
	"	   .         .   .   000     .        .       .\n"
	".. .. ..................O000O........................ ...... ...";
	std::cout << executor.getName() << " executed ShrubberyCreationForm " << this->target << std::endl;
	std::ofstream ofs;
	ofs.open((this->target + std::string("_shrubberry")).c_str(), std::ofstream::trunc);
	ofs << tree;
	ofs.close();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}
