#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main()
{
	AForm *form;
	std::cout << "----------------ShrubberyCreationForm---------------- " << __FILE__ << " in " << __LINE__ << std::endl << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			form = Intern().makeForm("ShrubberyCreationForm", "tree");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 140);
			form = Intern().makeForm("ShrubberyCreationForm", "tree");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 145);
			form = Intern().makeForm("ShrubberyCreationForm", "tree");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 150);
			form = Intern().makeForm("ShrubberyCreationForm", "tree");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	
	std::cout << "----------------RobotomyRequestForm---------------- " << __FILE__ << " in " << __LINE__ << std::endl << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			form = Intern().makeForm("RobotomyRequestForm", "robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 46);
			form = Intern().makeForm("RobotomyRequestForm", "robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 72);
			form = Intern().makeForm("RobotomyRequestForm", "robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 73);
			form = Intern().makeForm("RobotomyRequestForm", "robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;

	std::cout << "----------------PresidentialPardonForm---------------- " << __FILE__ << " in " << __LINE__ << std::endl << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			form = Intern().makeForm("PresidentialPardonForm", "presidentialPardonForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 10);
			form = Intern().makeForm("PresidentialPardonForm", "presidentialPardonForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 25);
			form = Intern().makeForm("PresidentialPardonForm", "presidentialPardonForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 100);
			form = Intern().makeForm("PresidentialPardonForm", "presidentialPardonForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;

	return 0;
}
