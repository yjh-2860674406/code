#include <iostream>

using namespace std;

class People
{
    public:
    string m_name;
    int m_age;

    People(string, int);
    void greet();
};

class Teacher : public People
{
    public :
    string m_job;
    
    Teacher(string, string, int);
    void greet();
};

int main()
{
    // People Yjh ("YJH", 19);
    // Yjh.greet();
    Teacher YJH ("teacher", "YJH", 19);
    YJH.greet();
    return 0;
}

People::People(string name, int age)
{
    m_name = name;
    m_age = age;
}
void People::greet()
{
    cout << "Hi, my name is " << m_name << "!" << endl;
    cout << "I have " << m_age << " years!" << endl;
}

Teacher::Teacher (string job, string name, int age) : People(name, age)
{
    m_name = name;
    m_age = age;
    m_job = job;
}
void Teacher::greet()
{
    cout << "Hi, my name is " << m_name << "!" << endl;
    cout << "My job is a " << m_job << "!" << endl;
    cout << "I have " << m_age << " years!" << endl;
}