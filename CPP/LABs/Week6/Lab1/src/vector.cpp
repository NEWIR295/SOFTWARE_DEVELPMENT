/*
Author: Mohamed Newir
Date: 8/03/2025
File: vector.cpp
Description:
            implement vector class using templates and specialization 
            to store data in an array of size Size
            - static vector: store the data in an array of size Size
            - dynamic vector: store the data in an array of size Size using pointers 
*/

#include <iostream>

/*
    Vector class
    - T: template type
    - Size: size of the vector
    - static vector: store the data in an array of size Size
*/
template <typename T, int Size>
class Vector
{

private:
    int count = 0;
    T arr[Size];

public:
    Vector()
    {
        std::cout << "static vector" << std::endl;
    }

    Vector &pushPack(T var)
    {
        if (count < Size)
        {
            arr[count] = var;
            count++;
        }

        return *this;
    }

    void display(void)
    {
        for (int i = 0; i < count; i++)
        {
            std::cout << *(arr + i) << " ";
        }

        std::cout << std::endl;
    }

    ~Vector()
    {
    }
};

/*
    Vector class
    - T: template type
    - Size: size of the vector
    - dynamic vector: store the data in an array of size Size using pointers
*/
template <typename T, int Size>
class Vector<T *, Size>
{

private:
    int count = 0;
    T *ptr;

public:
    Vector()
    {
        std::cout << "dynamic vector" << std::endl;
        ptr = new T[Size];
    }
    Vector &pushPack(T var)
    {
        if (count < Size)
        {
            ptr[count] = var;
            count++;
        }
        return *this;
    }
    void display(void)
    {
        for (int i = 0; i < count; i++)
        {
            std::cout << *(ptr + i) << " ";
        }
        std::cout << std::endl;
    }
    ~Vector()
    {
        delete[] ptr;
    }
};

int main(void)
{
    Vector<int, 5> x;
    x.pushPack(5).pushPack(3);
    x.display();
    x.pushPack(4).pushPack(2);
    x.display();
    x.pushPack(1);
    x.display();
    x.pushPack(0);
    x.display();

    Vector<int *, 4> y;
    y.pushPack(0).pushPack(1).pushPack(3);
    y.display();
    y.pushPack(2).pushPack(5);
    y.display();
}
