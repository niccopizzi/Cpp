#include "Zombie.hpp"

Zombie** zombieHorde( int N, std::string name )
{
    Zombie** theHorde = new Zombie*[N];

    if (N <= 0)
        return (nullptr);

    for (int i = 0; i < N; i++)
    {
        theHorde[i] = new Zombie(name);
    }
    return (theHorde);
}