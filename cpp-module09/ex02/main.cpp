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
		p.PairwiseComparisonToVec();
		p.print();
		std::cout << "RecursionToVec" <<std::endl;
		p.RecursionToVec();
		p.print();
		std::cout << "InsertAtTheStartToVec" <<std::endl;
		p.InsertAtTheStartToVec();
		p.print();
		std::cout << "InsertionToVec" <<std::endl;
		p.InsertionToVec();
		p.print();
		
	} catch ( std::exception &e ) {
		std::cerr << "exception: " << e.what() << std::endl;
	}

    return 0;
}
