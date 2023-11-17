#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource{
    private:
        AMateria *materia[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        virtual ~MateriaSource();
        MateriaSource &operator=(const MateriaSource &copy);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif