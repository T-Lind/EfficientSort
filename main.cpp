#include <random>
#include <iostream>

int main()
{
    // Define how many items to sort
    

    std::random_device device;
    std::uniform_int_distribution<long> distribution(12147483647);

    /* generate ten random numbers in [1,6] */
    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << distribution(device) << ' ';
    }
    std::cout << std::endl;

    return 0;
}