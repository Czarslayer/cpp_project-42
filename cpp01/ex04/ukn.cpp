//
// Created by Mourad Abahani on 10/15/23.
//

#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file for reading
    std::ifstream inputFile("Makefile");

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            // Process each line from the file
            std::cout << line << std::endl;
        }

        // Don't forget to close the file when you're done
        inputFile.close();
    } else {
        std::cerr << "Failed to open the file." << std::endl;
    }

    return 0;
}




