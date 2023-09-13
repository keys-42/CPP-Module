#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe & r): vec_(r.vec_), lst_(r.lst_) {};

PmergeMe::~PmergeMe() {};

PmergeMe & PmergeMe::operator= (const PmergeMe &other) {
    if( this != &other ) {
        this->vec_ = other.vec_;
        this->lst_ = other.lst_;
    }
    return *this;
}

void    PmergeMe::inputValidation(char **argv) {
    int i = 0;
    std::string s;
    while( argv[i] ) {
        s = static_cast<std::string>(argv[i]);
        if(s.size() != 1)
            throw std::runtime_error("error");
        if( !isdigit(s[0]) )
            throw std::runtime_error("error");
        i++;
    }
}

void    PmergeMe::initContainer(char **argv) {
    int i = 0;
    int n;

    while(argv[i]) {
        n = argv[i][0] - '0';
        vec_.push_back(n);
        lst_.push_back(n);
        i++;
    }    
}

/**
 * Sorting related to list iterators
*/
void    PmergeMe::PairwiseComparisonToList() {
    l_itr tmp;

    for(l_itr it = lst_.begin(); it != lst_.end(); ++it) {
        tmp = it++;
        if(it == lst_.end())
            break;
        if(*tmp  < *it ) {
            l_itr prev_it = it;
            --prev_it;
            std::iter_swap(prev_it, it);
        }
    }
}

void PmergeMe::mergeToList( std::list<int> &lst, std::list<int> &lst2, std::list<int> &lst3) {

    std::list<int>::iterator it2 = lst2.begin();
    std::list<int>::iterator it3 = lst3.begin();
    
    while ( it2 != lst2.end() && it3 != lst3.end() ) {
        if( *it2 < *it3 ) {
            lst.push_back(*it2++);
        } else {
            lst.push_back(*it3++);
        }
    } 

    while(it2 != lst2.end()) lst.push_back(*it2++);
    while(it3 != lst3.end()) lst.push_back(*it3++);
}

std::list<int> PmergeMe::mergeSortToList(std::list<int>::iterator begin, std::list<int>::iterator end) {
    std::list<int>::difference_type size = std::distance(begin, end);
    if(size <= 2) {
        return std::list<int>(begin, end);
    }
    std::list<int>::difference_type mid = size / 2;
    if(mid % 2 == 1)
        mid++;

    std::list<int>::iterator middle = begin;
    std::advance(middle, mid);

    std::list<int> left = mergeSortToList(begin, middle);
    std::list<int> right = mergeSortToList(middle, end);
    
    std::list<int> result;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(result));
    
    return result;
}

void    PmergeMe::RecursionToList() {
    int flag[2] = {0, 0};
    if ( (lst_.size() % 2) == 1 ){
        flag[0] = 1;
        flag[1] = lst_.back();
        lst_.pop_back();
    }
    l_itr begin = lst_.begin();
    l_itr end = lst_.end();
    lst_ = mergeSortToList(begin, end);
    if(flag[0])
        lst_.push_back(flag[1]);
}

void    PmergeMe::InsertAtTheStartToList() {
    l_itr it = lst_.begin();
    std::iter_swap( lst_.begin() , ++it );
}

std::list<int>::iterator PmergeMe::binarySearchToList( int key ) {
    return std::lower_bound(lst_.begin(), lst_.end(), key);
}

void    PmergeMe::InsertionToList() {
    std::list<int> small;

    l_itr it = lst_.begin();
    ++it; ++it; ++it;

    for( ; it != lst_.end(); ) {
    small.push_back(*it);
    lst_.erase(it++);

    if(it == lst_.end()) break;
    else {
        l_itr next_it = it;
        ++next_it;
        if( next_it == lst_.end() ) {
                small.push_back(*it);
                lst_.erase(it);
                break;
            }
        }
        ++it;
    }

    for (l_itr it = small.begin(); it != small.end(); ++it) {
        l_itr result = binarySearchToList(*it);
        lst_.insert(result,*it);
    }
}    

void PmergeMe::printToList() {
    for(l_itr it = lst_.begin(); it != lst_.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/**
 *  Sorting related to vector iterators
*/
void    PmergeMe::PairwiseComparisonToVec() {
    v_itr tmp;

    for(v_itr it = vec_.begin(); it != vec_.end(); ++it) {
        tmp = it++;
        if(it == vec_.end())
            break;
        if(*tmp  < *it )
            std::iter_swap(it - 1, it);
    }
}

void PmergeMe::mergeToVec( std::vector<int> &vec, std::vector<int> &vec2, std::vector<int> &vec3) {

    std::size_t s2 = vec2.size();
    std::size_t s3 = vec3.size();
    std::size_t p2 = 0;
    std::size_t p3 = 0;
    
    while ( p2 < s2  && p3 < s3 ) {
        if( vec2.at(p2) < vec3.at(p3)) {
            vec.push_back(vec2.at(p2++));
        } else {
            vec.push_back(vec3.at(p3++));
        }
    } 

    while(p2 < s2) vec.push_back(vec2.at(p2++));
    while(p3 < s3) vec.push_back(vec3.at(p3++));
}

std::vector<int> PmergeMe::mergeSortToVec(v_itr begin, v_itr end) {
    std::vector<int>::difference_type size = std::distance(begin, end);
    if(size <= 2) {
        return std::vector<int>(begin, end);
    }
    std::vector<int>::difference_type mid = size / 2;
    if(mid % 2 == 1)
        mid++;
    std::vector<int> result;
    result.reserve(size);

    std::vector<int> left = mergeSortToVec(begin, begin + mid);
    std::vector<int> right = mergeSortToVec(begin + mid, end);
    
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(result));
    
    return result;
}


void    PmergeMe::RecursionToVec() {
    int flag[2] = {0, 0};
    if ( (vec_.size() % 2) == 1 ){
        flag[0] = 1;
        flag[1] = vec_.back();
        vec_.pop_back();
    }
    v_itr begin = vec_.begin();
    v_itr end = vec_.end();
    vec_ = mergeSortToVec(begin, end);
    if(flag[0])
        vec_.push_back(flag[1]);
}

void    PmergeMe::InsertAtTheStartToVec() {
    std::iter_swap( vec_.begin() , vec_.begin() + 1 );
}

std::vector<int>::iterator PmergeMe::binarySearchToVec( int key ) {
    return std::lower_bound(vec_.begin(), vec_.end(), key);
}

void    PmergeMe::InsertionToVec() {
    std::vector<int> small;

    v_itr it = vec_.begin();
    ++it; ++it; ++it;
    for( ; it != vec_.end(); ) {
        small.push_back(*it);
        vec_.erase(it);
        if(it == vec_.end()) break;
        else if( (it + 1) == vec_.end() ) {
            small.push_back(*it);
            vec_.erase(it);
            break;
        }
        ++it;
    }

    for (v_itr it = small.begin(); it != small.end(); ++it) {
        v_itr result = binarySearchToVec(*it);
        vec_.insert(result,*it);
    }
}    

void PmergeMe::printToVec() {
    for(v_itr it = vec_.begin(); it != vec_.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
