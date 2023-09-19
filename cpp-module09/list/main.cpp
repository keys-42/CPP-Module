#include "PmergeMe.hpp"
#include <cstdlib>

template <class T>
T parse(const std::string& s)
{
  T out;
  std::stringstream ss(s);
  ss >> out;
  return out;
}
#define N 31
int main( int argc, char **argv )
{
  if (argc <= 1) {
      std::cerr << "argc <= 1" << std::endl;
      return 1;
  }

  int n = argc - 1;
  int* arr = new int[n];

  for(int i = 1; i < argc; ++i) {
      arr[i-1] = std::atoi(argv[i]);
  }

  std::cout << "Input      " << std::endl;
  for(int i = 0; i < n; ++i) {
      std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "FordJohnson" << std::endl;

  PmergeMe *p = new PmergeMe();
  p->FordJohnsonAlgorithm(n,arr);
  
  std::cout << "std::sort  " << std::endl;
  std::sort(arr, arr + n);
  for(int i = 0; i < n; ++i) {
      std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  delete p;
  delete[] arr;
  return 0;
}
