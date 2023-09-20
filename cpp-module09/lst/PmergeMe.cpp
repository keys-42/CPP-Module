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
bool PmergeMe::shouldSwapPairs(const std::list<int>& lst, int pairSize, int startIndex) {
    return getElementAtIndex(lst, startIndex) < getElementAtIndex(lst, startIndex + pairSize);
}

void PmergeMe::swapPairs(std::list<int>& lst, int pairSize, int startIndex) {
    std::list<int>::iterator leftStart = getIteratorAt(lst, startIndex);
    std::list<int>::iterator leftEnd = getIteratorAt(lst, startIndex + pairSize);
    std::list<int>::iterator rightStart = leftEnd;
    std::list<int>::iterator rightEnd = getIteratorAt(lst, startIndex + 2 * pairSize);

    lst.splice(leftStart, lst, rightStart, rightEnd);
    lst.splice(rightStart, lst, leftStart, leftEnd);
}

bool PmergeMe::isPairPresent(const std::list<int>& lst, int pairSize, size_t startIndex) {
    return getConstIteratorAt(lst, startIndex + 2*pairSize - 1) != lst.end();
}

void PmergeMe::processPairs(std::list<int>& lst, std::list<int>& subChain, int pairSize) {
    for (size_t i = 0; i < lst.size();) {
        if (!isPairPresent(lst, pairSize, i)) {
            std::list<int>::iterator iter = getIteratorAt(lst, i);
            if (iter != lst.end())
                subChain.splice(subChain.begin(), lst, iter, lst.end());
            break;
        }

        if (shouldSwapPairs(lst, pairSize, i)) {
            swapPairs(lst, pairSize, i);
        }

        i += 2 * pairSize;
    }
}

/**
 * separate mainChain SubChain
*/
void PmergeMe::splitIntoMainAndSubChains(std::list<int>& mainChain, std::list<int>& subChain, int pairSize) {

    int segmentIndex = 1;

    while (true) {
        std::list<int>::iterator segmentStart = getIteratorAt(mainChain, segmentIndex * pairSize);
        
        if (segmentStart == mainChain.end()) {
            break;
        }

        std::list<int>::iterator segmentEnd = getIteratorAt(mainChain, (segmentIndex + 1) * pairSize);
        std::list<int>::iterator subChainInsertPosition = getIteratorAt(subChain, (segmentIndex - 1) * pairSize);
        
        subChain.splice(subChainInsertPosition, mainChain, segmentStart, segmentEnd);
        
        ++segmentIndex;
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
        if(!shouldSwapPairs(mainChain, pairSize, 0)) { swapPairs(mainChain, pairSize, 0);}
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
    processPairs(mainChain, subChain, pairSize);
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
    splitIntoMainAndSubChains(mainChain, subChain, pairSize);
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

