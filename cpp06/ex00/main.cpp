#include "ScalarConversion.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    ScalarConversion sc(argv[1]);
    sc.convert();
    return 0;
}