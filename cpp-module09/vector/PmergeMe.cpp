#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe & r): mainChain_(r.mainChain_) {};

PmergeMe::~PmergeMe() {};

PmergeMe & PmergeMe::operator= (const PmergeMe &other) {
    if( this != &other ) {
        this->mainChain_ = other.mainChain_;
    }
    return *this;
}


typedef std::vector<int>::const_iterator ConstIntvectorIter;
typedef std::vector<int>::iterator IntvectorIter;

typedef std::vector<std::vector<int>::const_iterator> ConstIteratorvector;
typedef std::vector<std::vector<int>::const_iterator>::const_iterator ConstIteratorvectorIterator;





/**
 * pair comparison
*/
bool     PmergeMe::pairCompare( std::vector<int> & vec, int pairSize, int start ) {
    if( getElementAtIndex(vec, start) < getElementAtIndex(vec,start + pairSize) )
        return 1;
    return 0;
}

void    PmergeMe::pairSwap( std::vector<int> & vec, int pairSize, int start) {
    std::vector<int>::iterator left = advanceTo(vec, start);
    std::vector<int>::iterator left_end = advanceTo(vec, start + pairSize);

    std::vector<int>::iterator right = left_end;
    std::vector<int>::iterator right_end = advanceTo(vec, start + 2 * pairSize);

    std::vector<int> tmp(right, right_end);

    vec.erase(right, right_end);
    vec.insert(left, tmp.begin(), tmp.end());
    // std::vector<int>::iterator left = advanceTo(vec, start);
    // std::vector<int>::iterator left_end = advanceTo(vec, start + pairSize);

    // std::vector<int>::iterator right = left_end;
    // std::vector<int>::iterator right_end = advanceTo(vec, start + 2 * pairSize);

    // std::vector<int> tmp;
    // tmp.splice(tmp.begin(), vec, right, right_end);
    // // spliceVector(tmp,vec,right,right_end);

    // vec.splice(right, vec, left, left_end);
    // vec.splice(left, tmp, tmp.begin(), tmp.end());
}

bool PmergeMe::hasPair(std::vector<int> & vec, int pairSize, size_t start) {
    if(advanceTo(vec,start + pairSize + pairSize - 1) == vec.end())
        return false;
    return true;
}

void    PmergeMe::makePair(std::vector<int> & vec, std::vector<int> & subChain, int pairSize) {

    for ( size_t i=0; i < vec.size(); ) {

        if( ! hasPair(vec, pairSize,i) )
        {
            if ( advanceTo(vec,i) != vec.end())
                vector_splice(subChain, subChain.begin(), vec, advanceTo(vec, i), vec.end() );
                // spliceVector(subChain, vec, i, vec.size()-i);
                // subChain.splice(subChain.begin(), vec, advanceTo(vec, i), vec.end() );
            break;
        }
        if(pairCompare(vec, pairSize, i)) {
            pairSwap(vec, pairSize, i);
        }

        i+=pairSize + pairSize;
    }
}




/**
 * separate mainChain SubChain
*/

void PmergeMe::separateMainChainAndSubChain(std::vector<int> & mainChain, std::vector<int> & subChain, int pairSize) {
    std::vector<int>::iterator left;
    std::vector<int>::iterator left_end;

    for ( int i=1; ; ++i ) {
        left = advanceTo(mainChain,  i*pairSize );
        if( left == mainChain.end() )
            break;
        left_end = advanceTo(mainChain, i*pairSize + pairSize);
        vector_splice(subChain, advanceTo(subChain, (i-1) * pairSize), mainChain, left, left_end);
    } 
}




/**
 * insert first subPair
*/

void PmergeMe::insertAtTheStart(std::vector<int> & mainChain, std::vector<int> & subChain, int pairSize) {
    mainChain.insert(mainChain.begin(), subChain.begin(),  advanceTo(subChain, pairSize) );
}



/**
 * insert
*/
int PmergeMe::jacobsthalNumber(int n) {

    if (n <= 0) return 0;
    if (n == 1) return 1;

    return jacobsthalNumber(n - 1) + (2 * (jacobsthalNumber(n - 2)));
}

bool PmergeMe::isKey(std::vector<int> & vec, int index, int key) {
    if (getElementAtIndex(vec, index) >= key) return true;
    else return false;
}

int PmergeMe::lower_bound(std::vector<int> & vec, int key, int right) {
    int left = -1;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (isKey(vec, mid, key)) right = mid;
        else left = mid;
    }

    return right;
}

int  PmergeMe::binarySearch(std::vector<int> & mainChain, int key, int pairSize, UnpairedData& unpair, int endpoint) { 
    std::vector<int> vec;
    if(unpair.position == -1) {
        (void)unpair;
        for(ConstIntvectorIter it=mainChain.begin(); it != mainChain.end(); it = advanceIt(mainChain, it, pairSize)) {
            vec.push_back(*it);
        }
    } else {
        int index = 0;
        for(ConstIntvectorIter it=mainChain.begin(); it != mainChain.end(); ){
            if(unpair.position == index) {
                vec.push_back(*it);
                std::advance(it, unpair.length);
                ++index;
                continue;
            }
            vec.push_back(*it);
            std::advance(it, pairSize);
            ++index;
        }
    }
    return lower_bound(vec, key, endpoint);
}

void PmergeMe::insertSubChain(std::vector<int> & mainChain,int  insertPosition, ConstIntvectorIter begin, ConstIntvectorIter end) {
    mainChain.insert(advanceTo(mainChain, insertPosition), begin, end);
}

void PmergeMe::insertionFromSubIntoMain(std::vector<int> & mainChain, std::vector<int> & subChain, int pairSize, UnpairedData& unpair) {

    
    #ifdef SORT
        this->printDebug<std::vector<int> >(mainChain, subChain, pairSize, "Before sort");
    #endif

    int maxSize = subChain.size()/pairSize;
    int itr_index =0;
    int insertSize=0;
    for ( int n=3; ; ++n) {
        for( int i=jacobsthalNumber(n); i > jacobsthalNumber(n-1); --i) {
            if( i > maxSize ) {
                i = maxSize;
                if( i == jacobsthalNumber(n-1)) break;
                itr_index = binarySearch(mainChain, getElementAtIndex(subChain, (i-1)*pairSize), pairSize, unpair, insertSize + i - 1);
                insertSubChain(mainChain, itr_index, advanceTo(subChain, (i-1)*pairSize), subChain.end());
                unpair.position = itr_index;
                ++insertSize;
                continue;
            }
            if(unpair.position != -1) {
                if(unpair.value >= getElementAtIndex(subChain, (i-1)*pairSize))
                    ++unpair.position;
            }
            itr_index = binarySearch(mainChain, getElementAtIndex(subChain, (i-1)*pairSize), pairSize, unpair, insertSize + i - 1);
            insertSubChain(mainChain, pairSize*itr_index, advanceTo(subChain, (i-1)*pairSize), advanceTo(subChain, (i-1)*pairSize + pairSize));
            ++insertSize;
        }
        if(jacobsthalNumber(n) > maxSize) break;
    }
    subChain.clear();
    #ifdef SORT
        this->printDebug<std::vector<int> >(mainChain, subChain, pairSize, "After sort");
    #endif
}

void PmergeMe::mergeInsertionSort(std::vector<int> & mainChain,int pairSize) {
    if (mainChain.size() <= 2 * static_cast<size_t>(pairSize)) {
        #ifdef SEPARATE
            this->printDebug<std::vector<int> >( mainChain, std::vector<int>(), pairSize, "Before pair");
        #endif
        #ifdef PAIR
            this->printDebug<std::vector<int> >( mainChain, std::vector<int>(), pairSize, "Before pair");
        #endif
        if(mainChain.size()  <= static_cast<size_t>(pairSize)) return;
        if(!pairCompare(mainChain, pairSize, 0)) {
            pairSwap(mainChain, pairSize, 0);
        }
        #ifdef PAIR
            this->printDebug<std::vector<int> >( mainChain, std::vector<int>(), pairSize, "After pair");
        #endif
        #ifdef SEPARATE
            this->printDebug<std::vector<int> >( mainChain, std::vector<int>(), pairSize, "After pair");
        #endif
        return ; 
    } 
    
    std::vector<int> subChain;
    #ifdef PAIR
        this->printDebug<std::vector<int> >( mainChain, subChain, pairSize, "Before pair");
    #endif
    makePair( mainChain, subChain, pairSize);
    #ifdef PAIR
        this->printDebug<std::vector<int> >( mainChain, subChain, pairSize, "After pair");
    #endif
    // UnpairedData unpair;
    // unpair.length = subChain.size();
    // unpair.value = *(subChain.begin());
    // unpair.position = -1;
    
    // mergeInsertionSort(mainChain, pairSize * 2);

    // #ifdef SEPARATE
    //     this->printDebug<std::vector<int> >(mainChain, subChain, pairSize, "Before separating.");
    // #endif
    // separateMainChainAndSubChain(mainChain, subChain, pairSize);
    // #ifdef SEPARATE
    //     this->printDebug<std::vector<int> >(mainChain, subChain, pairSize, "After separating.");
    // #endif

    // #ifdef INSERTATTHESTART
    //     this->printDebug<std::vector<int> >(mainChain, subChain, pairSize, "Before Insert the first value.");
    // #endif
    // insertAtTheStart(mainChain, subChain, pairSize);
    // #ifdef INSERTATTHESTART
    //     this->printDebug<std::vector<int> >(mainChain, subChain, pairSize, "After Insert the first value.");
    // #endif

    // insertionFromSubIntoMain(mainChain, subChain, pairSize, unpair);
}























void    PmergeMe::initContainer(int size, int numbers[]) {
    for (int i = 0; i < size; ++i) { mainChain_.push_back(numbers[i]);}
}

void PmergeMe::FordJohnsonAlgorithm(int size, int numbers[]) {
    this->initContainer(size, numbers);
    std::vector<int> arr(mainChain_);
    try {
        mergeInsertionSort(this->mainChain_, 1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::exit(1);
    }

    std::cout << "sort 前" << std::endl;
    PmergeMe::print<std::vector<int>, ConstIntvectorIter>(this->mainChain_);
    // mainChain_.sort();
    std::sort(mainChain_.begin(), mainChain_.end());
    PmergeMe::print<std::vector<int>, ConstIntvectorIter>(this->mainChain_);
    std::cout << "sort後" << std::endl;
    if (isSorted(mainChain_)) {
        std::cout << "\033[32m" << "numbers is sorted: Yes" << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31m" << "numbers is sorted: No" << "\033[0m" << std::endl;
    }

    // arr.sort();
    std::sort(arr.begin(), arr.end());

    
    if (mainChain_ == arr) {
        std::cout << "\033[32m" << "vectors are equal." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31m" << "vectors are not equal." << "\033[0m" << std::endl;
    }


}

