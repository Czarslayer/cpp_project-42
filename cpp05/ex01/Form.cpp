#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Form default constructor called" << std::endl;
}