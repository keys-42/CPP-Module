#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <list>
# include <exception>
# include <algorithm>
# include <sstream>
# include <stdexcept>
# include <cstring>


class PmergeMe
{
    typedef std::list<int>::const_iterator ConstIntListIter;
    typedef std::list<int>::iterator IntListIter;

    typedef std::list<std::list<int>::const_iterator> ConstIteratorList;
    typedef std::list<std::list<int>::const_iterator>::const_iterator ConstIteratorListIterator;

    struct UnpairedData {
        size_t length;
        int value;
        int position;
    };

    private:
        std::list<int>          mainChain_;
    
    private:
        void    initContainer(int size, int numbers[]);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe & r);
        ~PmergeMe();
        PmergeMe & operator= (const PmergeMe &other);

    void FordJohnsonAlgorithm(int size, int numbers[]);
    void mergeInsertionSort(std::list<int> & mainChain,int pairSize);


    //pair
    bool    pairCompare( std::list<int> & lst, int pairSize, int start );
    void    pairSwap( std::list<int> & lst, int pairSize, int start );
    bool    hasPair(std::list<int> & lst, int pairSize, size_t start );
    void    makePair( std::list<int> & lst, std::list<int> & subChain, int pairSize );

    //separate
    void    separateMainChainAndSubChain(std::list<int> & mainChain, std::list<int> & subChain, int pairSize);
    
    // first insert
    void    insertAtTheStart(std::list<int> & mainChain, std::list<int> & subChain, int pairSize);

    // insert
    void                        insertionFromSubIntoMain(std::list<int> & mainChain, std::list<int> & subChain, int pairSize, UnpairedData& unpair);
    int                         jacobsthalNumber(int n);
    int                         binarySearch(std::list<int> & mainChain, int key,int pairSize, UnpairedData& unpair, int endpoint);
    bool                        isKey(std::list<int> & lst, int index, int key);
    int                         lower_bound(std::list<int> & lst, int key, int right);
    void                        insertSubChain(std::list<int> & mainChain, int insertPosition, ConstIntListIter begin, ConstIntListIter end);



    //utils
    template <typename T>
    typename std::list<T>::iterator getIteratorAt(std::list<T>& lst, size_t index) {
        if (index >= lst.size()) { return lst.end(); }

        typename std::list<T>::iterator it = lst.begin();
        std::advance(it, index);
        return it;
    }

    template <typename T>
    typename std::list<T>::const_iterator getConstIteratorAt(const std::list<T>& lst, size_t index) {
        if (index >= lst.size()) { return lst.end(); }

        typename std::list<T>::const_iterator it = lst.begin();
        std::advance(it, index);
        return it;
    }

    template <typename T>
    typename std::list<T>::const_iterator advanceTo(std::list<T>& lst, typename std::list<T>::const_iterator itr, size_t index) {
        for (size_t i=0; i< index ; ++i) {
            ++itr;
            if(itr == lst.end()) return lst.end();
        }
        return itr;
    }
    template <typename T>
    T getElementAtIndex(const std::list<T>& lst, size_t index) {
    typename std::list<T>::const_iterator it = lst.begin();
        for (size_t i = 0; i < index && it != lst.end(); ++i) {
            ++it;
        }

        if (it == lst.end()) {
            throw std::out_of_range("Index out of bounds");
        }

        return *it;
    }

    //debug
    public:
        template <typename T, typename Iter>
        static void print(T t) {
            for(Iter it=t.begin(); it != t.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
                template <typename T>
        void printDebug(const T& mainChain, const T& subChain, int pairSize, const char* message) {
            typedef typename T::const_iterator Iterator;
            if(strncmp(message,"B",1) == 0)
                std::cout << std::endl << "========================================================================================" << std::endl;
            std::cout << std::endl << message << " pairsize: " << pairSize << "   ( " << (pairSize*2) << " )" << std::endl;
            if(!mainChain.empty()) {
                std::cout << "mainChain" << std::endl;
                for(Iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
                    int index = std::distance(mainChain.begin(), it);

                    typename std::list<T>::iterator prevIt = mainChain.end();
                    --prevIt;

                    if(index % (pairSize * 2) == 0) { std::cout << "[" ; }
                    std::cout << *it;
                    if(index % (pairSize * 2) == pairSize * 2 - 1 || it == prevIt) { std::cout << "]" ; }
                    if ( (index % (pairSize * 2) == pairSize - 1) && (it != prevIt) ) { std::cout << " | "; }
                    else { std::cout << "  "; }

                    // if(index % (pairSize * 2) == 0) { std::cout << "[" ; }
                    // std::cout << *it;
                    // if(index % (pairSize * 2) == pairSize * 2 - 1 || it == std::prev(mainChain.end())) { std::cout << "]" ; }
                    // if ( (index % (pairSize * 2) == pairSize - 1) && (it != std::prev(mainChain.end())) ) { std::cout << " | "; }
                    // else { std::cout << "  "; }
                }
                std::cout << std::endl;
            }

            if(!subChain.empty()) {
                std::cout << "subChain" << std::endl;
                for(Iterator it = subChain.begin(); it != subChain.end(); ++it) {
                    int index = std::distance(subChain.begin(), it);
                    if( (index % (pairSize) == 0) && (it != subChain.begin()) ) { 
                        std::cout << " | " << *it;
                    } else {
                        std::cout << " " << *it << " ";
                    }
                }
                std::cout << std::endl;
            }
            if(strncmp(message,"A",1) == 0)
                std::cout << std::endl << "========================================================================================" << std::endl;
        }

        bool isSorted(const std::list<int>& lst) {
            if (lst.empty()) {
                return true;
            }

            std::list<int>::const_iterator it = lst.begin();
            std::list<int>::const_iterator next_it = it;
            ++next_it;

            while (next_it != lst.end()) {
                if (*it > *next_it) {
                    return false;
                }
                ++it;
                ++next_it;
            }

            return true;
        }

        void tset(std::list<int> & l, std::list<int> & s);

};

#endif
