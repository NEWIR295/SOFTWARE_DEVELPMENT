#include <iostream>

class Complex
{
private:
    float i, j;

public:
    friend std::ostream &operator<<(std::ostream &os, const Complex &c1);

    Complex() : i(0), j(0)
    {
    }                    

    Complex(float i, float j) : i(i), j(j)
    {
    }

    // pre increment operator
    Complex &operator++()
    {
        this->i++;
        this->j++;
        return *this;
    }

    // Post increment operator
    Complex &operator++(int)
    {
        this->i++;
        this->j++;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, const Complex &c1)
{
    return os << "real =  " << c1.i << " , imagine = " << c1.j << std::endl;
}

int main(int argc, char **argv)
{

    Complex c1(1, 2);
    std::cout << c1;

    c1++;
    // std::cout << c1.i << " + " << c1.j << "j " << std::endl;
    std::cout << c1;

    ++c1;
    // std::cout << c1.i << " + " << c1.j << "j " << std::endl;

    std::cout << c1;
    Complex c2(1, 0);
    std::cout << c2;
}