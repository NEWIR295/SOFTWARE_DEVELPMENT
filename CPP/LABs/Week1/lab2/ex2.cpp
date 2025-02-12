#include <iostream>

class Complex
{
public:
    float i;
    float j;
    void sum(Complex c1, Complex c2);
};

void Complex::sum(Complex c1, Complex c2)
{
    i = c1.i + c2.i;
    j = c1.j + c2.j;
}

int main(int argc, char **argv)
{
    Complex c1, c2, c3;
    c1.i = 1;
    c1.j = 2;
    c2.i = 3;
    c2.j = 4;
    c3.sum(c1, c2);
    std::cout << "c3.i= " << c3.i << " , c3.j= " << c3.j << std::endl;
    return 0;
}