/*
Author: Mohamed Newir
Date: 14/02/2025
File: family.hpp
Description: family header show inheritance concepts 
*/

#ifndef FAMILY_HPP
#define FAMILY_HPP

#include <iostream>

class M_Grand_Parent
{
    public:
    M_Grand_Parent();
    ~M_Grand_Parent();
};

class M_Parent : public M_Grand_Parent
{
    public:
    M_Parent();
    ~M_Parent();
};

class Parent : public M_Parent
{
    public:
    Parent();
    ~Parent();
};

class Son : public Parent
{
    public:
    Son();
    ~Son();
};

class Grand_Son : public Son
{
    public:
    Grand_Son();
    ~Grand_Son();
};
#endif