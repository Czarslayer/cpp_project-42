#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, "Dog idea");
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    std::cout << "dog copy constructor called" << std::endl;
    this->type = copy.type;
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, copy.brain->getIdea(i));
}

Dog &Dog::operator=(const Dog &copy) {
    std::cout << "dog assignation operator called" << std::endl;
    this->type = copy.type;
    // copy all copy's array to this
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, copy.brain->getIdea(i));
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << "haw haw mf" << std::endl;
}