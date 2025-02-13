#include "Zombie.hpp"

int main(int argc, char *argv[])
{
    int     i;
    int     n;
    Zombie  **newHorde;

    n = 10;
    newHorde = zombieHorde(n, "Nino Frassica");
    i = 0;
    while (i < n && newHorde)
    {
        newHorde[i]->announce();
        delete newHorde[i];
        i++;
    }
    if (newHorde)
        delete[] newHorde;
    return (0);
}