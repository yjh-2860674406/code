#include <iostream>

class Person 
{
public :
    std::string name;
};

class Teacher: virtual Person
{
public:
    std::string clas;
    Teacher (std::string i);
};

class Student: virtual Person
{
    public:
    Student (std::string i);
    std::string clas;
};

class TeacherStudent:Teacher,Student{};

int main ()
{
    
}

Teacher::Teacher(std::string i)
{   
    clas = i;
}