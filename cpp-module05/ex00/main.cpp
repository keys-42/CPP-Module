#include "Bureaucrat.hpp"

int main()
{
	{
		try {
			Bureaucrat a("test", 1);
			std::cout << a << std::endl;
			Bureaucrat b("test", 100);
			std::cout << b << std::endl;
			Bureaucrat c("test", 150);
            std::cout << c << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 0);
			std::cout << a << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", -1);
			std::cout << a << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 151);
			std::cout << a << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 5);
			std::cout << a << std::endl;
			while(1)
			{
				a.upgrade(1);
				std::cout << a << std::endl;
			}
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 145);
			std::cout << a << std::endl;
			while(1)
			{
				a.downgrade(1);
				std::cout << a << std::endl;
			}
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 75);
			std::cout << a << std::endl;
			Bureaucrat b(a);
			std::cout << b << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 75);
			std::cout << a << std::endl;
			Bureaucrat b ("123456",100);
			std::cout << b << std::endl;
			b = a;
			std::cout << b << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
