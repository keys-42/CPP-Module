#include "PmergeMe.hpp"

int main( int argc, char **argv )
{
    if (argc < 1)
    {
        std::cout << "Usage: " << argv[0] << " use a positive integer sequence " << std::endl;
        return 1;
    }

	PmergeMe *p = new PmergeMe();
	try {
		p->inputValidation(++argv);
		p->initContainer(argv);
		p->print();
		p->PairwiseComparison();
		p->print();
		p->Recursion();
		p->print();
		p->Insertion();
		p->print();
		
	} catch ( std::exception &e ) {
		std::cerr << "exception: " << e.what() << std::endl;
	}
	delete p;

    return 0;
}
