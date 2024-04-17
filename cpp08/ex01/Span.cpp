#include "Span.hpp"


Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &other) : _n(other._n), _v(other._v)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _n = other._n;
        _v = other._v;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int i)
{
    this->_v.push_back(i);
}

void Span::addMultNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    _v.insert(_v.begin() + _v.size(), begin, end);
}

int Span::shortestSpan()
{
    int buf;
    int size = _v.size();
    if(size == 0 || size == 1)
        throw NoSpanException();
    buf = _v[0];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if (_v[i] - _v[j] < buf && (_v[i] - _v[j]) > 0)
            {
                buf = _v[i] - _v[j];
            }
        }
    }
    return (buf);
}

int Span::longestSpan()
{
    int buf;
    int size = _v.size();
    if(size == 0 || size == 1)
        throw NoSpanException();
    buf = _v[0];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if (_v[i] - _v[j] > buf && (_v[i] - _v[j]) > 0)
            {
                buf = _v[i] - _v[j];
            }
        }
    }
    return (buf);
}

