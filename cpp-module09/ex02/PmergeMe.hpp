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
    typedef std::vector<int>::const_iterator cv_itr;
    typedef std::vector<int>::iterator v_itr;
    typedef std::vector<v_itr>::iterator vi_itr;

    typedef std::list<int>::const_iterator cl_itr;
    typedef std::list<int>::iterator l_itr;

    private:
        std::vector<int>        v_mainChain_;
        std::list<int>          l_mainChain_;
    
    private:
        void                    initContainer(int size, int numbers[]);
        // Sorting related to list iterators
        // Sorting related to vector iterators
        // Sorting related to list iterators
        void mergeInsertionSort(std::vector<int> & mainChain,int pairSize);
        int     comparison(int pairSize, std::vector<int> & v, int start) ;
        void    swap(int pairSize, std::vector<int> & v, int start) ;
        int checkOverflow(int pairSize, std::vector<int> & v, int start) ;

        void    pairwiseComparison(int pairSize, std::vector<int> & v, std::vector<int> & tmp) ;

        /**
         * separate mainChain SubChain
        */
        void separateMainChainAndSubChain(std::vector<int> & v, std::vector<int> & subChain, int pairSize) ;
        /**
         * insert first subPair
        */

        void insertAtTheStart(std::vector<int> & mainChain, std::vector<int> & subChain, int pairSize) ;

        /**
         * insert
        */
        void insert(std::vector<int> & v, v_itr position, std::vector<int> & s, v_itr begin, v_itr end);

        bool isKey(std::vector<v_itr> iterators, int index, int key);

        v_itr lower_bound(std::vector<v_itr>& iterators, vi_itr begin, vi_itr end, int key, int right) ;
        v_itr   binarySearch(std::vector<int> & v, int key, int pairSize, int keyPosition);

        void insertionFromSubIntoMain(std::vector<int> & mainChain, std::vector<int> & subChain, int pairSize);


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

};

#endif
