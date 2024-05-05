// the plan is the next :
// we need to sort a squence of numbers given by user input
// we will use the merge insert algorithm to sort the numbers also know as ford-johnson algorithm
// first we need to keep deviding the sequence into two parts until we have only two element in each part if the number of elements is odd we will have one part with one element
// we'll call it struggling part

// then we need to sort each pair of elements in each part 
// then we need to create two sequences one for largest elements and one for smallest elements in each part
// and index them in a way that the largest element in the first part is smaller than the smallest element in the second part
// so we need to save the index with every number somehow mybe use vectors of structs with two elements one for the number and one for the index
// afterwe have two sequences we need to create a jacobian sequence with the lenght of the two sequences combined
// jacobian squence looks like this : 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731
// use it like this : jacobian[i] = 2 * jacobian[i - 1] + 1

// now using the original indexing of smallest numbers we start inserting them one by one using the jacobian sequence like this 
//if we reach index 3 of jacobian we insert the number with index 3 in the smallest sequence followed by everyone lesser than it in the smallest sequence
// then we go to next index in the jacobian sequence and insert the number with that index in the smallest sequence followed by everyone lesser than it in the smallest sequence
// until we reach the end of smallest sequence then insert the struggling part using upper bound of the largest sequence
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <sstream>

void recursive_sort(std::vector<int> &t, std::vector<std::vector<int> > &couples)
{
    std::vector<int> couple;

}
int main(int argc, char const *argv[])
{
    std::vector<int> t;
    int n;
    std::stringstream ss;
    std::string temp;

    // fill ss with input
    for (int i = 1; i < argc; i++)
    {
        ss << argv[i] << " ";
    }
    // find if temp is empty or contains characters that are not numerical taking words from stringstream ss >> temp
    while(ss >> temp)
    {
        if(temp.empty() || temp.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cout << "Invalid input" << std::endl;
            return 1;
        }
        
        n = std::stoi(temp);
        t.push_back(n);
    }
    // step 1 : split the sequence into couples then sort them each couple largest first then smallest
    // if there's an odd number of elements we'll have a struggling part save it for later
    std::vector<std::vector<int> > couples;
    std::vector<int> couple;
    if (t.size() % 2 != 0)
    {
        couple.push_back(t[t.size() - 1]);
        couples.push_back(couple);
        couple.clear();
        t.pop_back();
    }
    std::cout << "t.size() = " << t.size() << std::endl;

    // for (size_t i = 0; i < t.size(); i += 2)
    // {
    //     if(t[i] < t[i + 1])
    //     {
    //         std::cout << "t[i] < t[i + 1]" << std::endl;
    //         couple.push_back(t[i + 1]);
    //         couple.push_back(t[i]);
    //     } else {
    //         std::cout << "t[i] > t[i + 1]" << std::endl;
    //         couple.push_back(t[i]);
    //         couple.push_back(t[i + 1]);
    //     }
    //     couples.push_back(couple);
    //     couple.clear();
    // }
    // sort couples recursively
    recursive_sort(t, couples);
    ///debug : print couples
    std::cout << "Couples" << std::endl;
    for (size_t i = 0; i < couples.size(); i++)
    {
        for (size_t j = 0; j < couples[i].size(); j++)
        {
            std::cout << couples[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // step 2 : create two sequences one for largest elements and one for smallest elements in each part
    std::vector<int> smallest;
    std::vector<int> largest;
    for (size_t i = 0; i < couples.size(); i++)
    {
        smallest.push_back(couples[i][1]);
        largest.push_back(couples[i][0]);
    }
    
    return 0;
}