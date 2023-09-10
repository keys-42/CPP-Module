#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

template <typename T,typename L>
void iter(T *ptr, L len, void (*f)(T &))
{
    for(L i = 0; i < len; i++) {
        f(ptr[i]);
    }
}

template <typename T>
void func(T &p)
{
    std::cout << std::setw(10) << p << std::endl;
}

#endif