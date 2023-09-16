#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
    std::cout << "Intern assignation operator called" << std::endl;
    if( this != &other) { *this = other; }
    return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string requestName[3] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *form[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    AForm *ret = NULL;
	for (std::size_t i = 0; i < 3; ++i) {
			if (requestName[i] == formName) {
				ret = form[i];
                continue;
			}
            delete form[i];
	}
    if(ret) {
        std::cout << "Intern creates " << formName << std::endl;
    } else {
        std::cout << formName << ": Form could not be created." << std::endl;
    }
    return ret;
}