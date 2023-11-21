#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inventory[4];
    public:
        Character();
        Character(std::string name);
        Character(const Character &copy);
        ~Character();
        Character &operator=(const Character &copy);
        std::string const & getName() const;
        void equip(AMateria* material);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void ADD_to_g_inventory(AMateria* materia);
};

#endif