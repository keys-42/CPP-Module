#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name_;
        bool isSigned_;
        const int sigingGrade_;
        const int executionGrade_;

    public:
        AForm( const std::string& name, int sigingGrade );
        AForm( const std::string& name, int sigingGrade, int executionGrade );
        AForm(const AForm & r);
        virtual ~AForm();
        AForm & operator=(const AForm & f);
        const std::string getName() const;
        bool getIsSigned() const;
        int getSigingGrade() const;
        int getExecutionGrade() const;
        void beSigned(const Bureaucrat & b);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            const char *message_;

            public:
                explicit GradeTooHighException( const char *message ): message_(message) {}
                virtual const char* what() const throw() { return message_; }
        };

        class GradeTooLowException : public std::exception
        {
            const char *message_;

            public:
                explicit GradeTooLowException( const char *message ): message_(message) {}
                virtual const char* what() const throw() { return message_; }
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
