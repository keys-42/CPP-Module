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
bool PmergeMe::shouldSwapPairs(const std::vector<int>& vec, int pairSize, int startIndex) {
    return getElementAtIndex(vec, startIndex) < getElementAtIndex(vec, startIndex + pairSize);
}

void PmergeMe::swapPairs(std::vector<int>& vec, int pairSize, int startIndex) {
    IntVecIterator leftStart = vec.begin() + startIndex;
    IntVecIterator leftEnd = leftStart + pairSize;
    IntVecIterator rightStart = leftEnd;

    std::swap_ranges(leftStart, leftEnd, rightStart);
}

bool PmergeMe::isPairPresent(const std::vector<int>& vec, int pairSize, size_t startIndex) {
    return getConstIteratorAt(vec, startIndex + 2*pairSize - 1) != vec.end();
}

void PmergeMe::processPairs(std::vector<int>& vec, std::vector<int>& subChain, int pairSize, UnpairedElemenat & unpairedData) {
    for (size_t i = 0; i < vec.size();) {
        if (!isPairPresent(vec, pairSize, i)) {
            std::vector<int>::iterator iter = getIteratorAt(vec, i);
            if (iter != vec.end()) {
                subChain.insert(subChain.begin(), iter, vec.end());
                vec.erase(iter, vec.end());
            }
            break;
        }

        if (shouldSwapPairs(vec, pairSize, i)) {
            swapPairs(vec, pairSize, i);
        }

        i += 2 * pairSize;
    }

    if(subChain.size() > 0)
        unpairedData.value = *(subChain.begin());

    unpairedData.length = subChain.size();
    unpairedData.position = -1;

}

/**
 * separate mainChain SubChain
*/
void PmergeMe::splitIntoMainAndSubChains(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize) {

    int segmentIndex = 1;
    std::vector<int> copy(subChain);
    subChain.clear();

    while (true) {
        std::vector<int>::iterator segmentStart = getIteratorAt(mainChain, segmentIndex * pairSize);
        
        if (segmentStart == mainChain.end()) {
            break;
        }

        std::vector<int>::iterator segmentEnd = getIteratorAt(mainChain, (segmentIndex + 1) * pairSize);
        
        subChain.insert(subChain.end(), segmentStart, segmentEnd);
        mainChain.erase(segmentStart, segmentEnd);
        
        ++segmentIndex;
    }
    
    subChain.insert(subChain.end(), copy.begin(), copy.end());
    copy.clear();
}

/**
 * insert first subPair
*/
void PmergeMe::prependSubchainToMain(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize) {
    std::vector<int>::iterator subStart = subChain.begin();
    std::vector<int>::iterator subEnd = getIteratorAt(subChain, pairSize);
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

bool PmergeMe::elementExceedsKey(std::vector<int>& vec, int index, int key) {
    return getElementAtIndex(vec, index) >= key;
}

int PmergeMe::find_lower_bound(std::vector<int> & vec, int key) {
    int left = -1;
    int right = vec.size();

    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (elementExceedsKey(vec, mid, key)) right = mid;
        else left = mid;
    }
    return right;
}

void PmergeMe::createComparisonVectorFromMainChain(std::vector<int>& vec, std::vector<int>& mainChain, int pairSize, UnpairedElemenat& unpairedData, int endpoint) {
    int point=0;
    if(unpairedData.position == -1 || unpairedData.length == 0 ) {
        for(ConstIntVecIterator it=mainChain.begin(); it != mainChain.end(); ) {
            vec.push_back(*it);
            if(point == endpoint)
                break;
            ++point;
        it = advanceTo(mainChain, it, pairSize);
        }
    } else {
        int index = 0;
        for(ConstIntVecIterator it=mainChain.begin(); it != mainChain.end(); ){
            if(unpairedData.position == index) {
                vec.push_back(*it);
                it = advanceTo(mainChain, it, unpairedData.length);
                ++index;
                ++point;
                continue;
            }
            vec.push_back(*it);
            std::advance(it, pairSize);
            if(point == endpoint)
                break;
            ++point;
            ++index;
        }
    }
}

int  PmergeMe::lower_bound(std::vector<int> & mainChain, int key, int pairSize, UnpairedElemenat& unpairedData, int endpoint) { 
    std::vector<int> vec;
    createComparisonVectorFromMainChain(vec, mainChain, pairSize, unpairedData, endpoint);
    return find_lower_bound(vec, key);
}

void PmergeMe::insertSubChain(std::vector<int> & mainChain,int  insertPosition, ConstIntVecIterator begin, ConstIntVecIterator end) {
    mainChain.insert(getIteratorAt(mainChain, insertPosition), begin, end);
}

void PmergeMe::insertSegmentToMainChain(std::vector<int>& mainChain, std::vector<int>& subChain, int segmentStart, int segmentEnd, int insertionPoint, int pairSize) {
    std::vector<int>::iterator startIter = getIteratorAt(subChain, segmentStart * pairSize);
    std::vector<int>::iterator endIter = (segmentEnd == -1) ? subChain.end() : getIteratorAt(subChain, segmentEnd * pairSize);
    mainChain.insert(getIteratorAt(mainChain, pairSize * insertionPoint), startIter, endIter);
}


void PmergeMe::mergeSubIntoMain(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize, UnpairedElemenat& unpairedData) {
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


void PmergeMe::mergeInsertionSort(std::vector<int> & mainChain,int pairSize) {
    if (mainChain.size() <= 2 * static_cast<size_t>(pairSize)) {
        #ifdef SEPARATE
        this->printDebug<int>( mainChain, std::vector<int>(), pairSize, "Before pair");
        #endif
        #ifdef PAIR
        this->printDebug<int>( mainChain, std::vector<int>(), pairSize, "Before pair");
        #endif
        if(mainChain.size()  <= static_cast<size_t>(pairSize)) return;
        if(!shouldSwapPairs(mainChain, pairSize, 0)) { swapPairs(mainChain, pairSize, 0);}
        #ifdef PAIR
            this->printDebug<int>( mainChain, std::vector<int>(), pairSize, "After pair");
        #endif
        #ifdef SEPARATE
            this->printDebug<int>( mainChain, std::vector<int>(), pairSize, "After pair");
        #endif
        return ; 
    } 
    
    std::vector<int> subChain;
    UnpairedElemenat unpairedData;
    #ifdef PAIR
        this->printDebug<int>( mainChain, subChain, pairSize, "Before pair");
    #endif
    processPairs(mainChain, subChain, pairSize, unpairedData);
    #ifdef PAIR
        this->printDebug<int>( mainChain, subChain, pairSize, "After pair");
    #endif
    
    mergeInsertionSort(mainChain, pairSize * 2);

    #ifdef SEPARATE
    this->printDebug<int>(mainChain, subChain, pairSize, "Before separating.");
    #endif
    splitIntoMainAndSubChains(mainChain, subChain, pairSize);
    #ifdef SEPARATE
        this->printDebug<int>(mainChain, subChain, pairSize, "After separating.");
    #endif

    #ifdef INSERTATTHESTART
        this->printDebug<int>(mainChain, subChain, pairSize, "Before Insert the first value.");
    #endif
    prependSubchainToMain(mainChain, subChain, pairSize);
    #ifdef INSERTATTHESTART
    this->printDebug<int>(mainChain, subChain, pairSize, "After Insert the first value.");
    #endif

    
    #ifdef SORT
        this->printDebug<int>(mainChain, subChain, pairSize, "Before sort");
    #endif
    mergeSubIntoMain(mainChain, subChain, pairSize, unpairedData);
    #ifdef SORT
        this->printDebug<int>(mainChain, subChain, pairSize, "After sort");
    #endif
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
    std::sort(arr.begin(), arr.end());

    // PmergeMe::print<std::vector<int>, ConstIntVecIterator>(this->mainChain_);
    // if (isSorted(mainChain_)) {
    //     std::cout << "\033[32m" << "numbers is sorted: Yes" << "\033[0m" << std::endl;
    // } else {
    //     std::cout << "\033[31m" << "numbers is sorted: No" << "\033[0m" << std::endl;
    // }

    // arr.sort();
    
if (mainChain_ == arr) {
    std::cout << "\033[32m" << "vectors are equal." << "\033[0m" << std::endl;
} else {
    std::cout << "\033[31m" << "vectors are not equal." << "\033[0m" << std::endl;
}
}
