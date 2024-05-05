#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
	T *arr;
	unsigned int arrsize;
public:
	Array() : arr(NULL), arrsize(0) {}
	Array(unsigned int n) : arr(new T[n]()), arrsize(n) {}
	Array(Array const &copy) : arr(new T[copy.arrsize]()), arrsize(copy.arrsize) {
		for (unsigned int i = 0; i < arrsize; i++)
			arr[i] = copy.arr[i];
	}
	~Array() {
		delete[] arr;
	}

	Array &operator=(Array const &copy) {
		if (this != &copy){
			delete[] arr;
			arr = new T[copy.arrsize]();
			arrsize = copy.arrsize;
			for (unsigned int i = 0; i < arrsize; i++)
				arr[i] = copy.arr[i];
		}
		return *this;
	}

	T &operator[](unsigned int i) {
		if (i >= arrsize)
			throw OutOfLimits();
		return arr[i];
	}
	unsigned int size() const{
		return arrsize;
	}
	class OutOfLimits : public std::exception {
		virtual const char *what() const throw(){
			return "Error: out of limits";
		}
	};
};

#endif