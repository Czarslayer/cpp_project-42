#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;
public:
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const &copy);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

    std::string const getTarget() const;
    void execute(Bureaucrat const &executor) const;
};

#endif