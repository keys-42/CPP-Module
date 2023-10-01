#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Form* form;
	Intern* intern = new Intern();
	std::cout << "--------ShrubberyCreationForm---------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	std::cout << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			form = intern->makeForm("ShrubberyCreationForm", "tree");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 140);
			form = intern->makeForm("ShrubberyCreationForm", "tree");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 145);
			form = intern->makeForm("ShrubberyCreationForm", "tree");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 150);
			form = intern->makeForm("ShrubberyCreationForm", "tree");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "--------RobotomyRequestForm---------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	std::cout << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			form = intern->makeForm("RobotomyRequestForm", "robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 46);
			form = intern->makeForm("RobotomyRequestForm", "robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 72);
			form = intern->makeForm("RobotomyRequestForm", "robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 73);
			form = intern->makeForm("RobotomyRequestForm", "robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "--------PresidentialPardonForm---------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	std::cout << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			form = intern->makeForm("PresidentialPardonForm", "presidentialPardonForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 10);
			form = intern->makeForm("PresidentialPardonForm", "presidentialPardonForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 25);
			form = intern->makeForm("PresidentialPardonForm", "presidentialPardonForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 100);
			form = intern->makeForm("PresidentialPardonForm", "presidentialPardonForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "--------Intern---------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	std::cout << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__
			  << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			form = intern->makeForm("PresidentialPardonForm", "presidentialPardonForm");
			std::cout << bureaucrat << std::endl;
			std::cout << *form;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------Invalid form name test-------------------- " << __FILE__ << " in "
			  << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			form = intern->makeForm("", "presidentialPardonForm");
			if (!form)
				throw std::runtime_error("Invalid form.");
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------Invalid form name test-------------------- " << __FILE__ << " in "
			  << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			form = intern->makeForm("test", "presidentialPardonForm");
			if (!form)
				throw std::runtime_error("Invalid form.");
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl
			  << "--------Invalid form name test-------------------- " << __FILE__ << " in "
			  << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			form = intern->makeForm("test test test", "presidentialPardonForm");
			if (!form)
				throw std::runtime_error("Invalid form.");
			delete form;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	delete intern;
	return 0;
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q intern");
// }