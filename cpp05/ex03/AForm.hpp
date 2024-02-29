#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>


class AForm {
private:
    std::string const _name;
    bool _signed;
    int const _gradeToSign;
    int const _gradeToExecute;
public:
    AForm();
    AForm(AForm const &copy);
    AForm(std::string const &name, int const gradeToSign, int const gradeToExecute);
    virtual ~AForm();
    AForm &operator=(AForm const &copy);

    virtual std::string const getName() const;
    virtual bool getSigned() const;
    virtual int getGradeToSign() const;
    virtual int getGradeToExecute() const;
    virtual void beSigned(Bureaucrat &bur);
    virtual void execute(Bureaucrat const &executor) const;

    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw() {
            return "Grade too high";
        }
    };

    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw() {
            return "Grade too low";
        }
    };
};


#endif