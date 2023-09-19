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
    std::cout <<  getElementAtIndex(lst, start) << " < " << getElementAtIndex(lst,start + pairSize) <<std::endl;
    if( getElementAtIndex(lst, start) < getElementAtIndex(lst,start + pairSize) )
        return 1;
    return 0;
}

void    PmergeMe::pairSwap( std::list<int> & lst, int pairSize, int start) {
    std::list<int>::iterator left = advanceTo(lst, start);
    std::list<int>::iterator left_end = advanceTo(lst, start + pairSize);

    std::list<int>::iterator right = left_end;
    std::list<int>::iterator right_end = advanceTo(lst, start + 2 * pairSize);

    std::list<int> tmp;
    tmp.splice(tmp.begin(), lst, right, right_end);

    lst.splice(right, lst, left, left_end);
    lst.splice(left, tmp, tmp.begin(), tmp.end());
}

bool PmergeMe::hasPair(std::list<int> & lst, int pairSize, size_t start) {
    if(advanceTo(lst,start + pairSize + pairSize - 1) == lst.end())
        return false;
    return true;
}

void    PmergeMe::makePair(std::list<int> & lst, std::list<int> & subChain, int pairSize) {

    for ( size_t i=0; i < lst.size(); ) {

        if( ! hasPair(lst, pairSize,i) )
        {
            if ( advanceTo(lst,i) != lst.end())
                subChain.splice(subChain.begin(), lst, advanceTo(lst, i), lst.end() );
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
        left = advanceTo(mainChain,  i*pairSize );
        if( left == mainChain.end() )
            break;
        left_end = advanceTo(mainChain, i*pairSize + pairSize);
        subChain.splice(advanceTo(subChain, (i-1) * pairSize), mainChain, left, left_end);
    } 
}




/**
 * insert first subPair
*/

void PmergeMe::insertAtTheStart(std::list<int> & mainChain, std::list<int> & subChain, int pairSize) {
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

int  PmergeMe::binarySearch(std::list<int> & mainChain, int key, int pairSize, UnpairedData& unpair) { 
    std::list<int> lst;
    // if(unpair.position == -1) {
        (void)unpair;
        for(ConstIntListIter it=mainChain.begin(); it != mainChain.end(); it = advanceIt(mainChain, it, pairSize)) {
            lst.push_back(*it);
            // std::cout << *it << " ";
        }
            // std::cout << std::endl;
    // } else {
    //     int index = 0;
    //     for(ConstIntListIter it=mainChain.begin(); it != mainChain.end(); ){
    //         std::cout << "test" << std::endl;
    //         if(unpair.position == index) {
    //             lst.push_back(*it);
    //             std::advance(it, unpair.length);
    //             ++index;
    //             continue;
    //         }
    //         lst.push_back(*it);
    //         std::advance(it, pairSize);
    //         ++index;
    //     }
    // }
    return lower_bound(lst, key, std::distance(lst.begin(), lst.end()) );
}

void PmergeMe::insertSubChain(std::list<int> & mainChain,int  insertPosition, ConstIntListIter begin, ConstIntListIter end) {
    mainChain.insert(advanceTo(mainChain, insertPosition), begin, end);
}

void PmergeMe::insertionFromSubIntoMain(std::list<int> & mainChain, std::list<int> & subChain, int pairSize, UnpairedData& unpair) {

    
    #ifdef SORT
        this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "Before sort");
    #endif
    // this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "Bsort");


    int maxSize = subChain.size()/pairSize;
    int itr_index;
    for ( int n=3; ; ++n) {
        // this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "Bsort");

        for( int i=jacobsthalNumber(n); i > jacobsthalNumber(n-1); --i) {
            if( i > maxSize ) {
                // break;
                i = maxSize;
                if( i == jacobsthalNumber(n-1)) break;
                itr_index = binarySearch(mainChain, getElementAtIndex(subChain, (i-1)*pairSize), pairSize, unpair);
                insertSubChain(mainChain, itr_index, advanceTo(subChain, (i-1)*pairSize), subChain.end());
                // unpair.position = itr_index;
                continue;
                // break;
            }
            // if(unpair.position != -1) {
            //     if(unpair.value >= getElementAtIndex(subChain, (i-1)*pairSize))
            //         ++unpair.position;
            // }
            itr_index = binarySearch(mainChain, getElementAtIndex(subChain, (i-1)*pairSize), pairSize, unpair);
                // std::cout << "itr_index: " << itr_index << " box " << getElementAtIndex(subChain, (i-1)*pairSize) << std::endl;
            insertSubChain(mainChain, pairSize*itr_index, advanceTo(subChain, (i-1)*pairSize), advanceTo(subChain, (i-1)*pairSize + pairSize));
        // std::string s = "i: " + std::to_string(i) + " ";
        // this->printDebug<std::list<int> >(mainChain, subChain, pairSize, s.c_str());
        }
        if(jacobsthalNumber(n) > maxSize) break;
    }
    subChain.clear();
    #ifdef SORT
        this->printDebug<std::list<int> >(mainChain, subChain, pairSize, "After sort");
    #endif
}



void PmergeMe::mergeInsertionSort(std::list<int> & mainChain,int pairSize) {
    if( (mainChain.size() / pairSize)  <= 2 ) { 
        #ifdef PAIR
            this->printDebug<std::list<int> >(mainChain, std::list<int>(), pairSize, "pair");
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























void    PmergeMe::initContainer(int size, int numbers[]) {
    for (int i = 0; i < size; ++i) { mainChain_.push_back(numbers[i]);}
}

void PmergeMe::FordJohnsonAlgorithm(int size, int numbers[]) {
    this->initContainer(size, numbers);
    try {
        mergeInsertionSort(this->mainChain_, 1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::exit(1);
    }

    std::cout << "sort 前" << std::endl;
    PmergeMe::print<std::list<int>, ConstIntListIter>(this->mainChain_);
    mainChain_.sort();
    PmergeMe::print<std::list<int>, ConstIntListIter>(this->mainChain_);
    std::cout << "sort後" << std::endl;

}

