#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* zombiearray = new Zombie[N]; // allocating an array of Zombie class 
    for(int i = 0; i < N; i++)
        zombiearray[i].setname(name); // here we're calling the setname method to set that name to every zombie
    return zombiearray;
}