#include <vector>
#include <iostream>

int return_index(std::vector<int> &v, int value)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] >= value && v[i-1] && v[i-1] < value)
        {
            return (i + 2);
        }
    }
    return -1;
}

int main()
{
    std::vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(11);
    v.push_back(21);
    int value = 3;
    std::cout << return_index(v, value) << std::endl;
    return 0;
}