/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
    This program demonstrates the use of the STL algorithms accumulate, max_element, min_element, and sort.
    The program calculates the total sales, max sales, min sales, and sorts the sales dataset in descending order.
*/

#include <iostream> 
#include <vector>
#include <algorithm>
#include <numeric>

int main(void){

    std::vector<int> salesDataset{1000, 2000, 3000, 4000, 5000, 500, 100};
    
    int sum = std::accumulate(salesDataset.begin(), salesDataset.end(), 0);
    std::cout << "Total Sales: " << sum << std::endl;

    auto max = std::max_element(salesDataset.begin(), salesDataset.end());
    std::cout << "Max Sales: " << *max << std::endl;

    auto min = std::min_element(salesDataset.begin(), salesDataset.end());
    std::cout << "Min Sales: " << *min << std::endl;

    std::sort(salesDataset.begin(), salesDataset.end(), std::greater<int>());
    std::cout << "Sorted Sales: ";
    for(auto i : salesDataset){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}