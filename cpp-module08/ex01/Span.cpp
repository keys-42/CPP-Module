#include "Span.hpp"

Span::Span(unsigned int n) { v_.reserve(n); }

Span::~Span() {}

void Span::checkMaxSize(unsigned int len) {
    if((v_.capacity() < len) ||(v_.size()  > v_.capacity() - len))
        throw SizeOverFlowException();
}

void Span::addNumber(int number) {
    checkMaxSize(1);
    v_.push_back(number);
}

void Span::printContainer() {
    std::vector<int>::iterator itr;

    for ( itr = v_.begin();itr != v_.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

unsigned int Span::shortestSpan() {
    if(v_.size() <= 1) throw SpanException();
    std::vector<int> c(v_);
    std::sort(c.begin(), c.end());
    std::vector<int>::iterator itr;
    unsigned int span = UINT_MAX;
    unsigned int p = 0;
    unsigned int n = 0;

    for (itr = c.begin(); itr < c.end(); itr++) {
        p = n;
        n = *itr;        
        if(span > (n - p))
            span = (n - p);
    }
    return span;
}

unsigned int Span::longestSpan() {
    if(v_.size() <= 1) throw SpanException();
    std::vector<int>::iterator max = std::max_element(v_.begin(), v_.end());
    std::vector<int>::iterator min = std::min_element(v_.begin(), v_.end());
    return *max - *min;
}