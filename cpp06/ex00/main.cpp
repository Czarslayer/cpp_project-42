#include "ScalarConversion.hpp"

void check_if_number_float(std::string str)
{
	int dot = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			dot++;
		if ((dot > 1 || (str[i] < '0' || str[i] > '9')) && str[i] != '.')
		{
			std::cerr << "Error: invalid input" << std::endl;
			exit(1);
		}
	}
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
	check_if_number_float(argv[1]);
    ScalarConversion sc(argv[1]);
    sc.convert();
    return 0;
}