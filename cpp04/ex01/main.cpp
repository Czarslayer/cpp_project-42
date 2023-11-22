#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    Animal *animals[10];
    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();
    for (int i = 0; i < 10; i++)
        delete animals[i];
std::cout << std::endl;
std::cout << std::endl;

    Dog dog;
    Dog dog1(dog);
    Dog dog2 = dog;

std::cout << std::endl;
std::cout << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    return 0;
}