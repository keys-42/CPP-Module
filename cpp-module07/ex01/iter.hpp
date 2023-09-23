#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

template <typename T,typename L>
void iter(T *ptr, L len, void (*f)(const T &))
{
    for(L i = 0; i < len; i++) {
        f(ptr[i]);
    }
}

template <typename T>
void func(const T &p)
{
    std::cout << std::setw(10) << p << std::endl;
}


template <typename T>
void multiplyByPi(const T &value) {
    double result = value * M_PI;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(10) << result << std::endl;
}

#endif