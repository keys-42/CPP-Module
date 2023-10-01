#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

class Intern {
public:
	Intern();
	Intern(Intern const& other);
	~Intern();
	Intern& operator=(Intern const& other);
	Form* makeForm(std::string formName, std::string target);
};
#endif