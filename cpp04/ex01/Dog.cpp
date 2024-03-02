#include "Dog.hpp"

Dog::Dog() : Animal() , brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy) , brain(new Brain(*copy.brain))
{
    std::cout << "dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
    std::cout << "dog assignation operator called" << std::endl;
    this->type = copy.type;

    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound()  {
    std::cout << "haw haw mf" << std::endl;
}