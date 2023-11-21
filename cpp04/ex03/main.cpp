#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <stdlib.h>


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    bob->equip(tmp);
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete src;
    delete me;
    return 0;
}
