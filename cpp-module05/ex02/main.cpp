#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::cout << "--------ShrubberyCreationForm---------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	std::cout << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			ShrubberyCreationForm shrubberyCreationForm("tree1");
			std::cout << bureaucrat << std::endl;
			std::cout << shrubberyCreationForm;
			bureaucrat.signForm(shrubberyCreationForm);
			bureaucrat.executeForm(shrubberyCreationForm);
			std::cout << shrubberyCreationForm;
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 140);
			ShrubberyCreationForm shrubberyCreationForm("tree2");
			std::cout << bureaucrat << std::endl;
			std::cout << shrubberyCreationForm;
			bureaucrat.signForm(shrubberyCreationForm);
			bureaucrat.executeForm(shrubberyCreationForm);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 145);
			ShrubberyCreationForm shrubberyCreationForm("tree");
			std::cout << bureaucrat << std::endl;
			std::cout << shrubberyCreationForm;
			bureaucrat.signForm(shrubberyCreationForm);
			std::cout << shrubberyCreationForm;
			bureaucrat.executeForm(shrubberyCreationForm);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 150);
			ShrubberyCreationForm shrubberyCreationForm("tree");
			std::cout << bureaucrat << std::endl;
			std::cout << shrubberyCreationForm;
			bureaucrat.signForm(shrubberyCreationForm);
			bureaucrat.executeForm(shrubberyCreationForm);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "--------RobotomyRequestForm---------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	std::cout << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			RobotomyRequestForm robotomyRequestForm("robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << robotomyRequestForm;
			bureaucrat.signForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 46);
			RobotomyRequestForm robotomyRequestForm("robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << robotomyRequestForm;
			bureaucrat.signForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 72);
			RobotomyRequestForm robotomyRequestForm("robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << robotomyRequestForm;
			bureaucrat.signForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 73);
			RobotomyRequestForm robotomyRequestForm("robotomyRequestForm");
			std::cout << bureaucrat << std::endl;
			std::cout << robotomyRequestForm;
			bureaucrat.signForm(robotomyRequestForm);
			bureaucrat.executeForm(robotomyRequestForm);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------PresidentialPardonForm---------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	std::cout << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			PresidentialPardonForm presidentform("President");
			std::cout << bureaucrat << std::endl;
			std::cout << presidentform;
			bureaucrat.signForm(presidentform);
			bureaucrat.executeForm(presidentform);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 10);
			PresidentialPardonForm presidentform("President");
			std::cout << bureaucrat << std::endl;
			std::cout << presidentform;
			bureaucrat.signForm(presidentform);
			bureaucrat.executeForm(presidentform);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 25);
			PresidentialPardonForm presidentform("President");
			std::cout << bureaucrat << std::endl;
			std::cout << presidentform;
			bureaucrat.signForm(presidentform);
			bureaucrat.executeForm(presidentform);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 100);
			PresidentialPardonForm presidentform("President");
			std::cout << bureaucrat << std::endl;
			std::cout << presidentform;
			bureaucrat.signForm(presidentform);
			bureaucrat.executeForm(presidentform);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Jim", 1);
			PresidentialPardonForm presidentform("President");
			std::cout << bureaucrat << std::endl;
			std::cout << presidentform;
			bureaucrat.executeForm(presidentform);
			bureaucrat.signForm(presidentform);
			bureaucrat.executeForm(presidentform);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;

	return 0;
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q bureaucrat");
// }