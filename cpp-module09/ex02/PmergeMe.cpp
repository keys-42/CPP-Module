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

void    PmergeMe::PairwiseComparison() {
    v_itr tmp;

    for(v_itr it = vec_.begin(); it != vec_.end(); ++it) {
        tmp = it++;
        if(it == vec_.end())
            break;
        if(*tmp  < *it )
            std::iter_swap(it - 1, it);
    }
}

void PmergeMe::merge( std::vector<int> &vec, std::vector<int> &vec2, std::vector<int> &vec3) {

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

void PmergeMe::mergeSort(std::vector<int> &vec) {
    if (vec.size() <= 2)
        return;
    v_itr  it = vec.begin() + vec.size() / 2;
    std::vector<int> vec2(vec.begin(), it);
    std::vector<int> vec3(it , vec.end());

    mergeSort(vec2);
    mergeSort(vec3);

    vec.clear();
    merge(vec, vec2, vec3);
}

void    PmergeMe::Recursion() {

    if ( (vec_.size() % 2) == 1 ){
        int last = vec_.back();
        vec_.pop_back();
        mergeSort(vec_);
        vec_.push_back(last);
        return;
    }
    mergeSort(vec_);
}

void    PmergeMe::Insertion() {
    vec_.insert( vec_.begin() , *(vec_.begin() + 1) );
    vec_.erase( vec_.begin() + 2 );
    if( vec_.size() < 4 )
        return;
    
    v_itr it = vec_.begin() + 3;

    std::cout << "test" << std::endl;
    for ( ; it != vec_.end();) {
        
    }
    // for( ; it != vec_.end(); it += 2 ) {
    //     v_itr t = it - 1;
    //     for ( ;; ) {
    //         this->print();
    //         std::cout << "t:" << *t << " it:" <<*it <<std::endl;
    //         if ( *t < *it ) {
    //             vec_.insert( t, *it );
    //             vec_.erase(it + 1);
    //             break;
    //         }
    //         if ( t == vec_.begin() ) {
    //             vec_.insert( t, *it );
    //             vec_.erase(it + 1);
    //             break;
    //         }
    //         t -= 2;
    //     }
       
    // }
}

void PmergeMe::print() {
    for(v_itr it = vec_.begin(); it != vec_.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
