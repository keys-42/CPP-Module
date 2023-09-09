#include "Bureaucrat.hpp"

int main()
{
	{
		try {
			Bureaucrat a("bereaucrat", 1);
			Form f("form", 1);
			a.signForm(f);
			std::cout << a << std::endl;
			std::cout << f << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("bereaucrat", 1);
			Form f("form", 100);
			a.signForm(f);
			std::cout << a << std::endl;
			std::cout << f << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("bereaucrat", 1);
			Form f("form", 150);
			a.signForm(f);
			std::cout << a << std::endl;
			std::cout << f << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("bereaucrat", 10);
			Form f("form", 1);
			a.signForm(f);
			std::cout << a << std::endl;
			std::cout << f << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("bereaucrat", 10);
			Form f("form", 100);
			a.signForm(f);
			std::cout << a << std::endl;
			std::cout << f << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("bereaucrat", 10);
			Form f("form", 150);
			a.signForm(f);
			std::cout << a << std::endl;
			std::cout << f << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("bereaucrat", 150);
			Form f("form", 1);
			a.signForm(f);
			std::cout << a << std::endl;
			std::cout << f << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("bereaucrat", 150);
			Form f("form", 100);
			a.signForm(f);
			std::cout << a << std::endl;
			std::cout << f << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("bereaucrat", 150);
			Form f("form", 150);
			a.signForm(f);
			std::cout << a << std::endl;
			std::cout << f << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;


	return 0;
}

