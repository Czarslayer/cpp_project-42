#include <iostream>


int main(int agc, char** argv)
{
    if (agc < 2)
    {
        std::cout << "* LOUD AND UNCLEAR NOISE *" << std::endl;
        return 1;
    }
    else
    {
        for (int i = 1; i < agc; i++)
        {
            for (int j = 0; argv[i][j]; j++)
            {
                std::cout << (char)std::toupper(argv[i][j]);
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
