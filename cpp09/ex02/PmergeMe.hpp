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
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        int Jacobsthal(int n);
        void parser(int argc,char **argv);


        // vector fucntions 
        std::vector<int> mainHubVector();
            //step one
            void recursiveSortVector(std::vector<std::pair<int,int> > &couples);
            void mergeSortVector(std::vector<std::pair<int, int> >& arr, int left, int right);
            void mergeVector(std::vector<std::pair<int, int> >& arr, int left, int mid, int right);
            //step two
            /*hosted in the main hub for vector not enogh to get a function on it's own*/
            //step three
            /*same like the other one most of it except the generator*/
            std::vector<unsigned long> jacobIndexGeneratorVector(std::vector<int> &jacobsthals, int size);
            //step four
            /*insetion will be kept at main hub except for it's inner functions*/
            int returnIndexVector(std::vector<int> &v, int value);
        
        // deque functions
        std::deque<int> mainHubDeque();
            //step one
            void recursiveSortDeque(std::deque<std::pair<int,int> > &couples);
            void mergeSortDeque(std::deque<std::pair<int, int> >& arr, int left, int right);
            void mergeDeque(std::deque<std::pair<int, int> >& arr, int left, int mid, int right);
            //step two
            /*hosted in the main hub for deque not enogh to get a function on it's own*/
            //step three
            /*same like the other one most of it except the generator*/
            std::deque<unsigned long> jacobIndexGeneratorDeque(std::deque<int> &jacobsthals, int size);
            //step four
            /*insetion will be kept at main hub except for it's inner functions*/
            int returnIndexDeque(std::deque<int> &v, int value);
            
};

#endif