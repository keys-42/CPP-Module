#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
# include <exception>
#include <algorithm>

class PmergeMe
{
    typedef std::vector<int>::iterator v_itr;
    typedef std::list<int>::iterator l_itr;
    private:
        std::vector<int>    vec_;
        std::list<int>      lst_;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe & r);
        ~PmergeMe();
        PmergeMe & operator= (const PmergeMe &other);

        void                        inputValidation(char **argv);
        void                        initContainer(char **argv);
        
        // Sorting related to list iterators
        // void                        mergeSortToList(std::list<int> &vec);
        std::list<int>                        mergeSortToList(std::list<int>::iterator begin, std::list<int>::iterator end);
        void                        mergeToList( std::list<int> &vec, std::list<int> &vec2, std::list<int> &vec3);
        void                        PairwiseComparisonToList();
        void                        RecursionToList();
        void                        InsertAtTheStartToList();
        std::list<int>::iterator    binarySearchToList( int key );
        void                        InsertionToList();
        void                        printToList();

        // Sorting related to vector iterators
        // void                        mergeSortToVec(std::vector<int> &vec);
        std::vector<int>            mergeSortToVec(v_itr begin, v_itr end);
        void                        mergeToVec( std::vector<int> &vec, std::vector<int> &vec2, std::vector<int> &vec3);
        void                        PairwiseComparisonToVec();
        void                        RecursionToVec();
        void                        InsertAtTheStartToVec();
        std::vector<int>::iterator  binarySearchToVec( int key );
        void                        InsertionToVec();
        void                        printToVec();
        template <typename T, typename ITR>
        void print(T c) {
            std::cout << std::endl << "-------------" << std::endl;
            for(ITR it = c.begin(); it != c.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl << "-------------" << std::endl;
        }
};

#endif
