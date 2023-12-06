/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:38:47 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/30 15:46:43 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main(int ac, char **av) {
    size_t found = 0;
    if(ac == 4) {
        std::ifstream inputFile(av[1]);
        if (!inputFile.is_open()) {
            std::cerr << "Failed to open the input file Make sure the file:" << "make sure ["<< av[1] << "] exist." << std::endl;
            return 1;
        }

        std::ofstream outputFile(std::string(std::string(av[1]) + ".replace").c_str());
        if (!outputFile.is_open()) {
            std::cerr << "Failed to open the output file." << std::endl;
            return 1;
        }

        std::string line;
        while (std::getline(inputFile, line, '\0')) {
            while ((found = line.find(av[2],found)) != std::string::npos) {
                if(strlen(av[2]) == 0)
                    break;
                line.erase(found, strlen(av[2]));
                line.insert(found, av[3]);
                found += strlen(av[3]);
            }
            outputFile << line << std::endl;
        }

        inputFile.close();
        outputFile.close();

        std::cout << "File copied successfully." << std::endl;
    }
    return 0;
}