#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform binary search and insert an element into a sorted vector
void binaryInsert(std::vector<int>& sortedVec, int element) {
    std::vector<int>::iterator it = std::upper_bound(sortedVec.begin(), sortedVec.end(), element);
    sortedVec.insert(it, element);
}
int i = 0;
// Merge-Insertion Sort function
void mergeInsertionSort(std::vector<int>& X) {
    i += 1;
    int n = X.size();
    if (n <= 1)
        return;

    // Step 1: Divide input into pairs
    std::vector<int> largerElements;

    for (int i = 0; i < n - 1; i += 2) {
        if (X[i] > X[i + 1]) {
            largerElements.push_back(X[i]);
            X[i] = X[i + 1];
        } else {
            largerElements.push_back(X[i + 1]);
        }
    }

    //print Largest Elements
    std::cout << "Largest Elements: ";
    for (std::vector<int>::iterator it = largerElements.begin(); it != largerElements.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "try number :" << i << std::endl;

    // Step 3: Recursively sort larger elements
    mergeInsertionSort(largerElements);
           std::cout << "Largest Elements befor binary insert: ";
    for (std::vector<int>::iterator it = largerElements.begin(); it != largerElements.end(); ++it) {
        std::cout << *it << " ";
    }

    // Step 4: Insert smaller elements into sorted sequence
    binaryInsert(largerElements, X[0]);
       std::cout << "Largest Elements after binary insert: ";
    for (std::vector<int>::iterator it = largerElements.begin(); it != largerElements.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "try number :" << i << std::endl;

    // Step 5: Insert remaining unpaired elements
    for (int i = 2; i < n; i += 2) {
        binaryInsert(largerElements, X[i]);
    }

    // Copy sorted elements back to the original vector
    X.swap(largerElements);
}

int main() {
    std::vector<int> X;
    X.push_back(12);
    X.push_back(5);
    X.push_back(7);
    X.push_back(2);
    X.push_back(10);
    X.push_back(4);
    X.push_back(3);
    X.push_back(8);
    X.push_back(1);
    X.push_back(6);
    X.push_back(9);
    X.push_back(11);
    
    // Perform Merge-Insertion Sort
    mergeInsertionSort(X);

    // Output sorted sequence
    std::cout << "Sorted sequence: ";
    for (std::vector<int>::iterator it = X.begin(); it != X.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}