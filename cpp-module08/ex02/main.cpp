#include "MutantStack.hpp"
// #include "MutantStackList.hpp"
// #include "MutantStackVector.hpp"
#include <unistd.h>
#define N 10
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main() {
  std::cout << "==========subject test==========" << std::endl;
  {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << GREEN;
    std::cout << "stack top   " << __FILE__ << " in " << __LINE__ << std::endl;
    mstack.print();
    std::cout << RESET;
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << GREEN;
    std::cout << "stack size  " << __FILE__ << " in " << __LINE__ << std::endl;
    mstack.print();
    std::cout << RESET;
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    for (int i = 0; i < N; i++) {
      mstack.push(i);
    }
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << GREEN;
    std::cout << "it = mstack.begin()" << __FILE__ << " in " << __LINE__
              << std::endl;
    mstack.print();
    std::cout << RESET;
    std::cout << *it << std::endl;
    std::cout << GREEN;
    std::cout << " ++it " << __FILE__ << " in " << __LINE__ << std::endl;
    mstack.print();
    std::cout << RESET;
    ++it;
    std::cout << *it << std::endl;
    std::cout << GREEN;
    std::cout << " --it " << __FILE__ << " in " << __LINE__ << std::endl;
    mstack.print();
    std::cout << RESET;
    --it;
    std::cout << *it << std::endl;
    while (it != ite) {
      std::cout << *it << " ";
      ++it;
    }
    std::cout << std::endl << std::endl;
    MutantStack<int>::iterator it2 = mstack.begin();
    MutantStack<int>::iterator ite2 = mstack.end();
    ++it2;
    --it2;
    while (it2 != ite2) {
      --ite2;
      std::cout << *ite2 << " ";
    }
    std::cout << std::endl;
    std::cout << GREEN;
    std::cout << "mstack => std::stack<int> copy " << __FILE__ << " in "
              << __LINE__ << std::endl;
    std::cout << RESET;
    std::stack<int> s(mstack);
    while (!s.empty()) {
      std::cout << s.top() << " ";
      s.pop();
    }
  }
  std::cout << std::endl;

  // {
  //     std::cout << GREEN;
  //     std::cout << "Testing if iterators of MutantStack and std::list behave
  //     the same." << __FILE__ << " in " << __LINE__ << std::endl; std::cout <<
  //     RESET;

  //     MutantStack<int> mstack;
  //     std::list<int>   lst;
  //     for (int i=0; i < 10; ++i) {
  //         mstack.push(i);
  //         lst.push_back(i);
  //     }

  //     MutantStack<int>::iterator mIt = mstack.begin();
  //     std::list<int>::iterator lIt = lst.begin();

  //     bool areEqual = true;
  //     while (mIt != mstack.end() && lIt != lst.end()) {
  //         std::cout << *mIt << " == " << *lIt << ";    ";
  //         if (*mIt != *lIt) {
  //             areEqual = false;
  //             break;
  //         }
  //         ++mIt;
  //         ++lIt;
  //     }
  //     std::cout << std::endl;
  //     if (areEqual && mIt == mstack.end() && lIt == lst.end()) {
  //         std::cout << "Iterators of MutantStack and std::list behave the
  //         same." << std::endl;
  //     } else {
  //         std::cout << "Iterators of MutantStack and std::list do not behave
  //         the same." << std::endl;
  //     }
  // }

  // std::cout << "==========MutantStackList==========" << std::endl;
  // sleep(1);
  // {
  //     MutantStackList<int> mstackList;
  //     mstackList.push(5);
  //     mstackList.push(17);
  //     std::cout << mstackList.top() << std::endl;
  //     mstackList.pop();
  //     std::cout << mstackList.size() << std::endl;
  //     mstackList.push(3);
  //     mstackList.push(5);
  //     mstackList.push(737);
  //     for (int i = 0; i < N; i++) {
  //         mstackList.push(i);
  //     }
  //     mstackList.push(0);
  //     MutantStackList<int>::iterator itList = mstackList.begin();
  //     MutantStackList<int>::iterator iteList = mstackList.end();
  //     ++itList;
  //     --itList;
  //     while (itList != iteList)
  //     {
  //         std::cout << *itList << std::endl;
  //         ++itList;
  //     }
  //     MutantStackList<int>::iterator it2 = mstackList.begin();
  //     MutantStackList<int>::iterator ite2 = mstackList.end();
  //     ++it2;
  //     --it2;
  //     while (it2 != ite2)
  //     {
  //         std::cout << *ite2 << std::endl;
  //         --ite2;
  //     }
  //     std::stack<int, std::list<int> > sList(mstackList);
  // }
  // std::cout << "==========MutantStackVector==========" << std::endl;
  // sleep(1);
  // {
  //     MutantStackVector<int> mstackVector;
  //     mstackVector.push(5);
  //     mstackVector.push(17);
  //     std::cout << mstackVector.top() << std::endl;
  //     mstackVector.pop();
  //     std::cout << mstackVector.size() << std::endl;
  //     mstackVector.push(3);
  //     mstackVector.push(5);
  //     mstackVector.push(737);
  //     for (int i = 0; i < N; i++) {
  //         mstackVector.push(i);
  //     }
  //     mstackVector.push(0);
  //     MutantStackVector<int>::iterator itVector = mstackVector.begin();
  //     MutantStackVector<int>::iterator iteVector = mstackVector.end();
  //     ++itVector;
  //     --itVector;
  //     while (itVector != iteVector)
  //     {
  //     std::cout << *itVector << std::endl;
  //     ++itVector;
  //     }
  //     std::stack<int, std::vector<int> > sVector(mstackVector);
  //     MutantStackVector<int>::iterator it2 = mstackVector.begin();
  //     MutantStackVector<int>::iterator ite2 = mstackVector.end();
  //     ++it2;
  //     --it2;
  //     while (it2 != ite2)
  //     {
  //         std::cout << *ite2 << std::endl;
  //         --ite2;
  //     }
  // }
  return 0;
}
