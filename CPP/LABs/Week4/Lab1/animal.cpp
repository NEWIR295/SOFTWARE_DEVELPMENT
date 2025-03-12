#include <iostream>
class Animal
{

public:
    virtual void sound(void) = 0;
    virtual void move(void) final
    {
        std::cout << " Move " << std::endl;
    }
};

class Cat final : public Animal
{

public:
    void sound(void) override
    {
        std::cout << " Meow " << std::endl;
    }
};

class Dog : public Animal
{

public:
    void sound(void) override
    {
        std::cout << " HowHow " << std::endl;
    }

};
int main(int argc, char **argv)
{

    Dog d;
    Cat c;

    Animal *a_ptr = &d;
    a_ptr->sound();

    a_ptr->move();

    a_ptr = &c;
    a_ptr->sound();

    a_ptr->move();

    return 0;
}