#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy) {
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {
    if (this != &copy)
        this->_target = copy._target;
    return *this;
}

std::string const RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << "executing RobotomyRequestForm" << std::endl;
    if (std::rand() % 2)
        std::cout << this->getTarget() << " has been robotomized" << std::endl;
    else
        std::cout << this->getTarget() << " robotomization failed" << std::endl;
}

// Path: cpp05/ex02/main.cpp