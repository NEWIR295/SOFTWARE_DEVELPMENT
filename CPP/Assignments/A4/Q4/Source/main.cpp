/*
Author: Mohamed Newir
Date: 10/03/2025
File: shape.hpp
Description: testing virtual destructors for Shape, Circle classes
*/

#include <iostream>
#include "../Include/shape.hpp"

int main(void)
{

    Shape *s = new Circle;
    delete s;

    return 0;
}
