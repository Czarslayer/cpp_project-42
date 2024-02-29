#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
    std::cout << "Bureaucrat param constructor called" << std::endl;
    if(grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    return *this;
}

void    Bureaucrat::incrementGrade() {
    std::cout << "you just called the increment function" << std::endl;
    if(_grade - 1 > 0)
        _grade -= 1;
    else
        throw GradeTooHighException();
}

void    Bureaucrat::decrementGrade() {
    std::cout << "you just called the decrement function" << std::endl;
    if(_grade + 1 < 150)
        _grade += 1;
    else
        throw GradeTooLowException();
}

int Bureaucrat::getGrade() const {
    return(_grade);
}

std::string const Bureaucrat::getName() const {
    return(_name);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bur) {
    out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signs " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "i think it's too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "i think it's too low";
}