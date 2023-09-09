#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
	std::cout << "----------------ShrubberyCreationForm---------------- " << __FILE__ << " in " << __LINE__ << std::endl << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			ShrubberyCreationForm shrubberyCreationForm("shrubberyCreationForm");
			std::cout << bureaucrat << std::endl;
			std::cout << shrubberyCreationForm;
			bureaucrat.signForm(shrubberyCreationForm);
			bureaucrat.executeForm(shrubberyCreationForm);
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
			ShrubberyCreationForm shrubberyCreationForm("shrubberyCreationForm");
			std::cout << bureaucrat << std::endl;
			std::cout << shrubberyCreationForm;
			bureaucrat.signForm(shrubberyCreationForm);
			bureaucrat.executeForm(shrubberyCreationForm);
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
			ShrubberyCreationForm shrubberyCreationForm("shrubberyCreationForm");
			std::cout << bureaucrat << std::endl;
			std::cout << shrubberyCreationForm;
			bureaucrat.signForm(shrubberyCreationForm);
			bureaucrat.executeForm(shrubberyCreationForm);
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
			ShrubberyCreationForm shrubberyCreationForm("shrubberyCreationForm");
			std::cout << bureaucrat << std::endl;
			std::cout << shrubberyCreationForm;
			bureaucrat.signForm(shrubberyCreationForm);
			bureaucrat.executeForm(shrubberyCreationForm);
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
			RobotomyRequestForm robotomyRequestForm("robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << robotomyRequestForm;
			bureaucrat.signForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
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
			RobotomyRequestForm robotomyRequestForm("robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << robotomyRequestForm;
			bureaucrat.signForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
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
			RobotomyRequestForm robotomyRequestForm("robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << robotomyRequestForm;
			bureaucrat.signForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
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
			RobotomyRequestForm robotomyRequestForm("robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << robotomyRequestForm;
			bureaucrat.signForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
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
			PresidentialPardonForm presidentform("President");
			std::cout << bureaucrat << std::endl;
			std::cout << presidentform;
			bureaucrat.signForm(presidentform);
			bureaucrat.executeForm(presidentform);
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
			PresidentialPardonForm presidentform("President");
			std::cout << bureaucrat << std::endl;
			std::cout << presidentform;
			bureaucrat.signForm(presidentform);
			bureaucrat.executeForm(presidentform);
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
			PresidentialPardonForm presidentform("President");
			std::cout << bureaucrat << std::endl;
			std::cout << presidentform;
			bureaucrat.signForm(presidentform);
			bureaucrat.executeForm(presidentform);
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
			PresidentialPardonForm presidentform("President");
			std::cout << bureaucrat << std::endl;
			std::cout << presidentform;
			bureaucrat.signForm(presidentform);
			bureaucrat.executeForm(presidentform);
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;

	return 0;
}
