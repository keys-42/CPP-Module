#ifndef  ROBOTOMYREQUESTFORM_HPP
#define  ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target_;

    public:
        RobotomyRequestForm( const std::string& target );
        RobotomyRequestForm(const RobotomyRequestForm & r);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm const &r);
        void execute(Bureaucrat const &executor) const;
};

#endif