#include "PmergeMe.hpp"

template <class T>
T parse(const std::string& s)
{
  T out;
  std::stringstream ss(s);
  ss >> out;
  return out;
}

int main( )
{
    // int arr[] = {"57", "21", "89", "34", "10", "73", "92", "46", "28", "66", "50","5", "99", "23"," 3", "15", "71", "80", "12", "44", "33", "90", "52", "29", "18", "82", "25"," 8", "62", "77" };
    int arr[] = {57, 21, 89, 34, 10, 73, 92, 46, 28, 66, 50, 5, 99, 23, 3, 15, 71, 80, 12, 44, 33, 90, 52, 29, 18, 82, 25, 8, 62, 77 };
    PmergeMe *p = new PmergeMe();
    p->FordJohnsonAlgorithm(30,arr);
    delete p;
    
    std::sort(arr, arr + 30);

    for(int i = 0; i < 30; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
