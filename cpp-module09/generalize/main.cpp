#include "PmergeMe.hpp"
#include <cstdlib>

int main( int argc, char **argv )
{
    (void)argv;
  if (argc <= 1) {
      std::cerr << "argc <= 1" << std::endl;
      return 1;
  }

  PmergeMe *p = new PmergeMe();
  p->FordJohnsonAlgorithm(argc - 1,++argv);
  
  delete p;
//   delete[] arr;
  return 0;
}
