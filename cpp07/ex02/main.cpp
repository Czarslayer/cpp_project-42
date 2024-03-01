#include "Array.hpp"

int main()
{
	Array<int> intArray(5);
	Array<char> charArray(5);
	Array<float> floatArray(5);

	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i + 1;
	for (unsigned int i = 0; i < charArray.size(); i++)
		charArray[i] = 'a' + i;
	for (unsigned int i = 0; i < floatArray.size(); i++)
		floatArray[i] = i + 1 + 0.1;

	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
	for (unsigned int i = 0; i < charArray.size(); i++)
		std::cout << charArray[i] << std::endl;
	for (unsigned int i = 0; i < floatArray.size(); i++)
		std::cout << floatArray[i] << std::endl;
	return 0;
}