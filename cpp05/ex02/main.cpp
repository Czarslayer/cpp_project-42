//#include "Bureaucrat.hpp"
//#include "AForm.hpp"
//#include "PresidentialPardonForm.hpp"
//#include "RobotomyRequestForm.hpp"
//#include "ShrubberyCreationForm.hpp"

#include <iostream>

class A {
    private:
        int x;

    public:
        A const & operator=(A const & walo){
            if (this != &walo) {
                this->x = walo.x;
                std::cout << walo.x << std::endl;
            }
            return *this;
        }
};

class B : public A {
    public:
        B const & operator=(B const &walo) {
            if (this != &walo) {
                A::operator=(walo);
            }
            return *this;
        }
};


int main()
{
    B walo;

    B walo1;

    walo1 = walo;

   // esting PresidentialPardonForm
//   std::cout << RED << "------<<testing PresidentialPardonForm>>------" << RESET << std::endl;
//   try {
//	   Bureaucrat bur("morad", 2);
//	   std::cout << bur << std::endl;
//	   PresidentialPardonForm form("target");
//	   bur.signForm(form);
//	   bur.executeForm(form);
//   } catch (std::exception &e) {
//	   std::cout << e.what() << std::endl;
//   }
//   std::cout << RED << "------<<testing shurbbery>>------" << RESET << std::endl;
//   try {
//	   Bureaucrat bur("morad", 2);
//	   std::cout << bur << std::endl;
//	   ShrubberyCreationForm form("target");
//	   bur.signForm(form);
//	   bur.executeForm(form);
//   } catch (std::exception &e) {
//	   std::cout << e.what() << std::endl;
//   }
//   std::cout << RED << "------<<testing RobotomyRequestForm>>------" << RESET << std::endl;
//   try {
//	   Bureaucrat bur("morad", 2);
//	   std::cout << bur << std::endl;
//	   RobotomyRequestForm form("target");
//	   bur.signForm(form);
//	   bur.executeForm(form);
//   } catch (std::exception &e) {
//	   std::cout << e.what() << std::endl;
//   }
}