#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <cmath>

// Merge helper function
void merge(std::vector<std::pair<int, int>>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<std::pair<int, int>> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
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
void mergeSort(std::vector<std::pair<int, int>>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

std::vector<int> jacob_index_generator(std::vector<int>& jacobsthals) {
    std::vector<int> jacobsthals_indexed;
    int jacob = 0;
    for (size_t i = 0; i < jacobsthals.size(); i++) {
        jacob = jacobsthals[i];
        jacobsthals_indexed.push_back(jacob);
        while (jacob > 0 && std::find(jacobsthals_indexed.begin(), jacobsthals_indexed.end(), --jacob) == jacobsthals_indexed.end()) {
            jacobsthals_indexed.push_back(jacob);
        }
    }
    jacobsthals_indexed.erase(jacobsthals_indexed.begin());
    return jacobsthals_indexed;
}

int Jacobsthal(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

void recursive_sort(std::vector<std::pair<int, int>>& couples) {
    mergeSort(couples, 0, couples.size() - 1);
}

int main(int argc, char const *argv[]) {
    std::vector<int> t;
    int n;
    std::stringstream ss;
    std::string temp;

    for (int i = 1; i < argc; i++) {
        ss << argv[i] << " ";
    }

    while (ss >> temp) {
        if (temp.empty() || temp.find_first_not_of("0123456789") != std::string::npos) {
            std::cout << "Invalid input" << std::endl;
            return 1;
        }
        n = std::stoi(temp);
        t.push_back(n);
    }

    std::vector<std::pair<int, int>> couples;
    std::vector<int> struggling;

    if (t.size() % 2 != 0) {
        struggling.push_back(t.back());
        t.pop_back();
    }

    for (size_t i = 0; i < t.size(); i += 2) {
        couples.push_back(std::make_pair(t[i], t[i + 1]));
    }

    recursive_sort(couples);

    std::vector<int> smallest;
    std::vector<int> largest;
    for (size_t i = 0; i < couples.size(); i++) {
        smallest.push_back(couples[i].second);
        largest.push_back(couples[i].first);
    }

    std::vector<int> jacobsthals;
    for (size_t i = 1; i < smallest.size() + largest.size(); i++) {
        jacobsthals.push_back(Jacobsthal(i));
    }
    jacobsthals = jacob_index_generator(jacobsthals);

    std::cout << "Smallest: ";
    for (const int& val : smallest) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Largest: ";
    for (const int& val : largest) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Jacobsthal: ";
    for (const int& val : jacobsthals) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    largest.insert(std::upper_bound(largest.begin(), largest.end(), smallest[0]), smallest[0]);

    for (size_t i = 2; i < jacobsthals.size(); i++) {
        if (jacobsthals[i] < smallest.size()) {
            largest.insert(std::upper_bound(largest.begin(), largest.begin() + std::pow(2, jacobsthals[i]) - 1 + (i - 2), smallest[jacobsthals[i]]), smallest[jacobsthals[i]]);
            std::cout << "distance is =>" << std::pow(2, jacobsthals[i]) - 1 + (i - 2) << std::endl; 
        }
    }

    if (!struggling.empty()) {
        largest.insert(std::upper_bound(largest.begin(), largest.end(), struggling[0]), struggling[0]);
    }

    std::cout << "Sorted sequence: ";
    for (const int& val : largest) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
