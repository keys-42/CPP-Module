#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ): AForm("PresidentialPardonForm", 25, 5), target_(target) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &r): AForm(r), target_(r.target_) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}


PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &r){
    std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
    if (this != &r) {
        this->target_ = r.target_;
    }
    return *this;
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if(executor.getGrade() > this->getExecutionGrade()) {
        throw AForm::GradeTooLowException("Grade too low to execute form");
    }
    std::cout << this->target_ << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
