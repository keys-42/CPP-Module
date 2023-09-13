#include "PmergeMe.hpp"

int main( int argc, char **argv )
{
    if (argc < 1)
    {
        std::cout << "Usage: " << argv[0] << " use a positive integer sequence " << std::endl;
        return 1;
    }
	++argv;

	std::cout << std::endl << "list iterators" <<std::endl;
	try {
		PmergeMe p;
		// p.inputValidation(argv);
		p.initContainer(argv);
		p.printToList();
		std::cout << "PariwiseComparison" <<std::endl;
		p.PairwiseComparisonToList();
		p.printToList();
		std::cout << "RecursionToList" <<std::endl;
		p.RecursionToList();
		p.printToList();
		std::cout << "InsertAtTheStartToList" <<std::endl;
		p.InsertAtTheStartToList();
		p.printToList();
		std::cout << "InsertionToList" <<std::endl;
		p.InsertionToList();
		p.printToList();
		
	} catch ( std::exception &e ) {
		std::cerr << "exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "vector iterators" <<std::endl;

	try {
		PmergeMe p;
		// p.inputValidation(argv);
		p.initContainer(argv);
		p.printToVec();
		std::cout << "PariwiseComparison" <<std::endl;
		p.PairwiseComparisonToVec();
		p.printToVec();
		std::cout << "RecursionToVector" <<std::endl;
		p.RecursionToVec();
		p.printToVec();
		std::cout << "InsertAtTheStartToVector" <<std::endl;
		p.InsertAtTheStartToVec();
		p.printToVec();
		std::cout << "InsertionToVector" <<std::endl;
		p.InsertionToVec();
		p.printToVec();
		
	} catch ( std::exception &e ) {
		std::cerr << "exception: " << e.what() << std::endl;
	}

    return 0;
}
