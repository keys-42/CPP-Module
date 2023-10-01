#include "Intern.hpp"

Intern::Intern() {
  std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other) {
  std::cout << "Intern copy constructor called" << std::endl;
  *this = other;
}

Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

Intern &Intern::operator=(Intern const &other) {
  std::cout << "Intern assignation operator called" << std::endl;
  if (this != &other) {
    *this = other;
  }
  return (*this);
}

int getFormIndex(const std::string &formName) {
  std::string requestName[3] = {"ShrubberyCreationForm", "RobotomyRequestForm",
                                "PresidentialPardonForm"};
  for (std::size_t i = 0; i < 3; ++i) {
    if (requestName[i] == formName) {
      return i;
    }
  }
  return -1;
}

Form *Intern::makeForm(std::string formName, std::string target) {
  Form *ret = NULL;

  switch (getFormIndex(formName)) {
  case 0:
    ret = new ShrubberyCreationForm(target);
    break;
  case 1:
    ret = new RobotomyRequestForm(target);
    break;
  case 2:
    ret = new PresidentialPardonForm(target);
    break;
  default:
    std::cout << formName << ": Form could not be created." << std::endl;
    return ret;
  }

  std::cout << "Intern creates " << formName << std::endl;
  return ret;
}
