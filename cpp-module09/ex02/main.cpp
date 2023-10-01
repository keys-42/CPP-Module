#include <cstdlib>

#include "PmergeMe.hpp"

int
main(int argc, char** argv) {
	if (argc <= 1) {
		std::cerr << "Usage ./Pmerge numbers" << std::endl;
		return 1;
	}

	PmergeMe p;
	p.FordJohnsonAlgorithm(argc - 1, ++argv);

	return 0;
}

#ifdef LEAK
__attribute__((destructor)) static void
destructor() {
	system("leaks -q Pmerge");
}
#endif