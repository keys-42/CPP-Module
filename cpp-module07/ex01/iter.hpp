#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

template <typename T,typename L>
void iter(T *ptr, L len, void (*f)(T &))
{
    if ( !ptr ) throw std::invalid_argument("Received null as argument"); 
    for(L i = 0; i < len; i++) {
        f(ptr[i]);
    }
}

template <typename T,typename L>
void iter(T const *ptr, L len, void (*f)(const T &))
{
    if ( !ptr ) throw std::invalid_argument("Received null as argument"); 
    for(L i = 0; i < len; i++) {
        f(ptr[i]);
    }
}

template <typename T>
void multiplyByPi(T &value) {
    value = static_cast<int>(M_PI) * value;
}

template <typename T>
void multiplyByPi(T const &value) {
    std::cout << static_cast<int>(M_PI) * value << " ";
}

template <typename T,typename L>
void print(T const *ptr, L len)
{
    if ( !ptr ) throw std::invalid_argument("Received null as argument"); 
    for(L i = 0; i < len; i++) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}

#endif