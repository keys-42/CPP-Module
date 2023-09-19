#include "PmergeMe.hpp"
#include <cstdlib>

int main( int argc, char **argv )
{
    (void)argv;
  if (argc <= 1) {
      std::cerr << "argc <= 1" << std::endl;
      return 1;
  }
  // int n = argc - 1;
  // int* arr = new int[n];

  int n = 42;
  int* arr = new int[n];
int arr1[] = {
       90, 32, 61, 58, 22, 92, 40, 55, 36, 11, 
       87, 30, 4,  59, 23, 39, 5,  13, 82, 18, 
       26, 84, 21, 8,  44, 1,  46, 43, 14, 29, 
       62, 79, 71, 99, 91, 50, 51, 88, 35, 54, 
       73, 56, 53,
      };
//   int arr1[] = {
//     53, 95, 35, 36, 24, 20, 97, 71, 78, 48, 
//     50, 25, 28, 56, 74, 91, 43, 23, 90, 14, 
//     31, 89, 38, 98, 93, 57, 33, 99, 77, 61, 
//     63, 52, 87, 80, 19, 2, 72, 21, 94, 65, 
//     60, 22};
  for(int i = 1; i <= n; ++i) {
      arr[i-1] = arr1[i-1];
  }  
//   for(int i = 1; i < argc; ++i) {
//       arr[i-1] = std::atoi(argv[i]);
//   }  

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
