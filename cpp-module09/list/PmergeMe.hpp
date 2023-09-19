#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <exception>
# include <algorithm>
# include <sstream>


class PmergeMe
{
    typedef std::list<int>::const_iterator cv_itr;
    typedef std::list<int>::iterator v_itr;
    typedef std::list<v_itr>::iterator vi_itr;

    typedef std::list<int>::const_iterator cl_itr;
    typedef std::list<int>::iterator l_itr;

    private:
        std::list<int>        v_mainChain_;
        std::list<int>          l_mainChain_;
    
    private:
        void                    initContainer(int size, int numbers[]);
        // Sorting related to list iterators
        // Sorting related to vector iterators
        // Sorting related to list iterators
        void mergeInsertionSort(std::list<int> & mainChain,int pairSize);
        int     comparison(int pairSize, std::list<int> & v, int start) ;
        void    swap(int pairSize, std::list<int> & v, int start) ;
        int checkOverflow(int pairSize, std::list<int> & v, int start) ;

        void    pairwiseComparison(int pairSize, std::list<int> & v, std::list<int> & tmp) ;

        /**
         * separate mainChain SubChain
        */
        void separateMainChainAndSubChain(std::list<int> & v, std::list<int> & subChain, int pairSize) ;
        /**
         * insert first subPair
        */

        void insertAtTheStart(std::list<int> & mainChain, std::list<int> & subChain, int pairSize) ;

        /**
         * insert
        */

        bool isKey(std::list<v_itr> iterators, int index, int key);

        v_itr lower_bound(std::list<v_itr>& iterators, vi_itr begin, vi_itr end, int key, int right) ;
        v_itr   binarySearch(std::list<int> & v, int key, int pairSize, int keyPosition);

        void insertionFromSubIntoMain(std::list<int> & mainChain, std::list<int> & subChain, int pairSize);
        int jacobsthalNumber(int n);
        void testttest(std::list<int>::const_iterator i, std::list<int>::const_iterator end, int q );
        template<typename T>
        typename std::list<T>::iterator advance_to(std::list<T>& lst, size_t index) {
            typename std::list<T>::iterator it = lst.begin();
            std::advance(it, index);
            return it;
        }
        template<typename T>
        T get_value_at(const std::list<T>& lst, size_t index) {
            typename std::list<T>::const_iterator it = lst.begin();
            std::advance(it, index);
            // if (it != lst.end()) {
            return *it;
            // }
            // return default_value;
        }


    public:
        PmergeMe();
        PmergeMe(const PmergeMe & r);
        ~PmergeMe();
        PmergeMe & operator= (const PmergeMe &other);
        void FordJohnsonAlgorithm(int size, int numbers[]);
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

            // if(pairSize  < 4 ) return;

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
        }

};

#endif
