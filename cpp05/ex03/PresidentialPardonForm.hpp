#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm {
private:
    std::string _target;
public:
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &copy);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

    std::string const getTarget() const;
    void execute(Bureaucrat const &executor) const;
};

#endif