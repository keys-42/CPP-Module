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
        void    inputValidation(char **argv);
        void    initContainer(char **argv);
        


        // Sorting related to vector iterators
        void    mergeSortToVec(std::vector<int> &vec);
        void    mergeToVec( std::vector<int> &vec, std::vector<int> &vec2, std::vector<int> &vec3);
        void    PairwiseComparisonToVec();
        void    RecursionToVec();
        void    InsertAtTheStartToVec();
        std::vector<int>::iterator binarySearchToVec( int key );
        void    InsertionToVec();
        void print();
        
};

#endif
