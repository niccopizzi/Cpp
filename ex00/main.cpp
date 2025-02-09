#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string input;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    else
    {
        for (int i = 1; i < ac; i++)
            input += av[i];
        for (std::string::iterator i = input.begin(); i != input.end(); i++)
        {
            std::cout << static_cast <char>(toupper(*i));
        }
        std::cout << std::endl;
    }
    return 0;
}