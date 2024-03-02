#include "AForm.hpp"


AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(AForm const &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
    std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm() {
    std::cout << "Form destructor called" << std::endl;
}

AForm::AForm(std::string const &name, int const gradeToSign, int const gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Form parameterized constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &copy) {
    std::cout << "Form assignation operator called" << std::endl;
    if (this != &copy)
        this->_signed = copy._signed;
    return *this;
}

std::string const AForm::getName() const {
    return this->_name;
}

bool AForm::getSigned() const {
    return this->_signed;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bur) {
    if (bur.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}