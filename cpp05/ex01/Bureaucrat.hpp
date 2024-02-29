#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
#include "Form.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

class Form;

class Bureaucrat {
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    ~Bureaucrat();
    Bureaucrat &operator=(Bureaucrat const &copy);

    std::string const getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form);
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw() {
            return ("i think it's too high");
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what()  const throw(){
            return ("i think it's too low");
        }
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const & bureau);
#endif