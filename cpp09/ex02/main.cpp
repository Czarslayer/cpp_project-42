/**********************************************************
 // -> : ██████╗ █████╗ ███████╗███████╗ █████╗ ██████╗ 
        ██╔════╝██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗ 
        ██║     ███████║█████╗  ███████╗███████║██████╔╝ 
        ██║     ██╔══██║██╔══╝  ╚════██║██╔══██║██╔══██╗ 
        ╚██████╗██║  ██║███████╗███████║██║  ██║██║  ██║ 
         ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝
 // -> Author:        mabahani
 // -> Modified by:   CZAR
 // -> Modified time: 2024-06-05 19:15:08
 **********************************************************/

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <deque>

int main(int argc, char **argv)
{
    PmergeMe fordJhonson;
    struct timeval startTimeVector, endTimeVector;
    struct timeval startTimeDeque, endTimeDeque;
    try {
        if(argc <= 1)
            throw std::runtime_error("Usage: ./PmergeMe [numbers to sort ..]");
        if(argc == 2)
            throw std::runtime_error("nothing to sort");
        fordJhonson.parser(argc,argv);
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        exit(3);
    }

    // Timing for std::vector
    gettimeofday(&startTimeVector, NULL);
    std::vector<int> vectorOne = fordJhonson.mainHubVector();
    gettimeofday(&endTimeVector, NULL);
    long durationVector = (endTimeVector.tv_sec - startTimeVector.tv_sec) * 1000000 + (endTimeVector.tv_usec - startTimeVector.tv_usec);

    // Timing for std::deque
    gettimeofday(&startTimeDeque, NULL);
    std::deque<int> dequeOne = fordJhonson.mainHubDeque();
    gettimeofday(&endTimeDeque, NULL);
    long durationDeque = (endTimeDeque.tv_sec - startTimeDeque.tv_sec) * 1000000 + (endTimeDeque.tv_usec - startTimeDeque.tv_usec);

    std::cout << "after: ";
    for (size_t i = 0; i < dequeOne.size(); i++)
    {
        std::cout << dequeOne[i] << " ";
    }
    std::cout << std::endl;
    // Output timings
    std::cout.precision(6);
    std::cout << "Time to process a range of " << vectorOne.size() << " Time taken by std::vector: " << std::fixed << (double)durationVector << " us" << std::endl;
    std::cout <<"Time to process a range of " << dequeOne.size() << " Time taken by std::deque: " << std::fixed << (double)durationDeque << " us" << std::endl;

    return 0;
}