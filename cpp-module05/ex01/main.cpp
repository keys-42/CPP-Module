#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("bereaucrat", 1);
			Form f("form", 1);
			std::cout << f << std::endl;
			a.signForm(f);
			std::cout << a << std::endl;
			std::cout << f << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
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
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
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
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
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
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
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
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
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
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
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
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
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
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
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

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q bureaucrat");
// }
