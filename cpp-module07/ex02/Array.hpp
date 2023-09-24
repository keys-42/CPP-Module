#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cmath>
# include <iomanip>
# include <string>

template <typename T>
class Array 
{
    private:
        T *array_;
        unsigned int size_;

    public:
        Array(): array_( new T[0] ), size_(0){ };
        Array( unsigned int n): array_( new T[n] ), size_(n) {
            for (unsigned int i=0; i < n; ++i) {
                array_[i] = T();
            }
         };
        Array(Array &r) :array_(new T[r.size()]) {
            this->size_ = r.size();
            for ( unsigned int i = 0; i < this->size_; i++) {
                this->array_[i] = r.array_[i];
            }
        };
        virtual ~Array() { 
            delete[] array_ ;
        };
        Array& operator=( const Array& r ) {
            if ( this != &r ) {
                delete[] this->array_;
                array_ = new T[r.size()];
                this->size_ = r.size();
                for ( unsigned int i = 0; i < this->size_; i++) {
                    this->array_[i] = r.array_[i];
                }
            }
            return *this;
        };
        T& operator[]( unsigned int i ) const {
            if(this->size() <= i)
                throw OutOfBoundsException();
            return this->array_[i];
        }
        unsigned int size() const {
            return size_;
        }
        class OutOfBoundsException : public std::exception
        {
            public: 
                virtual const char* what() const throw() { return ("its index is out of bounds."); }
        };
};

template < typename T >
std::ostream& operator<<(std::ostream& os, const Array<T>& obj)
{
    for (unsigned int i = 0; i < obj.size(); i++) {
        os << std::setw(7) << obj[i];
    }
	return os;
}

#endif