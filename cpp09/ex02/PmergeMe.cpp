
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <utility>

// Merge helper function
void merge(std::vector<std::pair<int, int> >& arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<std::pair<int, int> > L(n1), R(n2);

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Recursive merge sort
void mergeSort(std::vector<std::pair<int, int> >& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

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
            //std::cout << "pushing " << jacob << std::endl;
            jacobsthals_indexed.push_back(jacob);
            //jacob--;
        }
    }
    // remove one 1 from the beginning of the sequence
    jacobsthals_indexed.erase(jacobsthals_indexed.begin());
    // for(int j = 0; j < jacobsthals.size(); j++)
    // {
    //     std::cout << "index" << j << " is" << jacobsthals[j] << std::endl;
    // }
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

void recursive_sort(std::vector<int> &t, std::vector<std::pair<int,int> > &couples)
{
    std::vector<int> couple;
    for (size_t i = 0; i < couples.size(); i++)
    {
        if (couples[i].first < couples[i].second)
        {
            std::swap(couples[i].first, couples[i].second);
        }
    }

    mergeSort(couples, 0, couples.size() - 1);
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
    std::vector<std::pair<int,int> > couples;
    std::vector<int> struggling;

    if (t.size() % 2 != 0)
    {
        struggling.push_back(t.back());
        t.pop_back();
    }

    // Split the sequence into couples
    for (size_t i = 0; i < t.size(); i += 2)
    {
        // make pairs of couples
        couples.push_back(std::make_pair(t[i], t[i + 1]));

    }


    for (size_t i = 0; i < couples.size(); i++)
    {
        std::cout << couples[i].first << " " << couples[i].second << std::endl;
    }

    
    // sort couples recursively
    recursive_sort(t, couples);
    

    // step 2 : create two sequences one for largest elements and one for smallest elements in each part
    std::vector<int> smallest;
    std::vector<int> largest;
    for (size_t i = 0; i < couples.size(); i++)
    {
        smallest.push_back(couples[i].second);
        largest.push_back(couples[i].first);    
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

    // trim the jacobsthals sequence to the size of the smallest sequence run through the sequence and remove any element that is greater than the size of the smallest sequence
    // for (size_t i = 0; i < jacobsthals.size(); i++)
    // {
    //     if (jacobsthals[i] >= smallest.size())
    //     {
    //         jacobsthals.erase(jacobsthals.begin() + i);
    //     }
    // }


    // Print jacobian
    std::cout << "Jacobian" << std::endl;
    for (size_t i = 0; i < jacobsthals.size(); i++)
    {
        std::cout << jacobsthals[i] << " ";
    }
    std::cout << std::endl;

    // step 4 : insert the first element becuase it's the smallest
    largest.insert(std::upper_bound(largest.begin(), largest.end(), smallest[0]), smallest[0]);
    std::cout << "pushed the smallest " << smallest[0] << std::endl;

    // step 5 : insert the LARGEST sequence using the jacobian sequence to smallest sequence using upper bound and using jacob sequence as index
    int last_jacobian = 0;
    for (size_t i = 2; i < jacobsthals.size(); i++)
    {
        // std::cout << "Last Jacobian index " << i << std::endl;
        if (jacobsthals[i] < smallest.size())
        {// 
            std::cout << ">>Inserting " << jacobsthals[i] << std::endl;
            largest.insert(std::upper_bound(largest.begin(), largest.begin() + std::pow(2, jacobsthals[i]) - 1 + (i - 2), smallest[jacobsthals[i]]), smallest[jacobsthals[i]]);
            std::cout << "Inserting " << smallest[jacobsthals[i]] << std::endl;
            std::cout << "largest" << std::endl;
            for (size_t i = 0; i < largest.size(); i++)
            {
                std::cout << largest[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "===========================================" << std::endl;
        }
    }

    // step 4 : insert the STRUGGLING part using upper bound of the LARGEST sequence
    if (!struggling.empty())
    {
        largest.insert(std::upper_bound(largest.begin(), largest.end(), struggling[0]), struggling[0]);
    }


    // Print smallest
    std::cout << "largest" << std::endl;
    for (size_t i = 0; i < largest.size(); i++)
    {
        std::cout << largest[i] << " ";
    }
    std::cout << std::endl;


    
    return 0;
}
