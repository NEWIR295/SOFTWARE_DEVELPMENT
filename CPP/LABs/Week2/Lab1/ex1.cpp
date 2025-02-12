#include <iostream>
#include <cstring>

class Person
{
public:
    char *name;
    int age;

    Person() : name(nullptr)
    {
    }

    Person(const Person &other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
    }

    Person(const char *name, int age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }

    Person &operator=(const Person &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] name;
        age = other.age;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        return *this;
    }

    void displayInfo()
    {
        std::cout << "name is " << this->name << " and age = " << this->age << std::endl;
    }

    void modifyName(const char *n)
    {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Person()
    {
        delete[] name;
    }
};

int main(int argc, char **argv)
{

    Person p1("alice", 25);
    p1.displayInfo();
    Person p2;
    p2 = p1;
    p2.displayInfo();
    p2.modifyName("bob");
    p2.displayInfo();

    return 0;
}