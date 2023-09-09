#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ): AForm("RobotomyRequestForm", 72, 45), target_(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &r): AForm(r), target_(r.target_) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &r){
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    if (this != &r) {
        this->target_ = r.target_;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if(executor.getGrade() > this->getExecutionGrade()) {
        throw AForm::GradeTooLowException("Grade too low to execute form");
    }

    std::cout << "The drill goes vrrrr!" << std::endl;
    srand(static_cast<unsigned int>(time(0)));

    if ((rand() % 2) == 1) {
        std::cout << this->target_ << " has been robotomized successfully\n";
    }
	else {
        std::cout << this->target_ << " has been robotomized unsuccessfully\n";
    }
}
