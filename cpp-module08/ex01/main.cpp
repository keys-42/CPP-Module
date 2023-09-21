#include "Span.hpp"

# define BIGNUMBER 7777778

int main()
{
    Span sp = Span(5);
    try {
        std::cout << sp.shortestSpan() << std::endl;
    } catch (SpanException &e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
    sp.addNumber(6);
    try {
        std::cout << sp.longestSpan() << std::endl;
    } catch (SpanException &e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.printContainer();
    try {
        sp.addNumber(11);
    } catch (SizeOverFlowException &e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    

	std::vector<int> bigumber(BIGNUMBER);
	
	for (int i = 1; i < BIGNUMBER; ++i) bigumber[i] = i;
    try 
	{
		Span b(BIGNUMBER);
        b.containerInsert<std::vector<int> >(bigumber);
		std::cout << "shortest span: " << b.shortestSpan() << std::endl;
		std::cout << "longest span : " << b.longestSpan() << std::endl;
	}  catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
	}

	std::vector<int> bbigumber(2);
	bbigumber[0] = -2147483648;
	bbigumber[1] = 2147483647;
    try 
	{
		Span b(2);
        b.containerInsert<std::vector<int> >(bbigumber);
		std::cout << "shortest span: " << b.shortestSpan() << std::endl;
		std::cout << "longest span : " << b.longestSpan() << std::endl;
	}  catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
	}

    return 0;
}
