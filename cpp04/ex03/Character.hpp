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
        virtual ~Character();
        Character &operator=(const Character &copy);
        virtual std::string const & getName() const;
        virtual void equip(AMateria* material);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
        void ADD_to_g_inventory(AMateria* materia);
};

#endif