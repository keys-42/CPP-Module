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
# include <cstring>


class PmergeMe
{
    typedef std::vector<int>::iterator IntVecIterator;
    typedef std::vector<int>::const_iterator ConstIntVecIterator;

    typedef std::vector<IntVecIterator> VecOfIntVecIterator;
    typedef std::vector<ConstIntVecIterator> VecOfConstIntVecIterator;

    typedef VecOfIntVecIterator::iterator VecOfIntVecIteratorIter;
    typedef VecOfConstIntVecIterator::const_iterator ConstVecOfConstIntVecIteratorIter;


    struct UnpairedElemenat {
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

        bool shouldSwapPairs(const std::vector<int>& vec, int pairSize, int startIndex);
        void swapPairs(std::vector<int>& vec, int pairSize, int startIndex);
        bool isPairPresent(const std::vector<int>& vec, int pairSize, size_t startIndex);
        void processPairs(std::vector<int>& vec, std::vector<int>& subChain, int pairSize, UnpairedElemenat & unpairedData);

        void splitIntoMainAndSubChains(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize);
        void prependSubchainToMain(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize);
        
            // insert
    void                        mergeSubIntoMain(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize, UnpairedElemenat& unpairedData);
    int                         calculateJacobsthalNumber(int n);
    int                         lower_bound(std::vector<int> & mainChain, int key,int pairSize, UnpairedElemenat& unpairedData, int endpoint);
    void                        createComparisonVectorFromMainChain(std::vector<int>& lst, std::vector<int>& mainChain, int pairSize, UnpairedElemenat& unpairedData, int endpoint);
    bool                        elementExceedsKey(std::vector<int>& lst, int index, int key);
    int                         find_lower_bound(std::vector<int> & lst, int key);
    void                        insertSubChain(std::vector<int> & mainChain, int insertPosition, ConstIntVecIterator begin, ConstIntVecIterator end);
    void                        insertSegmentToMainChain(std::vector<int>& mainChain, std::vector<int>& subChain, int segmentStart, int segmentEnd, int insertionPoint, int pairSize);
        //utils
        template <typename T>
        typename std::vector<T>::iterator getIteratorAt(std::vector<T>& vec, size_t index) {
            if (index >= vec.size()) { return vec.end(); }

            typename std::vector<T>::iterator it = vec.begin();
            it += index;
            return it;
        }

        template <typename T>
        typename std::vector<T>::const_iterator getConstIteratorAt(const std::vector<T>& vec, size_t index) {
            if (index >= vec.size()) { return vec.end(); }

            typename std::vector<T>::const_iterator it = vec.begin();
            it += index;
            return it;
        }

        template <typename T>
        typename std::vector<T>::const_iterator advanceTo(std::vector<T>& vec, typename std::vector<T>::const_iterator itr, size_t index) {
            if (itr + index < vec.end()) {
                return itr + index;
            } else {
                return vec.end();
            }
            // for (size_t i=0; i< index ; ++i) {
            //     ++itr;
            //     if(itr == vec.end()) return vec.end();
            // }
            // return itr;
        }
        template <typename T>
        T getElementAtIndex(const std::vector<T>& vec, size_t index) {
            if (index >= vec.size()) { throw std::out_of_range("Index out of bounds"); }

            typename std::vector<T>::const_iterator it = vec.begin();
            it += index;
            return *it;
        }











        template <typename T>
        void printDebug(const std::vector<T>& mainChain, const std::vector<T>& subChain, int pairSize, const char* message) {
            typedef typename std::vector<T>::const_iterator Iterator;
            
            if(strncmp(message,"B",1) == 0)
                std::cout << std::endl << "========================================================================================" << std::endl;
            
            std::cout << std::endl << message << " pairsize: " << pairSize << "   ( " << (pairSize*2) << " )" << std::endl;
            
            if(!mainChain.empty()) {
                std::cout << "mainChain" << std::endl;
                for(Iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
                    int index = std::distance(mainChain.begin(), it);

                    Iterator prevIt = mainChain.end();
                    --prevIt;

                    if(index % (pairSize * 2) == 0) { std::cout << "[" ; }
                    std::cout << *it;
                    if(index % (pairSize * 2) == pairSize * 2 - 1 || it == prevIt) { std::cout << "]" ; }
                    if ( (index % (pairSize * 2) == pairSize - 1) && (it != prevIt) ) { std::cout << " | "; }
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



};

#endif
