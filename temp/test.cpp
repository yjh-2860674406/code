#include <iostream>

using namespace std;

class Animal 
{
    public :
    string m_name;
    int m_age;
    int m_weight;

    Animal (string name, int age, int weight)
    {
        m_name = name;
        m_age = age;
        m_weight = weight;
    }

    virtual void play ();
};

class Dog : public Animal
{
    void play ()
    {
        printf("%s is running !", m_name);
    }
};

int main()
{
    Dog YJh ("YJH", 19, 150);
}