
//
// Created by Mourad Abahani on 10/13/23.
//

#ifndef CPP_PROJECT_42_ZOMBIE_HPP
#define CPP_PROJECT_42_ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
    ~Zombie(void) {
        std::cout << P_name << " is dead" << std::endl;
    }
    Zombie(){}
    Zombie(std::string name) {
        P_name = name;
    }
    void       announce(void){
        std::cout << P_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
    void setname(std::string Name)
    {
        P_name = Name;
    }
private:
    std::string P_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif //CPP_PROJECT_42_ZOMBIE_HPP
