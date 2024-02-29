#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
   // esting PresidentialPardonForm
   std::cout << RED << "------<<testing PresidentialPardonForm>>------" << RESET << std::endl;
   try {
	   Bureaucrat bur("morad", 2);
	   std::cout << bur << std::endl;
	   PresidentialPardonForm form("target");
	   bur.signForm(form);
	   bur.executeForm(form);
   } catch (std::exception &e) {
	   std::cout << e.what() << std::endl;
   }
   std::cout << RED << "------<<testing shurbbery>>------" << RESET << std::endl;
   try {
	   Bureaucrat bur("morad", 2);
	   std::cout << bur << std::endl;
	   ShrubberyCreationForm form("target");
	   bur.signForm(form);
	   bur.executeForm(form);
   } catch (std::exception &e) {
	   std::cout << e.what() << std::endl;
   }
   std::cout << RED << "------<<testing RobotomyRequestForm>>------" << RESET << std::endl;
   try {
	   Bureaucrat bur("morad", 2);
	   std::cout << bur << std::endl;
	   RobotomyRequestForm form("target");
	   bur.signForm(form);
	   bur.executeForm(form);
   } catch (std::exception &e) {
	   std::cout << e.what() << std::endl;
   }
}