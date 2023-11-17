#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    std::cout << "dog copy constructor called" << std::endl;
    this->type = copy.type;
}

Dog &Dog::operator=(const Dog &copy) {
    std::cout << "dog assignation operator called" << std::endl;
    this->type = copy.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "haw haw mf" << std::endl;
}