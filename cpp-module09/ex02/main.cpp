#include "PmergeMe.hpp"

int main( int argc, char **argv )
{
    if (argc < 1)
    {
        std::cout << "Usage: " << argv[0] << " use a positive integer sequence " << std::endl;
        return 1;
    }

	PmergeMe p;
    // PmergeMe< std::list<int>, std::list<int>::iterator > listInstance;
	// PmergeMe<std::vector<int> *p = new PmergeMe();
	try {
		p.inputValidation(++argv);
		p.initContainer(argv);
		p.print();
		std::cout << "PariwiseComparison" <<std::endl;
		p.PairwiseComparison();
		p.print();
		std::cout << "Recursion" <<std::endl;
		p.Recursion();
		p.print();
		std::cout << "InsertAtTheStart" <<std::endl;
		p.InsertAtTheStart();
		p.print();
		std::cout << "Insertion" <<std::endl;
		p.Insertion();
		p.print();
		
	} catch ( std::exception &e ) {
		std::cerr << "exception: " << e.what() << std::endl;
	}

    return 0;
}
