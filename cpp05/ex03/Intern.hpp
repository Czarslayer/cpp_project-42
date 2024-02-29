#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <string>



class Intern {
public:
    Intern();
    Intern(Intern const &copy);
	~Intern();
    Intern &operator=(Intern const &copy);

    AForm *makeForm(std::string const &name, std::string const &target);
    AForm *createPresidentialPardonForm(std::string const &target);
    AForm *createRobotomyRequestForm(std::string const &target);
    AForm *createShrubberyCreationForm(std::string const &target);

	class FormNotFoundException : public std::exception {
		public:
			virtual const char* what() const throw(){
				return ("Form not found");
			}
	};
};

#endif