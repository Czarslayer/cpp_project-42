#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <string>



class Intern {
public:
    Intern();
    Intern(Intern const &copy);
    virtual ~Intern();
    Intern &operator=(Intern const &copy);

    AForm *makeForm(std::string const &name, std::string const &target);
    AForm *createPresidentialPardonForm(std::string const &target);
    AForm *createRobotomyRequestForm(std::string const &target);
    AForm *createShrubberyCreationForm(std::string const &target);
};