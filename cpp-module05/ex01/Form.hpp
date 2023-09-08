
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <sstream>

class Form
{
    private:
        const std::string name_;
        bool isSigned_;
    public:
        Form(std::string name);
 		Form(const Form & r);
        ~Form();
        Form & operator=(const Form & f);
        const std::string getName() const;
        const bool getIsSigned() const;
        void beSigned();

        class GradeTooHighException : public std::exception
        {
            const char *message_;

            public:
                explicit GradeTooHighException( const char *message ): message_(message) {}
                const char* whatMessage() const { return message_; }
        };

        class GradeTooLowException : public std::exception
        {
            const char *message_;

            public:
                explicit GradeTooLowException( const char *message ): message_(message) {}
                const char* whatMessage() const { return message_; }
        };

};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
