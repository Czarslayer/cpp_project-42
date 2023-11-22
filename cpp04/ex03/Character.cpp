#include "Character.hpp"

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
    // Clean up the inventory array
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
        inventory[i] = NULL;
    }

    // Clean up the g_inventory linked list
    s_inventory *current = g_inventory;
    while (current != NULL) {
        s_inventory *next = current->next;
        delete current->materia;
        delete current;
        current = next;
    }

    g_inventory = NULL; // Reset the g_inventory pointer after cleanup
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
    while(i < 4 && this->inventory[i] != NULL)
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