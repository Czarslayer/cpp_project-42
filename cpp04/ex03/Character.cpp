#include "Character.hpp"

struct s_inventory
{
    AMateria *materia;
    int idx;
    s_inventory *next;
};

extern s_inventory *g_inventory;

s_inventory *g_inventory = NULL;


Character::Character() {
    this->name = "default";
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string name) {
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character &copy) {
    this->name = copy.name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = copy.inventory[i];
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        delete this->inventory[i];
}

Character &Character::operator=(const Character &copy) {
    this->name = copy.name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = copy.inventory[i];
    return(*this);
}

std::string const &Character::getName() const {
    return(this->name);
}

void Character::equip(AMateria *material) {
    if(material == NULL)
        return;
    this->ADD_to_g_inventory(material);
    int i = 0;
    while(i < 4 && this->inventory[i] == NULL)
        i++;
    if(i < 4) {
        this->inventory[i] = material;
       // this->inventory[i]->use(*this);
    }
}

void Character::ADD_to_g_inventory(AMateria *materia) {
    if(g_inventory == NULL){
        g_inventory = new s_inventory;
        g_inventory->materia = materia;
        g_inventory->next = NULL;
        return;
    }

    s_inventory *current = g_inventory;
    while(current->next != NULL)
        current = current->next;

    s_inventory *new_inventory = new s_inventory;
    new_inventory->materia = materia;
    new_inventory->next = NULL;

    current->next = new_inventory;
}

void Character::unequip(int idx) {
    if(idx < 0 || idx > 3)
        return;
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if(idx >= 0 && idx < 4 && inventory[idx] != NULL){
        inventory[idx]->use(target);
    }
}