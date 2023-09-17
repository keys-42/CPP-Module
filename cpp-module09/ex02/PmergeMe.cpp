#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe & r): v_mainChain_(r.v_mainChain_), l_mainChain_(r.l_mainChain_) {};

PmergeMe::~PmergeMe() {};

PmergeMe & PmergeMe::operator= (const PmergeMe &other) {
    if( this != &other ) {
        this->v_mainChain_ = other.v_mainChain_;
        this->l_mainChain_ = other.l_mainChain_;
    }
    return *this;
}

typedef std::vector<int>::const_iterator cv_itr;
typedef std::vector<int>::iterator v_itr;
typedef std::vector<v_itr>::iterator vi_itr;

typedef std::list<int>::const_iterator cl_itr;
typedef std::list<int>::iterator l_itr;

/**
 * pair comparison
*/
int     PmergeMe::comparison(int pairSize, std::vector<int> & v, int start) {
    if(v.size() <= (pairSize + start))
        return -1;
    if(v[start] < v[pairSize+ start])
        return 1;
    return 0;
}

void    PmergeMe::swap(int pairSize, std::vector<int> & v, int start) {
    for(int i=0; i < pairSize; ++i) {
        std::iter_swap(v.begin() + start, v.begin() + start + pairSize);
        ++start;
    }
}

int PmergeMe::checkOverflow(int pairSize, std::vector<int> & v, int start) {
    size_t size = v.size() - 1;

    for(int i=0; i < pairSize; ++i) {
        if(start + pairSize > size)
            return true;
        ++start;
    }
    return false;
}

void    PmergeMe::pairwiseComparison(int pairSize, std::vector<int> & v, std::vector<int> & tmp) {
    for ( int i=0; i < v.size();) {
        if(checkOverflow(pairSize,v,i))
        {
            tmp.insert(tmp.begin(), v.begin() + i,v.end() );
            v.erase(v.begin() + i, v.end());
            // std::cout << std::endl << "tmp tmp pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
            
            // for ( v_itr it = tmp.begin(); it != tmp.end(); ++it ) {
            //     std::cout << *it << " ";
            // }
            // std::cout << std::endl << "tmp end: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
                break;
        }
        if(comparison(pairSize,v,i)) {
                swap(pairSize,v,i);
        }
        i+=pairSize;
        i+=pairSize;
    }
}

/**
 * separate mainChain SubChain
*/
void PmergeMe::separateMainChainAndSubChain(std::vector<int> & v, std::vector<int> & subChain, int pairSize) {
    int end = v.size();

    int over;
    int size= subChain.size();
    for ( int i=0; i < end;) {
        if(checkOverflow(pairSize,v,i))
        {
            over = i;
            for(int k=i; k<end;++k) {
                subChain.insert(subChain.end() - size, v[k]);
            }
            break;
        }
        i+=pairSize;
        for (int k=0; k<pairSize; ++k) {
            subChain.insert(subChain.end() - size, v[i + k]);
        }
        i+=pairSize;
    }
    
    int ep=0;
    v_itr it=v.begin(); 
    for ( ;it != v.end(); ++it) {
        if(ep == over)
            break;
        ep++;
    }
    v.erase(it,v.end());

    int beginPostion = pairSize;
    for ( ;; ) {
        v.erase(v.begin() + beginPostion, v.begin() + beginPostion + pairSize);
        if(v.begin() + beginPostion == v.end()) { break; }
        beginPostion += pairSize;
    }
}

/**
 * insert first subPair
*/

void PmergeMe::insertAtTheStart(std::vector<int> & mainChain, std::vector<int> & subChain, int pairSize) {
    mainChain.insert(mainChain.begin(), subChain.begin(), subChain.begin() + pairSize);
    subChain.erase(subChain.begin(), subChain.begin() + pairSize);
}

/**
 * insert
*/
void PmergeMe::insert(std::vector<int> & v, v_itr position, std::vector<int> & s, v_itr begin, v_itr end) {
    if(begin == end){
        v.insert(position, *begin);
        s.erase(begin);
        return;
    }
    v.insert(position, begin, end);
    s.erase(begin, end);
}

bool PmergeMe::isKey(std::vector<v_itr> iterators, int index, int key) {
    if (*(iterators[index]) >= key) return true;
    else return false;
}

v_itr PmergeMe::lower_bound(std::vector<v_itr>& iterators, vi_itr begin, vi_itr end, int key, int right) {
    int left = -1;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (isKey(iterators, mid, key)) right = mid;
        else left = mid;
    }

    return *(iterators.begin() + right);
}

v_itr   PmergeMe::binarySearch(std::vector<int> & v, int key, int pairSize, int keyPosition) {
    std::vector<v_itr> iterators;

    for (v_itr itr = v.begin(); itr != v.end(); itr += pairSize) {
        iterators.push_back(itr);
    }
    vi_itr begin = iterators.begin();
    vi_itr end = iterators.begin() + keyPosition;
    return lower_bound(iterators,begin, end, key, iterators.size());
}

void PmergeMe::insertionFromSubIntoMain(std::vector<int> & mainChain, std::vector<int> & subChain, int pairSize) {

    for ( ; !subChain.empty(); ) {
    #ifdef SORT
        std::cout << std::endl;
        std::cout << std::endl << "separateMainChain pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=mainChain.begin(); it != mainChain.end(); ++it){
            int index = std::distance(mainChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl << "separateSubChain pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=subChain.begin(); it != subChain.end(); ++it){
            int index = std::distance(subChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl;
    #endif
        v_itr it = binarySearch(mainChain, (*subChain.begin()), pairSize, 0);

        v_itr s_begin = subChain.begin();
        v_itr s_end = subChain.begin();
        if(subChain.size() < pairSize * 2) {
            s_end = subChain.end();
        } else {
            for (int i=0; i < pairSize; ++i) {
                ++s_end;
                if(s_end == subChain.end()) {
                    break;
                }
            }
        }

        insert(mainChain, it, subChain, s_begin, s_end);
    }
    #ifdef SORT
        std::cout << std::endl;
        std::cout << std::endl << "LastMainChain pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=mainChain.begin(); it != mainChain.end(); ++it){
            int index = std::distance(mainChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl << "LastSubChain pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=subChain.begin(); it != subChain.end(); ++it){
            int index = std::distance(subChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl;
    #endif
}

void PmergeMe::mergeInsertionSort(std::vector<int> & mainChain,int pairSize) {
    if(mainChain.size() / pairSize  <= 2) {
        #ifdef PAIR
            std::cout << std::endl;
            for(v_itr it=mainChain.begin(); it != mainChain.end(); ++it) {
                int index = std::distance(mainChain.begin(), it);
                if(index % (pairSize) == 0) std::cout << " [" ;
                std::cout << *it;
                if(index % (pairSize) == 0) std::cout << "] " ;
                std::cout << "  ";
            }
            std::cout << std::endl;
        #endif
        return ;
    } 
    #ifdef PAIR
        std::cout << std::endl;
        std::cout << std::endl << "pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=mainChain.begin(); it != mainChain.end(); ++it){
            int index = std::distance(mainChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl;
    #endif
    std::vector<int> subChain;
    pairwiseComparison(pairSize, mainChain,subChain);
    mergeInsertionSort(mainChain, pairSize * 2);

    separateMainChainAndSubChain(mainChain, subChain, pairSize);
    #ifdef SEPARATE
        std::cout << std::endl;
        std::cout << std::endl << "separateMainChain pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=mainChain.begin(); it != mainChain.end(); ++it){
            int index = std::distance(mainChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl << "separateSubChain pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=subChain.begin(); it != subChain.end(); ++it){
            int index = std::distance(subChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl;

    #endif
    insertAtTheStart(mainChain, subChain, pairSize);
    #ifdef INSERTATTHESTART
        std::cout << std::endl;
        std::cout << std::endl << "separateMainChain pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=mainChain.begin(); it != mainChain.end(); ++it){
            int index = std::distance(mainChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl << "separateSubChain pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=subChain.begin(); it != subChain.end(); ++it){
            int index = std::distance(subChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl;
    #endif
    insertionFromSubIntoMain(mainChain, subChain, pairSize);
    #ifdef SORT
        std::cout << std::endl;
        std::cout << std::endl << "separateMainChain pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=mainChain.begin(); it != mainChain.end(); ++it){
            int index = std::distance(mainChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl << "separateSubChain pairsize: ~" << (pairSize/2) << "~ line: " << __LINE__ << std::endl;
        for(v_itr it=subChain.begin(); it != subChain.end(); ++it){
            int index = std::distance(subChain.begin(), it);
            if(index % (pairSize) == 0) std::cout << " [" ;
            std::cout << *it;
            if(index % (pairSize) == 0) std::cout << "] " ;
            std::cout << "  ";
        }
        std::cout << std::endl;
    #endif
    subChain.clear();
}


void    PmergeMe::initContainer(int size, int numbers[]) {
    for (int i = 0; i < size; ++i) {
        v_mainChain_.push_back(numbers[i]);     
        l_mainChain_.push_back(numbers[i]);     
    }
}

void PmergeMe::FordJohnsonAlgorithm(int size, int numbers[]) {
    this->initContainer(size, numbers);
    mergeInsertionSort(this->v_mainChain_, 1);

    PmergeMe::print<std::vector<int>, v_itr>(this->v_mainChain_);
}