/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Explain with a code example how std::weak_ptr is used to: 
                o Monitor the managed object's lifecycle. 
                o Prevent memory leaks in a scenario involving cyclic references between 
                    objects. Highlight the differences and connections between std::weak_ptr 
                    and std::shared_ptr.
*/

#include <iostream>
#include <memory>

class weak;
class shared{

public:
    std::shared_ptr<weak> sptr;
    ~shared(){
        std::cout << "shared class destroyed" << std::endl;
    }
};

class weak{

public:
    std::weak_ptr<shared> wptr;
    ~weak(){
        std::cout << "weak class destroyed" << std::endl;
    }
};

int main(){

    std::shared_ptr<shared> _s = std::make_shared<shared>() ;
    std::shared_ptr<weak> _w = std::make_shared<weak>();

    _s -> sptr = _w;
    _w -> wptr = _s;

    std::cout << "_s count = " << _s.use_count() << std::endl;
    std::cout << "_w count = " << _w.use_count() << std::endl;

    return 0;

}