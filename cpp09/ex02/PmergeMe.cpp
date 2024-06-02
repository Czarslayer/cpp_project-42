
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <utility>

//debuger the vector print function
void print_vector(std::vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

//debug victor print function from iterator to another iterator
void print_vector(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = start; it != end; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

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
#define green "\033[1;32m"
#define red "\033[1;31m"
#define blue "\033[1;34m"
#define yellow "\033[1;33m"
#define reset "\033[0m"
std::vector<int> jacob_index_generator(std::vector<int> &jacobsthals, int size)
{
    std::cout << green << std::endl;
    std::cout << "=====================<inside generator>======================" << std::endl;
    print_vector(jacobsthals);

    std::vector<int> jacobsthals_indexed;
    int jacob = 0;
    for (size_t i = 0; i < jacobsthals.size(); i++)
    {
        jacob = jacobsthals[i];
        if (jacob <= size)
            jacobsthals_indexed.push_back(jacob);
        while (jacob > 0 && jacobsthals[i] != 1 && std::find(jacobsthals_indexed.begin(), jacobsthals_indexed.end(), --jacob) == jacobsthals_indexed.end())
        {
            if (jacob > size)
            {
                continue;
            }
            std::cout << "pushing " << jacob << std::endl;
            jacobsthals_indexed.push_back(jacob);
            //jacob--;
        }
    }

    print_vector(jacobsthals_indexed);
    // remove one 1 from the beginning of the sequence
    jacobsthals_indexed.erase(jacobsthals_indexed.begin());
    std::cout << "removed the first 1" << std::endl;
    print_vector(jacobsthals_indexed);
    std::cout << std::endl;
    std::cout << "the size of the sequence is " << size << std::endl;
    std::cout << reset << std::endl;
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
    print_vector(smallest);

    std::cout << "Largest" << std::endl;
    print_vector(largest);

    // step 3 : create a Jacobsthal sequence with the lenght of the two sequences combined
    std::vector<int> jacobsthals;
    std::vector<int> jacobsthals_indexed;
    int jacob = 0;
    for (size_t i = 2; i < smallest.size() + largest.size(); i++)
    {
        jacob = Jacobsthal(i);
        if (jacob > smallest.size())
        {
        jacobsthals.push_back(jacob);
            break;
        }
        jacobsthals.push_back(jacob);
    }
    std::cout << "Jacobsthal" << std::endl;
    jacobsthals_indexed = jacob_index_generator(jacobsthals, smallest.size());
    print_vector(jacobsthals_indexed);

    // Print jacobian
    std::cout << "Jacobian" << std::endl;
    print_vector(jacobsthals);

    // step 4 : insert the first element becuase it's the smallest
    largest.insert(std::upper_bound(largest.begin(), largest.end(), smallest[0]), smallest[0]);
    std::cout << "pushed the smallest " << smallest[0] << std::endl;

    // step 5 : insert the LARGEST sequence using the jacobian sequence to smallest sequence using upper bound and using jacob sequence as index
    std::cout << yellow << "===> the insertion <===" << std::endl;
    for (size_t i = 0; i < jacobsthals.size(); i++)
    {
        // std::cout << "Last Jacobian index " << i << std::endl;
        std::cout << "//&&&&&&&&&//" << std::endl;
        std::cout << "smallest size " << smallest.size() << std::endl;
        std::cout << "largest size " << largest.size() << std::endl;
        std::cout << "jacobsthals[i] " << jacobsthals[i] << std::endl;
        std::cout << "//&&&&&&&&&//" << std::endl;


        if (jacobsthals[i] < smallest.size())
        {// 
            std::cout << ">>Inserting " << jacobsthals[i] << std::endl;
            std::cout << ">>Inserting " << smallest[jacobsthals[i]] << std::endl;

            std::cout << "Searching area for upper bound" << std::endl;
            std::cout << "calculating the upper bound for " << std::pow(2, i) - 1 << " in the largest sequence" << std::endl;
            std::cout << "//&&&&&&&&&//" << std::endl;
            print_vector(largest.begin(), largest.begin() + std::pow(2, i) - 1);
            std::cout << "//&&&&&&&&&//" << std::endl;

            largest.insert(std::upper_bound(largest.begin(), largest.begin() + std::pow(2, i) - 1 /*+ (i - 2)*/, smallest[jacobsthals[i]]), smallest[jacobsthals[i]]);

            std::cout << "jacobsthals[i] = " << i << std::endl;
            std::cout << std::endl;
            std::cout << "Inserting " << smallest[jacobsthals[i]] << std::endl;
            std::cout << "largest" << std::endl;
            if (largest.size() > 0)
            {
                for (size_t i = 0; i < largest.size(); i++)
                {
                    std::cerr << "largest size: " << largest.size() << " index " << i << " = " << largest[i] << std::endl;
                }
                std::cout << std::endl;
                std::cout << "===========================================" << std::endl;
            }
        }
    }
    std::cout << reset << std::endl;

    // step 4 : insert the STRUGGLING part using upper bound of the LARGEST sequence
    if (!struggling.empty())
    {
        largest.insert(std::upper_bound(largest.begin(), largest.end(), struggling[0]), struggling[0]);
    }


    // Print largest
    std::cout << "Largest" << std::endl;
    print_vector(largest);


    
    return 0;
}
