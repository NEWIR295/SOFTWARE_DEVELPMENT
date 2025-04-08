
#include <iostream>
#include <vector>

int main(void){
    std::vector<int> vec1{1,2,3,4};
    for(auto num: vec1){
        std::cout << num << "\t" ; 
    }
    std::cout << "\n";
    std::vector<int> vec2 = std::move(vec1);
    for(auto num: vec2){
        std::cout << num << "\t" ; 
    }
    std::cout << "\n";
    if(vec1.empty()){
        std::cout << "vec1  is empty " << vec1.size() <<std::endl;
    }
}