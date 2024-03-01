#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
	T *_arr;
	unsigned int _size;
public:
	Array() : _arr(NULL), _size(0) {}
	Array(unsigned int n) : _arr(new T[n]), _size(n) {}
	Array(Array const &copy) : _arr(new T[copy._size]), _size(copy._size) {
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = copy._arr[i];
	}
	~Array() {
		delete[] _arr;
	}
	Array &operator=(Array const &copy){
		if (this != &copy){
			delete[] _arr;
			_arr = new T[copy._size];
			_size = copy._size;
			for (unsigned int i = 0; i < _size; i++)
				_arr[i] = copy._arr[i];
		}
		return *this;
	}
	T &operator[](unsigned int i){
		if (i >= _size)
			throw OutOfLimits();
		return _arr[i];
	}
	unsigned int size() const{
		return _size;
	}
	class OutOfLimits : public std::exception {
		virtual const char *what() const throw(){
			return "Error: out of limits";
		}
	};
};
#endif