#include "Ice.hpp"

Ice::Ice() : AMateria() {
    type = "ice";
}

Ice::Ice(const Ice &copy) : AMateria(copy) {
    this->type = copy.type;
}

Ice::~Ice() {
}

Ice &Ice::operator=(const Ice &copy) {
    this->type = copy.type;
    return(*this);
}

AMateria* Ice::clone() const {
    return(new Ice(*this));
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}