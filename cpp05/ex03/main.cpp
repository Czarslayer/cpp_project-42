#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat bur("morad", 0);
        std::cout << bur << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
    try
    {
        Bureaucrat bur("morad", 151);
        std::cout << bur << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
    try
    {
        Bureaucrat bur("morad", 150);
        std::cout << bur << std::endl;
        bur.incrementGrade();
        std::cout << bur << std::endl;
        bur.decrementGrade();
        std::cout << bur << std::endl;
        bur.decrementGrade();
        std::cout << bur << std::endl;
        bur.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
    try
    {
        Bureaucrat bur("morad", 1);
        std::cout << bur << std::endl;
        bur.incrementGrade();
        std::cout << bur << std::endl;
        bur.incrementGrade();
        std::cout << bur << std::endl;
        bur.incrementGrade();
        std::cout << bur << std::endl;
        bur.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}