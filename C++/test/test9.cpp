#include <iostream>

class Animal
{
public :
    int age;

    Animal (void);
    void running(void);

protected :
    std::string name;
};

class Pig : protected Animal
{
    public:
    void running(int);
};
int main()
{
    class Animal a1;
    a1.running();
    class Pig p1;
    p1.running(3);
    return 0;
}

void Animal::running(void)
{
    std::cout << name << " is running." << std::endl;
}

Animal::Animal (void)
{
    name = "yjh";
    age = 19;
}

void Pig::running (int)
{
    std::cout << "sss" << std::endl;
}