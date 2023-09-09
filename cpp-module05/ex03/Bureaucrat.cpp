#include "Bureaucrat.hpp"
#include <sstream>

Bureaucrat::Bureaucrat(std::string name, int grade): name_(name)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
    if( grade < 1 )
        throw GradeTooHighException("Exception occurred: Grade value is too high.");
    else if ( 150 < grade )
        throw GradeTooLowException("Exception occurred: Grade value is too low.");
    grade_ = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Default destructor called" << std::endl;
}

void Bureaucrat::upgrade(int n) { 
    if(grade_ - n < 1)
        throw GradeTooHighException("Exception occurred: Grade value is too high.");
    this->grade_ -= n;
}
void Bureaucrat::downgrade(int n) { 
    if(grade_ + n > 150)
        throw GradeTooLowException("Exception occurred: Grade value is too low.");
    this->grade_ += n;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    std::stringstream ss;
    ss << obj.getGrade();
    std::string str = ss.str();
    os << obj.getName() +  " bureaucrat grade " + ss.str() + ".";
    return os;
}

const std::string Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return this->grade_; }


Bureaucrat::Bureaucrat(const Bureaucrat & r): name_(r.getName()), grade_(r.getGrade()){
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
    std::cout << "Bureaucrat copy assignment operator overload called" << std::endl;
    if (this != &b) {
        this->grade_ = b.grade_;
    }
    return *this;
}

void Bureaucrat::signForm(AForm & f) const
{
    try {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    } catch ( AForm::GradeTooLowException & e ) {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
        return ;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try {
        if(form.getIsSigned() == false)
            throw AForm::GradeTooLowException("the form is not signed");
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch ( AForm::GradeTooLowException & e ) {
        std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << "." << std::endl;
        return ;
    }
}
