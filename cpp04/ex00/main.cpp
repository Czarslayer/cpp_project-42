#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();
    const Animal* d = new Cat();
    std::cout << std::endl;
    std::cout << "meta->getType(): " << meta->getType() << std::endl;
    std::cout << "j->getType(): " << j->getType() << std::endl;
    std::cout << "i->getType(): " << i->getType() << std::endl;
    std::cout << std::endl;
    i->makeSound(); //will output the wrong cat sound!
    j->makeSound();
    meta->makeSound();
    d->makeSound();
    std::cout << std::endl;
    delete meta;
    delete j;
    delete i;
    delete d;
    return 0;
}