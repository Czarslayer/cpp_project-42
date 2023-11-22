#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria; // whhy is this here? you : "because it's a forward declaration"
// WHY DO WE NEED IT HERE ITS ALREADY IN AMATERIA.HPP    you : "as u see"

class ICharacter
{
    public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif