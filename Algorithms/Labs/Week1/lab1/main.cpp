#include <iostream>
#include <vector>
#include <algorithm>

/*
    bubble sort implementation for containers
*/
template <typename T>
void bubbleSort(T &container)
{
    for (auto it1 = container.begin(); it1 != container.end(); it1++)
    {
        for (auto it2 = container.begin(); it2 != container.end(); it2++)
        {
            if (*it1 < *it2)
            {
                std::swap(*it1, *it2);
            }
        }
    }
}

/*
    Selection Sort
*/
template <typename T>
void selectionSort(T &container)
{
    for (auto it = container.begin(); it != container.end(); it++)
    {
        if (*it < *(it+1))
        {
            std::swap(*it, *(it+1));
        }
    }
}

int main(void)
{
    std::cout << "Bubble Sort" << std::endl;
    std::vector<int> vec{5, 1, 7, 3, 0, 2};
    bubbleSort(vec);
    for (auto i : vec)
    {
        std::cout << i << "\t";
    }
    std::cout << "\n";

    std::cout << "Selection Sort" << std::endl;
    std::vector<int> vec2{5, 1, 7, 3, 0, 2};
    selectionSort(vec);
    for (auto i : vec2)
    {
        std::cout << i << "\t";
    }
    std::cout << "\n";

    return 0;
}