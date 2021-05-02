#include <iostream>

class Animal
{
public :
    std::string name;
    int age;
    float weight;

    virtual void playing ();
    void running ();
};

class Dog:public Animal
{
public :
    void playing ();
};

int main()
{
    Animal *dog = new Dog();
    dog->name = "yjh";
    dog->playing();
    return 0;
}

void Animal::running ()
{
    using namespace std;
    cout << name << " is running" << endl;
}

void Animal::playing ()
{
    using namespace std;
    cout << name << " is playing" << endl;
}

void Dog::playing ()
{
    using namespace std;
    cout << name << " is chasing the ball" << endl;
}