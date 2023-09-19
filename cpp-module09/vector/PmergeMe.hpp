#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <vector>
# include <exception>
# include <algorithm>
# include <sstream>
# include <stdexcept>


class PmergeMe
{
    typedef std::vector<int>::const_iterator ConstIntvectorIter;
    typedef std::vector<int>::iterator IntvectorIter;

    typedef std::vector<std::vector<int>::const_iterator> ConstIteratorvector;
    typedef std::vector<std::vector<int>::const_iterator>::const_iterator ConstIteratorvectorIterator;

    struct UnpairedData {
        size_t length;
        int value;
        int position;
    };

    private:
        std::vector<int>          mainChain_;
    
    private:
        void    initContainer(int size, int numbers[]);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe & r);
        ~PmergeMe();
        PmergeMe & operator= (const PmergeMe &other);
 
    void FordJohnsonAlgorithm(int size, int numbers[]);
    void mergeInsertionSort(std::vector<int> & mainChain,int pairSize);
    // void spliceVector(std::vector<int>& dest, std::vector<int>& src, size_t start, size_t length);
    template <typename T>
    void vector_splice(
        std::vector<T>& target, 
        typename std::vector<T>::iterator position, 
        std::vector<T>& source, 
        typename std::vector<T>::iterator first, 
        typename std::vector<T>::iterator last)
    {
        target.insert(position, first, last);
        source.erase(first, last);
    }



    //pair
    bool    pairCompare( std::vector<int> & vec, int pairSize, int start );
    void    pairSwap( std::vector<int> & vec, int pairSize, int start );
    bool    hasPair(std::vector<int> & vec, int pairSize, size_t start );
    void    makePair( std::vector<int> & vec, std::vector<int> & subChain, int pairSize );

    //separate
    void    separateMainChainAndSubChain(std::vector<int> & mainChain, std::vector<int> & subChain, int pairSize);
    
    // first insert
    void    insertAtTheStart(std::vector<int> & mainChain, std::vector<int> & subChain, int pairSize);

    // insert
    void                        insertionFromSubIntoMain(std::vector<int> & mainChain, std::vector<int> & subChain, int pairSize, UnpairedData& unpair);
    int                         jacobsthalNumber(int n);
    int                         binarySearch(std::vector<int> & mainChain, int key,int pairSize, UnpairedData& unpair, int endpoint);
    bool                        isKey(std::vector<int> & vec, int index, int key);
    int                         lower_bound(std::vector<int> & vec, int key, int right);
    void                        insertSubChain(std::vector<int> & mainChain, int insertPosition, ConstIntvectorIter begin, ConstIntvectorIter end);






    template <typename T>
    typename std::vector<T>::iterator advanceTo(std::vector<T>& vec, size_t index) {
        if (index >= vec.size()) { return vec.end(); }

        typename std::vector<T>::iterator it = vec.begin();
        std::advance(it, index);
        return it;
    }
    template <typename T>
    typename std::vector<T>::const_iterator advanceIt(std::vector<T>& vec, typename std::vector<T>::const_iterator itr, size_t index) {

        for (size_t i=0; i< index ; ++i) {
            ++itr;
            if(itr == vec.end()) return vec.end();
        }
        return itr;
    }

    template <typename T>
    T getElementAtIndex(const std::vector<T>& vec, size_t index) {
        typename std::vector<T>::const_iterator it = vec.begin();
        for (size_t i = 0; i < index; ++i) {
            if (it == vec.end()) {
                throw std::out_of_range("Index out of bounds");
            }
            ++it;
        }

        if (it == vec.end()) {
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

                    if(index % (pairSize * 2) == 0) { std::cout << "[" ; }
                    std::cout << *it;
                    if(index % (pairSize * 2) == pairSize * 2 - 1 || it == std::prev(mainChain.end())) { std::cout << "]" ; }
                    if ( (index % (pairSize * 2) == pairSize - 1) && (it != std::prev(mainChain.end())) ) { std::cout << " | "; }
                    else { std::cout << "  "; }
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

        bool isSorted(const std::vector<int>& vec) {
            if (vec.empty()) {
                return true;
            }

            std::vector<int>::const_iterator it = vec.begin();
            std::vector<int>::const_iterator next_it = it;
            ++next_it;

            while (next_it != vec.end()) {
                if (*it > *next_it) {
                    return false;
                }
                ++it;
                ++next_it;
            }

            return true;
        }

};

#endif
