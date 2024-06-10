/**********************************************************
 // -> : ██████╗ █████╗ ███████╗███████╗ █████╗ ██████╗ 
        ██╔════╝██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗ 
        ██║     ███████║█████╗  ███████╗███████║██████╔╝ 
        ██║     ██╔══██║██╔══╝  ╚════██║██╔══██║██╔══██╗ 
        ╚██████╗██║  ██║███████╗███████║██║  ██║██║  ██║ 
         ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝
 // -> Author:        mabahani
 // -> Modified by:   CZAR
 // -> Modified time: 2024-06-05 15:23:04
 **********************************************************/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <utility>

class PmergeMe {
    private:
        std::vector<int> vec_t;
        std::deque<int> deq_t;
        int isSorted;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        int Jacobsthal(int n);
        void parser(int argc,char **argv);
        int strToDouble(std::string test);


        // vector fucntions 
        std::vector<int> mainHubVector();
            void recursiveSortVector(std::vector<std::pair<int,int> > &couples);
            void mergeSortVector(std::vector<std::pair<int, int> >& arr, int left, int right);
            void mergeVector(std::vector<std::pair<int, int> >& arr, int left, int mid, int right);
            std::vector<unsigned long> jacobIndexGeneratorVector(std::vector<int> &jacobsthals, int size);
            int returnIndexVector(std::vector<int> &v, int value);
        
        // deque functions
        std::deque<int> mainHubDeque();
            void recursiveSortDeque(std::deque<std::pair<int,int> > &couples);
            void mergeSortDeque(std::deque<std::pair<int, int> >& arr, int left, int right);
            void mergeDeque(std::deque<std::pair<int, int> >& arr, int left, int mid, int right);
            std::deque<unsigned long> jacobIndexGeneratorDeque(std::deque<int> &jacobsthals, int size);
            int returnIndexDeque(std::deque<int> &v, int value);
            
};

#endif