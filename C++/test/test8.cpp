#include <iostream>

class Animal
{
    public :
    int weight;
    std::string name;

    void running (void);
};

class Pig : public Animal{}; // 继承

int main()
{
    class Pig pig;
    pig.name = "ljy";
    pig.weight = 60;
    pig.running();
    return 0;
}

void Animal::running (void)
{
    std::cout << name << " is running." << '\n'
    << "And " << "its weight : " << --weight << "kg" << std::endl;

}