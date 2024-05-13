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

std::vector<int> jacob_index_generator(std::vector<int> &jacobsthals)
{

    std::vector<int> jacobsthals_indexed;
    int jacob = 0;
    for (size_t i = 0; i < jacobsthals.size(); i++)
    {
        jacob = jacobsthals[i];
        jacobsthals_indexed.push_back(jacob);
        while (jacob > 0 && std::find(jacobsthals_indexed.begin(), jacobsthals_indexed.end(), --jacob) == jacobsthals_indexed.end())
        {
            jacobsthals_indexed.push_back(jacob);
            jacob--;
        }
    }
    // remove one 1 from the beginning of the sequence
    jacobsthals_indexed.erase(jacobsthals_indexed.begin());
    return jacobsthals_indexed;
}

int Jacobsthal(int n)
{
    if (n == 0)
        return 0;
 
    if (n == 1)
        return 1;
 
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void recursive_sort(std::vector<int> &t, std::vector<std::vector<int> > &couples)
{
    std::vector<int> couple;

    // Sort each couple largest first then smallest
    for (size_t i = 0; i < couples.size(); ++i) {
        if (couples[i][0] < couples[i][1]) {
            std::swap(couples[i][0], couples[i][1]);
        }
    }
    //test swaping two couple vectors
     std::swap(couples[0], couples[1]);

    // Continue with the remaining steps of the algorithm
    // You can implement these steps here recursively
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

    for (size_t i = 0; i < t.size(); i += 2)
    {
        couple.push_back(t[i]);
        couple.push_back(t[i + 1]);
        couples.push_back(couple);
        couple.clear();
    }

    // sort couples recursively
    recursive_sort(t, couples);
    
    // Print couples
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

    // Print smallest and largest
    std::cout << "Smallest" << std::endl;
    for (size_t i = 0; i < smallest.size(); i++)
    {
        std::cout << smallest[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Largest" << std::endl;
    for (size_t i = 0; i < largest.size(); i++)
    {
        std::cout << largest[i] << " ";
    }
    std::cout << std::endl;

    // step 3 : create a Jacobsthal sequence with the lenght of the two sequences combined
    std::vector<int> jacobsthals;
    int jacob = 0;
    for (size_t i = 1; i < smallest.size() + largest.size(); i++)
    {
        jacob = Jacobsthal(i);
        jacobsthals.push_back(jacob);
    }
    jacobsthals = jacob_index_generator(jacobsthals);

    // Print jacobian
    std::cout << "Jacobian" << std::endl;
    for (size_t i = 0; i < jacobsthals.size(); i++)
    {
        std::cout << jacobsthals[i] << " ";
    }
    std::cout << std::endl;

    // step 4 : insert the LARGEST sequence using the jacobian sequence to smallest sequence using upper bound and using jacob sequence as index
    int last_jacobian = 0;
    for (size_t i = 0; i < jacobsthals.size(); i++)
    {
        if (jacobsthals[i] < largest.size())
        {
            std::cout << ">>Inserting " << jacobsthals[i] << std::endl;
            smallest.insert(std::upper_bound(smallest.begin(), smallest.end(), largest[jacobsthals[i]]), largest[jacobsthals[i]]);
            std::cout << "Inserting " << largest[jacobsthals[i]] << std::endl;
            std::cout << "Smallest" << std::endl;
            for (size_t i = 0; i < smallest.size(); i++)
            {
                std::cout << smallest[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "===========================================" << std::endl;
        }
    }

    // step 5 : insert the STRUGGLING part using upper bound of the LARGEST sequence
    if (!couple.empty())
    {
        std::upper_bound(largest.begin(), largest.end(), couple[0]);
    }

    // Print smallest
    std::cout << "Smallest" << std::endl;
    for (size_t i = 0; i < smallest.size(); i++)
    {
        std::cout << smallest[i] << " ";
    }
    std::cout << std::endl;


    
    return 0;
}
