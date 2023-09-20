#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip> 
# include <list>
# include <vector>
# include <algorithm>
# include <exception>
# include <sstream>
# include <ctime>
# include <cstring>


class PmergeMe
{
    typedef std::list<int>::const_iterator ConstIntListIterator;

    typedef std::vector<int>::iterator IntVecIterator;
    typedef std::vector<int>::const_iterator ConstIntVecIterator;

    struct UnpairedElemenat {
        size_t length;
        int value;
        int position;
    };
    typedef enum 
    {
        LIST,
        VECTOR,
    } E_Type;
    
    private:
        std::list<int>              List_mainChain_;
        std::vector<int>            Vector_mainChain_;
        int size_;
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe & r);
        ~PmergeMe();
        PmergeMe & operator= (const PmergeMe &other);

        std::list<int> getList() const;
        std::vector<int> getVector() const;
        void printClock(std::clock_t start, std::clock_t end, E_Type type);
    
        template <typename T>
        void FordJohnsonAlgorithm(int size, T numbers) {
            this->size_ = size;
            try {
                this->initContainer(size, numbers);
            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
                std::exit(1);
            }


            PmergeMe::printContainer(List_mainChain_);
            std::cout << std::endl;
            std::clock_t start;
            std::clock_t end;

            try {
                start = std::clock();
                mergeInsertionSort(this->List_mainChain_, 1);
                end = std::clock();
                printClock(start, end, LIST);
            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
                std::exit(1);
            }
            try {
                start = std::clock();
                mergeInsertionSort(this->Vector_mainChain_, 1);
                end = std::clock();
                printClock(start, end, VECTOR);

            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
                std::exit(1);
            }
            std::cout << "after: "; 
            PmergeMe::printContainer(List_mainChain_);
        }
    
    private:
        int                         stoi(const std::string& str);
        void                        initContainer(int size, int numbers[]);
        void                        initContainer(int size, char* numbers);
        void                        initContainer(int size, char* numbers[]);
        void                        initContainer(int size, std::string numbers);
        void                        initContainer(int size, std::string numbers[]);
        int                         calculateJacobsthalNumber(int n);

    /**
     * list
    */
        //processPairs
        bool                        shouldSwapPairs(const std::list<int>& lst, int pairSize, int startIndex);
        void                        swapPairs(std::list<int>& lst, int pairSize, int startIndex);
        bool                        isPairPresent(const std::list<int>& lst, int pairSize, size_t startIndex);
        void                        processPairs(std::list<int>& lst, std::list<int>& subChain, int pairSize, UnpairedElemenat & unpairedData);

        //splitIntoMainAndSubChains
        void                        splitIntoMainAndSubChains(std::list<int>& mainChain, std::list<int>& subChain, int pairSize);
    
        // first insert
        void                        prependSubchainToMain(std::list<int>& mainChain, std::list<int>& subChain, int pairSize);

        // insert
        void                        mergeSubIntoMain(std::list<int>& mainChain, std::list<int>& subChain, int pairSize, UnpairedElemenat& unpairedData);
        int                         lower_bound(std::list<int> & mainChain, int key,int pairSize, UnpairedElemenat& unpairedData, int endpoint);
        void                        createComparisonListFromMainChain(std::list<int>& lst, std::list<int>& mainChain, int pairSize, UnpairedElemenat& unpairedData, int endpoint);
        bool                        elementExceedsKey(std::list<int>& lst, int index, int key);
        int                         find_lower_bound(std::list<int> & lst, int key);
        void                        insertSubChain(std::list<int> & mainChain, int insertPosition, ConstIntListIterator begin, ConstIntListIterator end);
        void                        insertSegmentToMainChain(std::list<int>& mainChain, std::list<int>& subChain, int segmentStart, int segmentEnd, int insertionPoint, int pairSize);
    /**
     * vector
    */
        //processPairs
        bool                        shouldSwapPairs(const std::vector<int>& vec, int pairSize, int startIndex);
        void                        swapPairs(std::vector<int>& vec, int pairSize, int startIndex);
        bool                        isPairPresent(const std::vector<int>& vec, int pairSize, size_t startIndex);
        void                        processPairs(std::vector<int>& vec, std::vector<int>& subChain, int pairSize, UnpairedElemenat & unpairedData);

        //splitIntoMainAndSubChains
        void                        splitIntoMainAndSubChains(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize);
        
        // first insert
        void                        prependSubchainToMain(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize);
        
        // insert
        void                        mergeSubIntoMain(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize, UnpairedElemenat& unpairedData);
        int                         lower_bound(std::vector<int> & mainChain, int key,int pairSize, UnpairedElemenat& unpairedData, int endpoint);
        void                        createComparisonVectorFromMainChain(std::vector<int>& lst, std::vector<int>& mainChain, int pairSize, UnpairedElemenat& unpairedData, int endpoint);
        bool                        elementExceedsKey(std::vector<int>& lst, int index, int key);
        int                         find_lower_bound(std::vector<int> & lst, int key);
        void                        insertSubChain(std::vector<int> & mainChain, int insertPosition, ConstIntVecIterator begin, ConstIntVecIterator end);
        void                        insertSegmentToMainChain(std::vector<int>& mainChain, std::vector<int>& subChain, int segmentStart, int segmentEnd, int insertionPoint, int pairSize);


        template <typename T>
        void mergeInsertionSort(T & mainChain,int pairSize) {
            if (mainChain.size() <= 2 * static_cast<size_t>(pairSize)) {
                if(mainChain.size()  <= static_cast<size_t>(pairSize)) return;
                if(!shouldSwapPairs(mainChain, pairSize, 0)) { swapPairs(mainChain, pairSize, 0);}
                return ; 
            } 
            
            T subChain;
            UnpairedElemenat unpairedData;
            processPairs(mainChain, subChain, pairSize, unpairedData);
            
            mergeInsertionSort(mainChain, pairSize * 2);

            splitIntoMainAndSubChains(mainChain, subChain, pairSize);

            prependSubchainToMain(mainChain, subChain, pairSize);

            mergeSubIntoMain(mainChain, subChain, pairSize, unpairedData);
        }
    
    
    //utils
    private:
        template <typename T>
        typename std::vector<T>::iterator getIteratorAt(std::vector<T>& vec, size_t index) {
            if (index >= vec.size()) { return vec.end(); }

            typename std::vector<T>::iterator it = vec.begin();
            it += index;
            return it;
        }

        template <typename T>
        typename std::list<T>::iterator getIteratorAt(std::list<T>& lst, size_t index) {
            if (index >= lst.size()) { return lst.end(); }

            typename std::list<T>::iterator it = lst.begin();
            std::advance(it, index);
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
        typename std::list<T>::const_iterator getConstIteratorAt(const std::list<T>& lst, size_t index) {
            if (index >= lst.size()) { return lst.end(); }

            typename std::list<T>::const_iterator it = lst.begin();
            std::advance(it, index);
            return it;
        }

        template <typename T>
        typename std::vector<T>::const_iterator advanceTo(std::vector<T>& vec, typename std::vector<T>::const_iterator itr, size_t index) {
            if (itr + index < vec.end()) {
                return itr + index;
            } else {
                return vec.end();
            }
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
        T getElementAtIndex(const std::vector<T>& vec, size_t index) {
            if (index >= vec.size()) { throw std::out_of_range("Index out of bounds"); }

            typename std::vector<T>::const_iterator it = vec.begin();
            it += index;
            return *it;
        }

        template <typename T>
        T getElementAtIndex(const std::list<T>& lst, size_t index) {
            if (index >= lst.size()) { throw std::out_of_range("Index out of bounds"); }

            typename std::list<T>::const_iterator it = getConstIteratorAt(lst, index);

            return *it;
        }

        public:
        template <typename T>
        static void printContainer(const T& container) {
            for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
                std::cout << *it << " ";
            }
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


};

#endif
