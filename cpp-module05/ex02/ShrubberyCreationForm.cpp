#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ): AForm("ShrubberyCreationForm", 145, 137), target_(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &r): AForm(r), target_(r.target_) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &r){
    std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
    if (this != &r) {
        this->target_ = r.target_;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if(executor.getGrade() > this->getExecutionGrade()) {
        throw AForm::GradeTooLowException("Grade too low to execute form");
    }
    std::string file = this->target_ + "_shrubbery";
    std::ofstream outfile(file.c_str());
    if (!outfile) {
        std::cerr << "file open error"<< std::endl;
        exit(1);
    }
    srand(static_cast<unsigned int>(time(0)));
    int height = rand() % 100 + 1;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < height - i - 1; ++j) {
            outfile << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            outfile << "*";
        }
        outfile << std::endl;
    }
    for (int i = 0; i < height / 3; ++i) {
        for (int j = 0; j < height - 1; ++j) {
            outfile << " ";
        }
        outfile << "*" << std::endl;
    }
    outfile.close();
}