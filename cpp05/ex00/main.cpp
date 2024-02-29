#include "Bureaucrat.hpp"

int main()
{
	std::cout << RED << "------<<testing constructor>>------" << RESET << std::endl;
    try {
        Bureaucrat bur("morad", 0);
        std::cout << bur << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << RED << "------<<testing constructor>>------" << RESET << std::endl;
    try {
        Bureaucrat bur("morad", 151);
        std::cout << bur << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << RED << "------<<testing decrement>>------" << RESET << std::endl;
    try {
        Bureaucrat bur("morad", 150);
        std::cout << bur << std::endl;
        bur.incrementGrade();
        std::cout << bur << std::endl;
        bur.decrementGrade();
        std::cout << bur << std::endl;
        bur.decrementGrade();
        std::cout << bur << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << RED << "------<<testing increment>>------" << RESET << std::endl;
    try {
        Bureaucrat bur("morad", 2);
        std::cout << bur << std::endl;
        bur.incrementGrade();
        std::cout << bur << std::endl;
        bur.incrementGrade();
        std::cout << bur << std::endl;
        bur.incrementGrade();
        std::cout << bur << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}