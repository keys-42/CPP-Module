#include "AForm.hpp"

AForm::AForm(const std::string& name, int sigingGrade): name_(name), isSigned_(false), sigingGrade_(sigingGrade), executionGrade_(0) {
    std::cout << "AForm Default constructor called" << std::endl;
    if( sigingGrade < 1 )
        throw GradeTooHighException("Exception occurred: Grade value is too high.");
    else if ( 150 < sigingGrade )
        throw GradeTooLowException("Exception occurred: Grade value is too low.");
}

AForm::AForm(const std::string& name, int sigingGrade, int executionGrade): name_(name), isSigned_(false), sigingGrade_(sigingGrade), executionGrade_(executionGrade) {
    std::cout << "AForm Default constructor called" << std::endl;
    if( sigingGrade < 1 )
        throw GradeTooHighException("Exception occurred: Grade value is too high.");
    else if ( 150 < sigingGrade )
        throw GradeTooLowException("Exception occurred: Grade value is too low.");
}

AForm::~AForm()
{
    std::cout << "AForm Default destructor called" << std::endl;
}

AForm::AForm(const AForm & r): name_(r.name_), isSigned_(r.isSigned_), sigingGrade_(r.sigingGrade_), executionGrade_(r.executionGrade_){
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

AForm & AForm::operator=(const AForm & f)
{
    std::cout << "AForm copy assignment operator overload called" << std::endl;
    if (this != &f) {
        this->isSigned_ = f.isSigned_;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    std::stringstream isSigned;
    isSigned << obj.getIsSigned();
    std::stringstream sigingGrade;
    sigingGrade << obj.getSigingGrade();
    std::stringstream executionGrade;
    executionGrade << obj.getExecutionGrade();
    
    os \
    << "{" << std::endl \
    << "    name_: " << obj.getName() << std::endl \
    << "    isSigned_: " << isSigned.str() << std::endl \
    << "    sigingGrade_: " << sigingGrade.str() << std::endl \
    << "    executionGrade_: " << executionGrade.str() << std::endl \
    << "}" << std::endl;
    return os;
}

void AForm::beSigned(const Bureaucrat & b){
    if(b.getGrade() > this->sigingGrade_){
        throw GradeTooLowException("his grade was too low");
    }
    this->isSigned_ = true;
}

const std::string AForm::getName() const { return this->name_; }
bool AForm::getIsSigned() const { return this->isSigned_; }
int AForm::getSigingGrade() const { return this->sigingGrade_; }
int AForm::getExecutionGrade() const { return this->executionGrade_; }
