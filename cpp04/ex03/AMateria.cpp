#include "AMateria.hpp"

AMateria::AMateria() {
}

AMateria::AMateria(const AMateria &copy) {
    this->type = copy.type;
}

AMateria::~AMateria() {
}

std::string const &AMateria::getType() const {
    return(this->type);
}

AMateria &AMateria::operator=(const AMateria &copy) {
    this->type = copy.type;
    return(*this);
}

void AMateria::use(ICharacter &target) {
    std::cout << "czar zaml"<< std::endl;
    (void)target;
}


