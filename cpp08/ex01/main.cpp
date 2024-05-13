#include "Span.hpp"


int main()
{
    //testing addNumber and shortestSpan and longstSpan functions

    {
        Span sp = Span(10);
        sp.addNumber(2);
        sp.addNumber(-3);
        sp.addNumber(17);
        sp.addNumber(8);
        sp.addNumber(11);
        std::cout << "test 1: shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "test 1: longest span: " << sp.longestSpan() << std::endl;
    }
    std::cout << "================================================" << std::endl;
    // testing addMultNumbers for not enough room
    try {
        Span sp = Span(5);
        std::vector<int> v;
        v.push_back(100);
        v.push_back(500);
        v.push_back(1000);
        v.push_back(100000);
        sp.addMultNumbers(v.begin(), v.end());
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "test 2: shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "test 2: longest span: " << sp.longestSpan() << std::endl;
    }
    catch (Span::NotenoughRoom &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "================================================" << std::endl;
    // testing no span exception
    try {
        Span sp = Span(5);
        sp.addNumber(5);
        std::cout << "test 3: shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "test 3: longest span: " << sp.longestSpan() << std::endl;
    }
    catch (Span::NoSpanException &e) {
        std::cout << e.what() << std::endl;
    }
}