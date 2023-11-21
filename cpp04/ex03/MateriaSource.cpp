#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    for (int i = 0; i < 4; i++)
        materia[i] = copy.materia[i];
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete materia[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    for (int i = 0; i < 4; i++)
        materia[i] = copy.materia[i];
    return(*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if(materia == NULL)
        return;
    int i = 0;
    while(i < 4 && this->materia[i] != NULL)
        i++;
    if(i < 4)
        this->materia[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    while(i < 4 && this->materia[i]->getType() != type)
        i++;
    if(i < 4)
        return(this->materia[i]->clone());
    return(NULL);
}