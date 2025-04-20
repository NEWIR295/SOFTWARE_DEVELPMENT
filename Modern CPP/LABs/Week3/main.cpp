/*
    navigate through threads problem of race condition in multithreading 
*/

#include <iostream>
#include <thread>
#include <vector>

void print()
{
    std::cout << "hello " // cout is thread safe
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

        // vTh.push_back(std::thread(print)); // 3mlt thread(func) 3shan lazm y3ml hna temp object yhto fe push
        vTh.emplace_back(print); // emplace create object on fly mfesh 38l copy - direct insert
    }

    for (auto it = vTh.begin(); it != vTh.end(); it++)
    {
        it->join();
    }
    return 0;
}