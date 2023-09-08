#include "form.hpp"

Form::Form(std::string name): name_(name)
{
    std::cout << "Form Default constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form Default destructor called" << std::endl;
}

Form::Form(const Form & r): name_(r.name_), isSigned_(r.isSigned_) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Form & Form::operator=(const Form & f)
{
    std::cout << "Form copy assignment operator overload called" << std::endl;
    if (this != &f) {
        this->isSigned_ = f.isSigned_;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    std::stringstream ss;
    // ss << obj.
    // std::string str = ss.str();
    os << obj.getName() +  " Form " + ss.str() + ".";
    return os;
}

void Form::beSigned() { this->isSigned_ = !this->isSigned_; }