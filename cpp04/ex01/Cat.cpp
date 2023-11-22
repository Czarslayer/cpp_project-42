#include "Cat.hpp"

Cat::Cat() : Animal() , brain(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy) , brain(new Brain(*copy.brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = copy.type;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignation operator called" << std::endl;
    this->type = copy.type;
    if (this != &copy)
        *(this->brain) = *(copy.brain);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow nigga" << std::endl;

}