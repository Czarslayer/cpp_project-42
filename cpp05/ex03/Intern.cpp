#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(Intern const &copy) {
    *this = copy;
}

Intern::~Intern() {
}

Intern &Intern::operator=(Intern const &copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string const &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
    int i = 0;
    std::string _formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
AForm *(Intern::*_formCreators[3])(std::string const &target) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};
    while(i < 3) {
        if (name == _formNames[i]) {
            std::cout << "Intern creates " << name << " form" << std::endl;
            return (this->*_formCreators[i])(target);
        }
        i++;
    }
    std::cout << "Intern can't create " << name << " form" << std::endl;
	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}