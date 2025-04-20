#include <iostream>
#include <thread>
#include <vector>

void print()
{
    std::cout << "hello "
              << "C++ "
              << "student "
              << "to multithreading "
              << std::endl;
}

int main(void)
{

    std::vector<std::thread> vTh; // mynf3sh t allocate fe init 3shan hwa kda nada thread constructor
    for (int i = 0; i < 10; i++)
    {

        vTh.emplace_back(print);
    }

    for (auto it = vTh.begin(); it != vTh.end(); it++)
    {

        it->join();
    }
    return 0;
}