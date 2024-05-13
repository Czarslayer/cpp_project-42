#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _v;
    public:
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int n);
        void addMultNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();

        class NotenoughRoom : public std::exception 
        {
            public:
                virtual const char * what() const throw()
                {
                    return("no no that's out of boundaries");
                }
        };

        class NoSpanException : public std::exception 
        {
            public:
                virtual const char * what() const throw()
                {
                    return("there's not enough numbers to calculate span");
                }
        };
};

#endif