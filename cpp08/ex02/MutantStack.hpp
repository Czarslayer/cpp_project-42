#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack &other)
    {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    typedef typename std::stack<T>::container_type::iterator iterator;
    
    typename std::stack<T>::container_type::iterator begin()
    {
        return std::stack<T>::c.begin();
    }

    typename std::stack<T>::container_type::iterator end()
    {
        return std::stack<T>::c.end();
    }
};

#endif