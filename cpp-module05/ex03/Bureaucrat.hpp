#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Form;

class Bureaucrat {

private:
  const std::string name_;
  int grade_;

public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &r);
  ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &b);
  const std::string getName() const;
  int getGrade() const;
  void upgrade(int n);
  void downgrade(int n);
  void signForm(Form &f) const;
  void executeForm(Form const &form) const;

  class GradeTooHighException : public std::exception {
    const char *message_;

  public:
    explicit GradeTooHighException(const char *message) : message_(message) {}
    virtual const char *what() const throw() { return message_; }
  };

  class GradeTooLowException : public std::exception {
    const char *message_;

  public:
    explicit GradeTooLowException(const char *message) : message_(message) {}
    virtual const char *what() const throw() { return message_; }
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
