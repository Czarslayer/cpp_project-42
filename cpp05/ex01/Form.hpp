#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    std::string const _name;
    bool _signed;
    int const _gradeToSign;
    int const _gradeToExecute;
public:
    Form();
    Form(std::string const name, int gradeToSign, int gradeToExecute);
    Form(Form const &copy);
    ~Form();
    Form &operator=(Form const &copy);

    std::string const getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &bur);
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif