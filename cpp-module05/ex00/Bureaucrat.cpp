#include "Bureaucrat.hpp"
#include <sstream>


Bureaucrat::Bureaucrat(std::string name, int grade): name_(name)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
    try {
        throwGradeConstructorError(grade);
    } 
    catch (GradeTooHighException& e) {
        std::cout << e.whatMessage() << std::endl;
    }
    catch (GradeTooLowException& e) {
        std::cout << e.whatMessage() << std::endl;
    }
    grade_ = grade;

}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Default destructor called" << std::endl;
}

std::string Bureaucrat::getName() const { return this->name_; }
int Bureaucrat::getGrade() const { return this->grade_; }
void Bureaucrat::upgrade(int n) { 
    try {
        if(grade_ - n < 1)
            throw GradeTooHighException("Exception occurred: Grade value is too high.");
    } catch (GradeTooHighException& e) {
        std::cout << e.whatMessage() << std::endl;
        return ;
    }
    this->grade_ += n; 
}
void Bureaucrat::downgrade(int n) { 
    try {
        if(grade_ + n)
        throw GradeTooLowException("Exception occurred: Grade value is too low.");
    } catch (GradeTooLowException& e) {
        std::cout << e.whatMessage() << std::endl;
        return ;
    }
    this->grade_ -= n; 
}

void Bureaucrat::throwGradeConstructorError( int grade ) {
    if( grade < 1 )
        throw GradeTooHighException("Exception occurred: Grade value is too high.");
    else if ( 150 < grade )
        throw GradeTooLowException("Exception occurred: Grade value is too low.");
    return;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    std::stringstream ss;
    ss << obj.getGrade();
    std::string str = ss.str();
    os << obj.getName() +  " bureaucrat grade " + ss.str() + ".";
    return os;
}

