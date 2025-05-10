/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Implementation of the Adapter Design Pattern
*/


#include <iostream>
#include <memory>
//target class
class USBC{

public:
    virtual  void connect(void){
        std::cout << "USB-C connected" << std::endl;
    }
};

//source class 
class Lightning{

public:
    void connect(void){
        std::cout << "Lightning connected" << std::endl;
    }
};

//adapter class
// wraps the Lightning class to make it compatible with the USBC interface
class Adapter: public USBC{

private:
    std::shared_ptr<Lightning> lightning;
public:
    Adapter(std::shared_ptr<Lightning> lightening): lightning(lightning){}

    void connect(void) override{
        lightning->connect();
        std::cout << "Adapter: Lightning to USB-C connected" << std::endl;
        USBC::connect();
    }
};

int main(void){

    std::shared_ptr<Lightning> lightning = std::make_shared<Lightning>();
    std::shared_ptr<USBC> usbc = std::make_shared<Adapter>(lightning);

    usbc->connect();

    return 0;

}