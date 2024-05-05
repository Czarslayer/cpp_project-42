#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class PmergeME {
    public:
        PmergeME();
        ~PmergeME();
        PmergeME(const PmergeME& other);
        PmergeME& operator=(const PmergeME& other);
        void run(std::vector<std::string> args);
        void run(int argc, char** argv);

};

#endif