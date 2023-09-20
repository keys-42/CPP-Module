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

void PmergeMe::processPairs(std::list<int>& lst, std::list<int>& subChain, int pairSize, UnpairedElemenat & unpairedData) {
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

    unpairedData.length = subChain.size();
    unpairedData.value = *(subChain.begin());
    unpairedData.position = -1;
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
void PmergeMe::prependSubchainToMain(std::list<int>& mainChain, std::list<int>& subChain, int pairSize) {
    std::list<int>::iterator subStart = subChain.begin();
    std::list<int>::iterator subEnd = getIteratorAt(subChain, pairSize);
    mainChain.insert(mainChain.begin(), subStart, subEnd);
}

/**
 * insert
*/
int PmergeMe::calculateJacobsthalNumber(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return calculateJacobsthalNumber(n - 1) + (2 * calculateJacobsthalNumber(n - 2));
}

bool PmergeMe::elementExceedsKey(std::list<int>& lst, int index, int key) {
    return getElementAtIndex(lst, index) >= key;
}

int PmergeMe::find_lower_bound(std::list<int> & lst, int key) {
    int left = -1;
    int right = lst.size();

    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (elementExceedsKey(lst, mid, key)) right = mid;
        else left = mid;
    }
    return right;
}

void PmergeMe::createComparisonListFromMainChain(std::list<int>& lst, std::list<int>& mainChain, int pairSize, UnpairedElemenat& unpairedData, int endpoint) {
    int point=0;
    if(unpairedData.position == -1 || unpairedData.length == 0 ) {
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
            if(unpairedData.position == index) {
                lst.push_back(*it);
                std::advance(it, unpairedData.length);
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
}

int  PmergeMe::lower_bound(std::list<int> & mainChain, int key, int pairSize, UnpairedElemenat& unpairedData, int endpoint) { 
    std::list<int> lst;
    createComparisonListFromMainChain(lst, mainChain, pairSize, unpairedData, endpoint);
    return find_lower_bound(lst, key);
}

void PmergeMe::insertSubChain(std::list<int> & mainChain,int  insertPosition, ConstIntListIter begin, ConstIntListIter end) {
    mainChain.insert(getIteratorAt(mainChain, insertPosition), begin, end);
}

void PmergeMe::insertSegmentToMainChain(std::list<int>& mainChain, std::list<int>& subChain, int segmentStart, int segmentEnd, int insertionPoint, int pairSize) {
    std::list<int>::iterator startIter = getIteratorAt(subChain, segmentStart * pairSize);
    std::list<int>::iterator endIter = (segmentEnd == -1) ? subChain.end() : getIteratorAt(subChain, segmentEnd * pairSize);
    mainChain.insert(getIteratorAt(mainChain, pairSize * insertionPoint), startIter, endIter);
}


void PmergeMe::mergeSubIntoMain(std::list<int>& mainChain, std::list<int>& subChain, int pairSize, UnpairedElemenat& unpairedData) {
    int maxSegments = subChain.size() / pairSize;
    int insertSize = 0;

    for (int n = 3;; ++n) {
        for (int i = calculateJacobsthalNumber(n); i > calculateJacobsthalNumber(n - 1); --i) {
            if (i > maxSegments) {
                i = maxSegments;
                if (i == calculateJacobsthalNumber(n - 1)) break;
            }

            int key = getElementAtIndex(subChain, (i - 1) * pairSize);
            int insertionPoint = lower_bound(mainChain, key, pairSize, unpairedData, insertSize + i - 1);

            if (i == maxSegments) {
                insertSegmentToMainChain(mainChain, subChain, i - 1, -1, insertionPoint, pairSize);
                unpairedData.position = insertionPoint - 1;
            } else {
                insertSegmentToMainChain(mainChain, subChain, i - 1, i, insertionPoint, pairSize);
                if (unpairedData.position != -1 && unpairedData.value > key) {
                    unpairedData.position++;
                }
            }

            insertSize++;
        }
        if (calculateJacobsthalNumber(n) > maxSegments) break;
    }

    subChain.clear();
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
    UnpairedElemenat unpairedData;
    #ifdef PAIR
        this->printDebug<std::list<int> >( mainChain, subChain, pairSize, "Before pair");
    #endif
    processPairs(mainChain, subChain, pairSize, unpairedData);
    #ifdef PAIR
        this->printDebug<std::list<int> >( mainChain, subChain, pairSize, "After pair");
    #endif
    
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
    prependSubchainToMain(mainChain, subChain, pairSize);
    #ifdef INSERTATTHESTART
    this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "After Insert the first value.");
    #endif

    
    #ifdef SORT
        this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "Before sort");
    #endif
    mergeSubIntoMain(mainChain, subChain, pairSize, unpairedData);
    #ifdef SORT
        this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "After sort");
    #endif
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
}
