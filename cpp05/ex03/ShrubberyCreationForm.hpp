#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <fstream>

// random rand() function include <random> header file

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
public:
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

    std::string const getTarget() const;
    void execute(Bureaucrat const &executor) const;

    class FileNotOpenException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "File not open";
        }
    };
};

#endif