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
    if (_v.size() >= _n)
        throw NotenoughRoom();
    this->_v.push_back(i);
}

void Span::addMultNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_v.size() + std::distance(begin, end) > _n)
        throw NotenoughRoom();
    _v.insert(_v.end(), begin, end);
}

int Span::shortestSpan()
{
    int buf;
    int size = _v.size();
    if(size == 0 || size == 1)
        throw NoSpanException();
    std::vector <int> v = _v;
    std::sort(v.begin(), v.end());
    buf = v[1] - v[0];
    for(int i = 0; i < size; i++) {
        if(i + 1 < size) {
            if(v[i + 1] - v[i] < buf)
                {buf = v[i + 1] - v[i];
                std::cout << "buf: " << buf << std::endl;}
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
    std::vector<int>::iterator max = std::max_element(_v.begin(), _v.end());
    std::vector<int>::iterator min = std::min_element(_v.begin(), _v.end());
    buf = *max - *min;
    return (buf);
}

