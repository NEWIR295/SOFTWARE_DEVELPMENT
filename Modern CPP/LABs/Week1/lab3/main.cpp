#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main(void)
{

    std::vector<int> vec{-1, 1, 0, 3, -4, -2, -3, 6};
    std::set<int> set1;

    std::sort(vec.begin(), vec.end(), [&set1](int a, int b)
        {

        if(a < 0 && set1.find(a) == set1.end()){
            set1.emplace(a);
            std::cout << a << "\n";
        }
        if(b < 0 && set1.find(b) == set1.end()){
            set1.emplace(b);
            std::cout << b << "\n";
        }
        return abs(a) < abs(b); });

    for (auto i : vec)
    {
        std::cout << i * i << "\t";
    }
    std::cout << "\n";
    return 0;
}