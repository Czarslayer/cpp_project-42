#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {
    if (this != &copy)
        this->_target = copy._target;
    return *this;
}

std::string const ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute() || this->getSigned() == false)
		throw AForm::GradeTooLowException();
    std::ofstream file;
    file.open(std::string(this->getTarget()).append("_shrubbery").c_str(), std::ios::out | std::ios::trunc);
    if (!file.is_open()){
        throw ShrubberyCreationForm::FileNotOpenException();
	}
	file << "       / \\" << std::endl;
	file << "      / * \\" << std::endl;
	file << "     / *** \\" << std::endl;
	file << "    / ***** \\" << std::endl;
	file << "   / ******* \\" << std::endl;
	file << "  / ********* \\" << std::endl;
	file << " / *********** \\" << std::endl;
	file << "/ ************* \\" << std::endl;
	file << "      ||||    " << std::endl;
	file << "  O   |O||    " << std::endl;
	file << "  |   ||||    " << std::endl;
	file << ";:;l;::;;l:l;:;l;l" << std::endl;
	file << std::endl;
    file.close();
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw() {
	return "File not open";
}