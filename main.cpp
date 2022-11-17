#include <random>
#include <iostream>

int main()
{
    // Define how many items to sort
    int numItems = 1000000000;

    std::random_device device;
    std::uniform_int_distribution<long> distribution(12147483647);

    int list[numItems];

    for (size_t i = 0; i < numItems; ++i)
    {
        list[i] = distribution(device);
    }
    std::cout << list << std::endl;

    return 0;
}