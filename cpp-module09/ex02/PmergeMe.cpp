#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe & r): input_(r.input_), List_mainChain_(r.List_mainChain_), Vector_mainChain_(r.Vector_mainChain_), sorted_(r.sorted_) {};

PmergeMe::~PmergeMe() {};

PmergeMe & PmergeMe::operator= (const PmergeMe &other) {
    if( this != &other ) {
        this->input_ = other.input_;
        this->List_mainChain_ = other.List_mainChain_;
        this->Vector_mainChain_ = other.Vector_mainChain_;
        this->sorted_ = other.sorted_;
    }
    return *this;
}
std::list<int> PmergeMe::getList() const { return this->List_mainChain_; }
std::vector<int> PmergeMe::getVector() const { return this->Vector_mainChain_; }

void PmergeMe::printClock(std::clock_t start, std::clock_t end, E_Type type) {
    std::string t;
    if(type == LIST) t = "  List  ";
    else if(type == VECTOR) t = " Vector ";
    double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    double microseconds = elapsed_time * 1e6;
    std::cout << \
    "Time to process a range of " << \
    this->size_ << \
    " elements with std::[" << \
    t << \
    "] : " << \
    std::fixed << std::setprecision(5) << microseconds << \
    " us" << \
    std::endl;
}

int PmergeMe::stoi(const std::string& str) {
    std::istringstream iss(str);
    int value;
    iss >> value;

    if (iss.fail() || !iss.eof()) {
        throw std::runtime_error("Invalid integer string");
    }

    return value;
}

void    PmergeMe::initContainer(int size, int numbers[]) {
    for (int i = 0; i < size; ++i) { 
        if(numbers[i] < 0) throw std::invalid_argument("Received a negative number");
        if(sorted_.find(numbers[i]) != sorted_.end()) throw std::runtime_error("The number already exists in the sorted container.");
        input_.push_back(numbers[i]);
        sorted_.insert(numbers[i]);
        List_mainChain_.push_back(numbers[i]);
        Vector_mainChain_.push_back(numbers[i]);
    }
}

void    PmergeMe::initContainer(int size, char* numbers) {
    (void)size;
    std::stringstream ss(numbers);
    std::string number;
    int n;
    while (std::getline(ss, number, ' ')) {
        if (!number.empty()) {
            n = stoi(number);
            if(n < 0) throw std::invalid_argument("Received a negative number");
            if(sorted_.find(n) != sorted_.end()) throw std::runtime_error("The number already exists in the sorted container.");
                input_.push_back(n);
                sorted_.insert(n);
                List_mainChain_.push_back(n);
                Vector_mainChain_.push_back(n);
        }
    }
}
void    PmergeMe::initContainer(int size, char* numbers[]) {
    int n;
    for (int i=0; i < size ; ++i) {
        n = stoi(numbers[i]);
        if(n < 0) throw std::invalid_argument("Received a negative number");
        if(sorted_.find(n) != sorted_.end()) throw std::runtime_error("The number already exists in the sorted container.");
        input_.push_back(n);
        sorted_.insert(n);
        List_mainChain_.push_back(n);
        Vector_mainChain_.push_back(n);
    }
}

void    PmergeMe::initContainer(int size, std::string numbers) {
    (void)size;
    std::stringstream ss(numbers);
    std::string number;
    int n;
    while (std::getline(ss, number, ' ')) {
        if (!number.empty()) {
            n = stoi(number);
            if(n < 0) throw std::invalid_argument("Received a negative number");
            if(sorted_.find(n) != sorted_.end()) throw std::runtime_error("The number already exists in the sorted container.");
                input_.push_back(n);
                sorted_.insert(n);
                List_mainChain_.push_back(n);
                Vector_mainChain_.push_back(n);
        }
    }
}
void    PmergeMe::initContainer(int size, std::string numbers[]) {
    int n;
    for (int i=0; i < size ; ++i) {
        n = stoi(numbers[i]);
        if(n < 0) throw std::invalid_argument("Received a negative number");
        if(sorted_.find(n) != sorted_.end()) throw std::runtime_error("The number already exists in the sorted container.");
        input_.push_back(n);
        sorted_.insert(n);
        List_mainChain_.push_back(n);
        Vector_mainChain_.push_back(n);
    }
}

size_t PmergeMe::calculateJacobsthalNumber(size_t n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return calculateJacobsthalNumber(n - 1) + (2 * calculateJacobsthalNumber(n - 2));
}

/**
 * list
*/
//pair comparison
bool PmergeMe::shouldSwapPairs(const int l, const int r) const {
    return l < r;
}

void PmergeMe::swapPairs(std::list<int> lst, std::list<int>::iterator leftStart, std::list<int>::iterator leftEnd, std::list<int>::iterator  rightStart, std::list<int>::iterator rightEnd){
    lst.splice(leftStart, lst, rightStart, rightEnd);
    lst.splice(rightStart, lst, leftStart, leftEnd);
}

void PmergeMe::processPairs(std::list<int>& lst, std::list<int>& subChain, int pairSize) {

    std::list<int>::iterator l_it = lst.begin();
    std::list<int>::iterator r_it = l_it;
    advanceTo(lst, r_it, pairSize);
    while ( l_it != lst.end() ) {
        if(r_it == lst.end()) {
            if(l_it != lst.end())
                subChain.splice(subChain.begin(), lst, l_it, lst.end());
            break;
        }
        if (shouldSwapPairs(*l_it, *r_it)) {
            swapPairs(lst, l_it, r_it,r_it,getAdvanceTo(lst, r_it, pairSize));
            advanceTo(lst, l_it, pairSize);
        } else {
            advanceTo(lst,l_it, 2*pairSize);
        }
        r_it = l_it;
        advanceTo(lst, r_it, pairSize);
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
void PmergeMe::prependFirstOfSubchainToMain(std::list<int>& mainChain, std::list<int>& subChain, int pairSize) {
    std::list<int>::iterator subStart = subChain.begin();
    std::list<int>::iterator subEnd = getIteratorAt(subChain, pairSize);
    mainChain.insert(mainChain.begin(), subStart, subEnd);
}


/**
 * insert
*/
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

void PmergeMe::createComparisonListFromMainChain(std::list<int>& lst, std::list<int>& mainChain, int pairSize, int endpoint) {
    int point=0;
    for(IntListIterator it=mainChain.begin(); it != mainChain.end(); ) {
        lst.push_back(*it);
        if(point == endpoint)
            break;
        ++point;
        advanceTo(mainChain, it, pairSize);
    }
}

int  PmergeMe::lower_bound(std::list<int> & mainChain, int key, int pairSize, int endpoint) { 
    std::list<int> lst;
    createComparisonListFromMainChain(lst, mainChain, pairSize, endpoint);
    return find_lower_bound(lst, key);
}

void PmergeMe::insertSubChain(std::list<int> & mainChain,int  insertPosition, ConstIntListIterator begin, ConstIntListIterator end) {
    mainChain.insert(getIteratorAt(mainChain, insertPosition), begin, end);
}

void PmergeMe::insertSegmentToMainChain(std::list<int>& mainChain, std::list<int>& subChain, int segmentStart, int segmentEnd, int insertionPoint, int pairSize) {
    std::list<int>::iterator startIter = getIteratorAt(subChain, segmentStart * pairSize);
    std::list<int>::iterator endIter = (segmentEnd == -1) ? subChain.end() : getIteratorAt(subChain, segmentEnd * pairSize);
    mainChain.insert(getIteratorAt(mainChain, pairSize * insertionPoint), startIter, endIter);
}


void PmergeMe::mergeSubIntoMain(std::list<int>& mainChain, std::list<int>& subChain, int pairSize, std::list<int>& tmp) {

    std::list<int>::iterator it;
    size_t maxSegments = subChain.size() / pairSize;
    size_t insertSize = 0;

    for (size_t n = 3;; ++n) {
        for (size_t i = calculateJacobsthalNumber(n); i > calculateJacobsthalNumber(n - 1); --i) {
            if (i > maxSegments) {
                i = maxSegments;
                if (i == calculateJacobsthalNumber(n - 1)) break;
            }

            int key = getElementAtIndex(subChain, (i - 1) * pairSize);
            int insertionPoint = lower_bound(mainChain, key, pairSize, insertSize + i - 1);
            #ifdef INSERT
                #ifdef LISTDEBUG
                    testInsertDebug(mainChain, subChain, pairSize, "Insert", key, i);
                #endif
                #ifdef lstTORDEBUG
                    testInsertDebug(mainChain, subChain, pairSize, "Insert", key, i);
                #endif
            #endif

            insertSegmentToMainChain(mainChain, subChain, i - 1, i, insertionPoint, pairSize);

            insertSize++;
        }
        if (calculateJacobsthalNumber(n) > maxSegments) break;
    }
    if(!tmp.empty()){
        int key =*(tmp.begin());
        int insertionPoint = lower_bound(mainChain, key, pairSize, mainChain.size()/pairSize);
        std::cout << "[ last " << key  <<" : " << insertionPoint << " ]" << std::endl;
        std::list<int>::iterator it_l = mainChain.begin();
        advanceTo(mainChain, it_l, pairSize * insertionPoint);
        mainChain.splice(it_l, tmp, tmp.begin(), tmp.end());
    }
    #ifdef INSERT
        std::cout << std::endl << std::endl;
    #endif
    tmp.clear();
    subChain.clear();
}









/**
 * vector
*/

//pair comparison
bool PmergeMe::shouldSwapPairs(const std::vector<int>& vec, int pairSize, int startIndex) {
    return getElementAtIndex(vec, startIndex) < getElementAtIndex(vec, startIndex + pairSize);
}

void PmergeMe::swapPairs(std::vector<int> vec, std::vector<int>::iterator leftStart, std::vector<int>::iterator leftEnd, std::vector<int>::iterator  rightStart, std::vector<int>::iterator rightEnd){
    (void)vec;
    (void)rightEnd;
    std::swap_ranges(leftStart, leftEnd, rightStart);
}

bool PmergeMe::isPairPresent(const std::vector<int>& vec, int pairSize, size_t startIndex) {
    return getConstIteratorAt(vec, startIndex + 2*pairSize - 1) != vec.end();
}

void PmergeMe::processPairs(std::vector<int>& vec, std::vector<int>& subChain, int pairSize) {
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
            swapPairs(vec, vec.begin() + i, vec.begin() + i + pairSize, vec.begin() + i + pairSize, vec.end());
        }

        i += 2 * pairSize;
    }
}

/**
 * separate mainChain SubChain
*/
void PmergeMe::splitIntoMainAndSubChains(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize) {

    std::vector<int>::iterator segmentStart = mainChain.begin();
    advanceTo(mainChain, segmentStart, pairSize);

    while (true) {
        
        if (segmentStart == mainChain.end()) {
            break;
        }
        subChain.insert(subChain.end(), segmentStart, segmentStart + pairSize);
        
        advanceTo(mainChain, segmentStart, 2*pairSize);
    }

    segmentStart = mainChain.begin();
    advanceTo(mainChain, segmentStart, pairSize);

    while (true) {
        
        if (segmentStart == mainChain.end()) {
            break;
        }

        mainChain.erase(segmentStart, segmentStart + pairSize);
        
        advanceTo(mainChain, segmentStart, pairSize);
    }
}


/**
 * insert first subPair
*/
void PmergeMe::prependFirstOfSubchainToMain(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize) {
    std::vector<int>::iterator subStart = subChain.begin();
    mainChain.insert(mainChain.begin(), subStart, subStart + pairSize);
}

/**
 * insert
*/
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

void PmergeMe::createComparisonVectorFromMainChain(std::vector<int>& vec, std::vector<int>& mainChain, int pairSize, int endpoint) {
    int point=0;
    for(IntVecIterator it=mainChain.begin(); it != mainChain.end(); ) {
        vec.push_back(*it);
        if(point == endpoint)
            break;
        ++point;
        advanceTo(mainChain, it, pairSize);
    }
}

int  PmergeMe::lower_bound(std::vector<int> & mainChain, int key, int pairSize, int endpoint) { 
    std::vector<int> vec;
    createComparisonVectorFromMainChain(vec, mainChain, pairSize, endpoint);
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

void PmergeMe::mergeSubIntoMain(std::vector<int>& mainChain, std::vector<int>& subChain, int pairSize, std::vector<int>& tmp) {

    std::vector<int>::iterator it;
    size_t maxSegments = subChain.size() / pairSize;
    size_t insertSize = 0;

    for (size_t n = 3;; ++n) {
        for (size_t i = calculateJacobsthalNumber(n); i > calculateJacobsthalNumber(n - 1); --i) {
            if (i > maxSegments) {
                i = maxSegments;
                if (i == calculateJacobsthalNumber(n - 1)) break;
            }

            int key = getElementAtIndex(subChain, (i - 1) * pairSize);
            int insertionPoint = lower_bound(mainChain, key, pairSize, insertSize + i - 1);
            #ifdef INSERT
                #ifdef LISTDEBUG
                    testInsertDebug(mainChain, subChain, pairSize, "Insert", key, i);
                #endif
                #ifdef VECTORDEBUG
                    testInsertDebug(mainChain, subChain, pairSize, "Insert", key, i);
                #endif
            #endif

            insertSegmentToMainChain(mainChain, subChain, i - 1, i, insertionPoint, pairSize);

            insertSize++;
        }
        if (calculateJacobsthalNumber(n) > maxSegments) break;
    }
    if(!tmp.empty()){
        int key = tmp[0];
        int insertionPoint = lower_bound(mainChain, key, pairSize, mainChain.size()/pairSize);
        mainChain.insert(mainChain.begin() + pairSize * insertionPoint, tmp.begin(), tmp.end());
    }
    #ifdef INSERT
        std::cout << std::endl << std::endl;
    #endif

    subChain.clear();
}




