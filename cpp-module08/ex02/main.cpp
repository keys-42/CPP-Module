#include "MutantStack.hpp"
#include "MutantStackList.hpp"
#include "MutantStackVector.hpp"
#include <unistd.h>
#define N 1000000

int main()
{
    std::cout << "==========MutantStack==========" << std::endl;
    sleep(1);
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        for(int i = 0; i < N; i++) { mstack.push(i); }
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        MutantStack<int>::iterator it2 = mstack.begin();
        MutantStack<int>::iterator ite2 = mstack.end();
        ++it2;
        --it2;
        while (it2 != ite2)
        {
            std::cout << *ite2 << std::endl;
            --ite2;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "==========MutantStackList==========" << std::endl;
    sleep(1);
    {
        MutantStackList<int> mstackList;
        mstackList.push(5);
        mstackList.push(17);
        std::cout << mstackList.top() << std::endl;
        mstackList.pop();
        std::cout << mstackList.size() << std::endl;
        mstackList.push(3);
        mstackList.push(5);
        mstackList.push(737);
        for (int i = 0; i < N; i++) {
            mstackList.push(i);
        }
        mstackList.push(0);
        MutantStackList<int>::iterator itList = mstackList.begin();
        MutantStackList<int>::iterator iteList = mstackList.end();
        ++itList;
        --itList;
        while (itList != iteList)
        {
            std::cout << *itList << std::endl;
            ++itList;
        }
        MutantStackList<int>::iterator it2 = mstackList.begin();
        MutantStackList<int>::iterator ite2 = mstackList.end();
        ++it2;
        --it2;
        while (it2 != ite2)
        {
            std::cout << *ite2 << std::endl;
            --ite2;
        }
        std::stack<int, std::list<int> > sList(mstackList);
    }
    std::cout << "==========MutantStackVector==========" << std::endl;
    sleep(1);
    {
        MutantStackVector<int> mstackVector;
        mstackVector.push(5);
        mstackVector.push(17);
        std::cout << mstackVector.top() << std::endl;
        mstackVector.pop();
        std::cout << mstackVector.size() << std::endl;
        mstackVector.push(3);
        mstackVector.push(5);
        mstackVector.push(737);
        for (int i = 0; i < N; i++) {
            mstackVector.push(i);
        }
        mstackVector.push(0);
        MutantStackVector<int>::iterator itVector = mstackVector.begin();
        MutantStackVector<int>::iterator iteVector = mstackVector.end();
        ++itVector;
        --itVector;
        while (itVector != iteVector)
        {
        std::cout << *itVector << std::endl;
        ++itVector;
        }
        std::stack<int, std::vector<int> > sVector(mstackVector);
        MutantStackVector<int>::iterator it2 = mstackVector.begin();
        MutantStackVector<int>::iterator ite2 = mstackVector.end();
        ++it2;
        --it2;
        while (it2 != ite2)
        {
            std::cout << *ite2 << std::endl;
            --ite2;
        }
    }

    return 0;
}
