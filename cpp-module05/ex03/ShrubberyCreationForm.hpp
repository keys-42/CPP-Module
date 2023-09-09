#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target_;

    public:
        ShrubberyCreationForm( const std::string& target );
        ShrubberyCreationForm(const ShrubberyCreationForm & r);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &r);
        void execute(Bureaucrat const &executor) const;
};

#endif