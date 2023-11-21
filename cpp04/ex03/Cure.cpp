#include "Cure.hpp"

Cure::Cure() : AMateria() {
    type = "cure";
}

Cure::Cure(const Cure &copy) : AMateria(copy) {
    this->type = copy.type;
}

Cure::~Cure() {
}

Cure &Cure::operator=(const Cure &copy) {
    this->type = copy.type;
    return(*this);
}

AMateria* Cure::clone() const {
    return(new Cure(*this));
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

