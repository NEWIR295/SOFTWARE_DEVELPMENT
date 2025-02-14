/*
Author: Mohamed Newir
Date: 14/02/2025
File: family.cpp
Description: family source show inheritance concepts 
*/

#include "family.hpp"

M_Grand_Parent::M_Grand_Parent()
{
    std::cout << " M_Grand_Parent Constructor " << std::endl;
}
M_Grand_Parent::~M_Grand_Parent()
{
    std::cout << " M_Grand_Parent Destructor " << std::endl;
}
M_Parent::M_Parent()
{
    std::cout << " M_Parent Constructor " << std::endl;
}
M_Parent::~M_Parent()
{
    std::cout << " M_Parent Destructor " << std::endl;
}
Parent::Parent()
{
    std::cout << " Parent Constructor " << std::endl;
}
Parent::~Parent()
{
    std::cout << " Parent Destructor " << std::endl;
}
Son::Son()
{
    std::cout << " Son Constructor " << std::endl;
}
Son::~Son()
{
    std::cout << " Son Destructor " << std::endl;
}
Grand_Son::Grand_Son()
{
    std::cout << " Grand_Son Constructor " << std::endl;
}
Grand_Son::~Grand_Son()
{
    std::cout << " Grand_Son Destructor " << std::endl;
}
