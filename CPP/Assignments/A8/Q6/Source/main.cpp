/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
    This program demonstrates the use of the std::list container and the std::sort algorithm.
    The program creates a list of Person objects and sorts them in descending order based on their age.
    The program uses a custom comparator to sort the list.
    The program outputs the sorted list to the console.
*/

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

class Person{

    private:
        std::string name;
        int age;
        friend class PersonDescendingOrder;
    public:
        Person(std::string name, int age): name(name), age(age){}
        int getAge() const {return age;}
        std::string getName() const {return name;}
};

class PersonDescendingOrder {
    public:
        bool operator()(const Person &p1, const Person &p2) const
        {
            return p1.age > p2.age;
        }
};


int main()
{
    std::list<Person> people;
    people.push_back(Person("Mohamed", 25));
    people.push_back(Person("Ahmed", 30));
    people.push_back(Person("Ali", 20));
    people.push_back(Person("Omar", 35));
    people.push_back(Person("Khaled", 40));

    people.sort(PersonDescendingOrder());

    for (const auto &person : people)
    {
        std::cout << person.getName() << " " << person.getAge() << std::endl;
    }

    return 0;
}