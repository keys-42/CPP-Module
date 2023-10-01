#ifndef ITER_HPP
#define ITER_HPP

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

template<typename T>
void iter(T* ptr, std::size_t len, void (*f)(T&)) {
	if (!ptr)
		throw std::invalid_argument("Received null as argument");
	for (std::size_t i = 0; i < len; i++) {
		f(ptr[i]);
	}
}

template<typename T>
void iter(T const* ptr, std::size_t len, void (*f)(T const&)) {
	if (!ptr)
		throw std::invalid_argument("Received null as argument");
	for (std::size_t i = 0; i < len; i++) {
		f(ptr[i]);
	}
}

#endif