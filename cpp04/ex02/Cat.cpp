#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, "Cat idea");
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = copy.type;
    this->brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, copy.brain->getIdea(i));
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignation operator called" << std::endl;
    this->type = copy.type;
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, copy.brain->getIdea(i));
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