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

typedef std::list<int>::const_iterator ConstIntListIter;
typedef std::list<int>::iterator IntListIter;

typedef std::list<std::list<int>::const_iterator> ConstIteratorList;
typedef std::list<std::list<int>::const_iterator>::const_iterator ConstIteratorListIterator;


/**
 * pair comparison
*/
bool     PmergeMe::pairCompare( std::list<int> & lst, int pairSize, int start ) {
    if( getElementAtIndex(lst, start) < getElementAtIndex(lst,start + pairSize) )
        return 1;
    return 0;
}

void PmergeMe::pairSwap(std::list<int>& lst, int pairSize, int start) {
    std::list<int>::iterator left = getIteratorAt(lst, start);
    std::list<int>::iterator left_end = getIteratorAt(lst, start + pairSize);
    std::list<int>::iterator right = left_end;
    std::list<int>::iterator right_end = getIteratorAt(lst, start + 2 * pairSize);

    lst.splice(left, lst, right, right_end);

    lst.splice(right, lst, left, left_end);
}

bool PmergeMe::hasPair(std::list<int> & lst, int pairSize, size_t start) {
    if(getIteratorAt(lst,start + pairSize + pairSize - 1) == lst.end())
        return false;
    return true;
}

void    PmergeMe::makePair(std::list<int> & lst, std::list<int> & subChain, int pairSize) {

    for ( size_t i=0; i < lst.size(); ) {

        if( ! hasPair(lst, pairSize,i) )
        {
            if ( getIteratorAt(lst,i) != lst.end())
                subChain.splice(subChain.begin(), lst, getIteratorAt(lst, i), lst.end() );
            break;
        }
        if(pairCompare(lst, pairSize, i)) {
            pairSwap(lst, pairSize, i);
        }

        i+=pairSize + pairSize;
    }
}

/**
 * separate mainChain SubChain
*/

void PmergeMe::separateMainChainAndSubChain(std::list<int> & mainChain, std::list<int> & subChain, int pairSize) {
    std::list<int>::iterator left;
    std::list<int>::iterator left_end;

    for ( int i=1; ; ++i ) {
        left = getIteratorAt(mainChain,  i*pairSize );
        if( left == mainChain.end() )
            break;
        left_end = getIteratorAt(mainChain, i*pairSize + pairSize);
        subChain.splice(getIteratorAt(subChain, (i-1) * pairSize), mainChain, left, left_end);
    } 
}

/**
 * insert first subPair
*/

void PmergeMe::insertAtTheStart(std::list<int> & mainChain, std::list<int> & subChain, int pairSize) {
    mainChain.insert(mainChain.begin(), subChain.begin(),  getIteratorAt(subChain, pairSize) );
}

/**
 * insert
*/
int PmergeMe::jacobsthalNumber(int n) {

    if (n <= 0) return 0;
    if (n == 1) return 1;

    return jacobsthalNumber(n - 1) + (2 * (jacobsthalNumber(n - 2)));
}

bool PmergeMe::isKey(std::list<int> & lst, int index, int key) {
    if (getElementAtIndex(lst, index) >= key) return true;
    else return false;
}

int PmergeMe::lower_bound(std::list<int> & lst, int key, int right) {
    // std::cout << right <<" right"<< std::endl;
    int left = -1;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (isKey(lst, mid, key)) right = mid;
        else left = mid;
    }

    return right;
}

int  PmergeMe::binarySearch(std::list<int> & mainChain, int key, int pairSize, UnpairedData& unpair, int endpoint) { 
    std::list<int> lst;
    int point=0;
    if(unpair.position == -1 || unpair.length == 0 ) {
        for(ConstIntListIter it=mainChain.begin(); it != mainChain.end(); ) {
            lst.push_back(*it);
            if(point == endpoint)
                break;
            ++point;
        it = advanceTo(mainChain, it, pairSize);
        }
    } else {
        int index = 0;
        for(ConstIntListIter it=mainChain.begin(); it != mainChain.end(); ){
            if(unpair.position == index) {
                lst.push_back(*it);
                std::advance(it, unpair.length);
                ++index;
                ++point;
                continue;
            }
            lst.push_back(*it);
            std::advance(it, pairSize);
            if(point == endpoint)
                break;
            ++point;
            ++index;
        }
    }
    return lower_bound(lst, key, lst.size());
}

void PmergeMe::insertSubChain(std::list<int> & mainChain,int  insertPosition, ConstIntListIter begin, ConstIntListIter end) {
    mainChain.insert(getIteratorAt(mainChain, insertPosition), begin, end);
}

void PmergeMe::insertionFromSubIntoMain(std::list<int> & mainChain, std::list<int> & subChain, int pairSize, UnpairedData& unpair) {

    
    #ifdef SORT
        this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "Before sort");
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
                insertSubChain(mainChain, pairSize*itr_index, getIteratorAt(subChain, (i-1)*pairSize), subChain.end());
                unpair.position = itr_index -1 ;
                ++insertSize;
                continue;
            }
            itr_index = binarySearch(mainChain, getElementAtIndex(subChain, (i-1)*pairSize), pairSize, unpair, insertSize + i - 1);
            insertSubChain(mainChain, pairSize*itr_index, getIteratorAt(subChain, (i-1)*pairSize), getIteratorAt(subChain, (i-1)*pairSize + pairSize));
            if(unpair.position != -1) {
                if(unpair.value > getElementAtIndex(subChain, (i-1)*pairSize))
                    ++unpair.position;
            }
            ++insertSize;
        }
        if(jacobsthalNumber(n) > maxSize) break;
    }
    subChain.clear();
    #ifdef SORT
        this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "After sort");
    #endif
}

void PmergeMe::mergeInsertionSort(std::list<int> & mainChain,int pairSize) {
    if (mainChain.size() <= 2 * static_cast<size_t>(pairSize)) {
        #ifdef SEPARATE
        this->printDebug<std::list<int> >( mainChain, std::list<int>(), pairSize, "Before pair");
        #endif
        #ifdef PAIR
        this->printDebug<std::list<int> >( mainChain, std::list<int>(), pairSize, "Before pair");
        #endif
        if(mainChain.size()  <= static_cast<size_t>(pairSize)) return;
        if(!pairCompare(mainChain, pairSize, 0)) {
            pairSwap(mainChain, pairSize, 0);
        }
        #ifdef PAIR
            this->printDebug<std::list<int> >( mainChain, std::list<int>(), pairSize, "After pair");
        #endif
        #ifdef SEPARATE
            this->printDebug<std::list<int> >( mainChain, std::list<int>(), pairSize, "After pair");
        #endif
        return ; 
    } 
    
    std::list<int> subChain;
    #ifdef PAIR
        this->printDebug<std::list<int> >( mainChain, subChain, pairSize, "Before pair");
    #endif
    makePair( mainChain, subChain, pairSize);
    #ifdef PAIR
        this->printDebug<std::list<int> >( mainChain, subChain, pairSize, "After pair");
    #endif
    UnpairedData unpair;
    unpair.length = subChain.size();
    unpair.value = *(subChain.begin());
    unpair.position = -1;
    
    mergeInsertionSort(mainChain, pairSize * 2);

    #ifdef SEPARATE
    this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "Before separating.");
    #endif
    separateMainChainAndSubChain(mainChain, subChain, pairSize);
    #ifdef SEPARATE
        this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "After separating.");
    #endif

    #ifdef INSERTATTHESTART
        this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "Before Insert the first value.");
    #endif
    insertAtTheStart(mainChain, subChain, pairSize);
    #ifdef INSERTATTHESTART
    this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "After Insert the first value.");
    #endif

    insertionFromSubIntoMain(mainChain, subChain, pairSize, unpair);
}


















void PmergeMe::tset(std::list<int> & l, std::list<int> & s) {

        std::list<int>::const_iterator it = l.begin();
        std::list<int>::const_iterator itr = s.begin();
    for( ;itr != s.end() ;) {
        if(*it != *itr)
            std::cout << "\033[31m" << *it << "\033[0m" << std::endl;

        ++itr;
        ++it;
    } 
}




void    PmergeMe::initContainer(int size, int numbers[]) {
    for (int i = 0; i < size; ++i) { mainChain_.push_back(numbers[i]);}
}

void PmergeMe::FordJohnsonAlgorithm(int size, int numbers[]) {
    this->initContainer(size, numbers);
    std::list<int> arr(mainChain_);
    try {
        mergeInsertionSort(this->mainChain_, 1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::exit(1);
    }

    PmergeMe::print<std::list<int>, ConstIntListIter>(this->mainChain_);
    if (isSorted(mainChain_)) {
        std::cout << "\033[32m" << "numbers is sorted: Yes" << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31m" << "numbers is sorted: No" << "\033[0m" << std::endl;
    }

    arr.sort();
    
    if (mainChain_ == arr) {
        std::cout << "\033[32m" << "Lists are equal." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31m" << "Lists are not equal." << "\033[0m" << std::endl;
    }

    tset(mainChain_, arr);

}

