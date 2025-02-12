#include <iostream>

int main(int argc, char **argv)
{
    int arraySize;
    int i;
    std::cout << "please enter array size: ";
    std::cin >> arraySize;
    int *ptr = new int[arraySize];
    for (i = 0; i < arraySize; i++)
    {
        std::cout << "please enter array " << i+1 << " value: ";
        std::cin >> *(ptr + i);
    }
    for (i = 0; i < arraySize; i++)
    {
        std::cout << "array "<< i+1 << " = " << *(ptr + i) << std::endl;
    }
    delete ptr;
    ptr = nullptr;
    return 0;
}
