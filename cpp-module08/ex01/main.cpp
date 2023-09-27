#include "Span.hpp"

// # define BIGNUMBER 2147483647
# define BIGNUMBER 2147483


# define GREEN "\033[32m"
# define RESET "\033[0m"

int main()
{
    {
        Span sp = Span(5);
        std::cout << GREEN;
        std::cout << std::endl << "--------empty-------- " << __FILE__ << " in " << __LINE__ << std::endl;   
        std::cout << RESET;
        try {
            std::cout << sp.shortestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << "exception: " << e.what() << std::endl;
        }

        std::cout << GREEN;
        std::cout << std::endl << "--------only one stored,-------- " << __FILE__ << " in " << __LINE__ << std::endl;   
        std::cout << RESET;
        try {
            sp.addNumber(6);
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << "exception: " << e.what() << std::endl;
        }

        try {
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << GREEN;
            std::cout << std::endl << "--------max size 5{try add}-------- " << __FILE__ << " in " << __LINE__ << std::endl;   
            sp.printContainer();
            std::cout << RESET;
            sp.addNumber(11);
        } catch (std::exception &e) {
            std::cout << "exception: " << e.what() << std::endl;
        }
        
        try {
            std::cout << GREEN;
            std::cout << std::endl << "--------shortestSpan && longestSpan-------- " << __FILE__ << " in " << __LINE__ << std::endl;   
            std::cout << RESET;
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << "exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << GREEN;
        std::cout << std::endl << "--------big container 2147483-------- " << __FILE__ << " in " << __LINE__ << std::endl;   
        std::cout << RESET;
        std::srand(static_cast<unsigned int>(std::time(0)));
        std::vector<int> bigumber(BIGNUMBER);
        int random_value = std::rand() % 500 + 1;
        for (int i = 1; i < BIGNUMBER; ++i) bigumber[i] = i * random_value;
        try 
        {
            Span b(BIGNUMBER);
            b.containerInsert<std::vector<int> >(bigumber);
            // b.printContainer();
            std::cout << "shortest span: " << b.shortestSpan() << std::endl;
            std::cout << "longest span : " << b.longestSpan() << std::endl;
            std::cout << "--------addNumber 1-------- " << __FILE__ << " in " << __LINE__ << std::endl;   
            b.addNumber(1);
        }  catch (std::exception& e) {
            std::cout << "exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << GREEN;
        std::cout << std::endl << "--------INT_MIN and INT_MAX-------- " << __FILE__ << " in " << __LINE__ << std::endl;   
        std::cout << RESET;
        std::vector<int> bbigumber(2);
        bbigumber[0] = -2147483648;
        bbigumber[1] = 2147483647;
        try 
        {
            Span b(2);
            b.containerInsert<std::vector<int> >(bbigumber);
            b.printContainer();
            std::cout << "shortest span: " << b.shortestSpan() << std::endl;
            std::cout << "longest span : " << b.longestSpan() << std::endl;
        }  catch (std::exception& e) {
            std::cout << "exception: " << e.what() << std::endl;
        }
    }
    return 0;
}
