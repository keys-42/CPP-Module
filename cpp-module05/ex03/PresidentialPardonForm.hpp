#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public Form {
private:
	std::string target_;

public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(PresidentialPardonForm const& r);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(PresidentialPardonForm const& r);
	void execute(Bureaucrat const& executor) const;
};

#endif
