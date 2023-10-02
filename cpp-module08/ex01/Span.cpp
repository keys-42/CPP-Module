#include "Span.hpp"

Span::Span(){};

Span::Span(unsigned int n) {
	v_.reserve(n);
}

Span::Span(const Span& r)
	: v_(r.v_) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->v_ = other.v_;
	}
	return *this;
}

void Span::checkMaxSize(unsigned int len) const {
	if ((v_.capacity() < len) || (v_.size() > v_.capacity() - len))
		throw SizeOverFlowException();
}

void Span::addNumber(int number) {
	checkMaxSize(1);
	v_.push_back(number);
}

void Span::printContainer() {
	std::vector<int>::iterator itr;

	for (itr = v_.begin(); itr != v_.end(); ++itr) {
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

unsigned int Span::shortestSpan() {
	if (v_.size() <= 1)
		throw SpanException();

	std::vector<int> sorted(v_);
	std::sort(sorted.begin(), sorted.end());

	unsigned int span = std::numeric_limits<int>::max() - std::numeric_limits<int>::min();
	for (std::size_t i = 1; i < sorted.size(); ++i) {
		unsigned int diff = sorted[i] - sorted[i - 1];
		if (diff < span)
			span = diff;
	}
	return span;
}

unsigned int Span::longestSpan() {
	if (v_.size() <= 1)
		throw SpanException();
	std::vector<int>::iterator max = std::max_element(v_.begin(), v_.end());
	std::vector<int>::iterator min = std::min_element(v_.begin(), v_.end());
	return *max - *min;
}