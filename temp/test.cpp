#include <iostream>

using namespace std;

class People
{
public :
    People(string name, int age, int life) : m_max(life)
    {
        m_name = name;
        m_age = age;
        m_life = life;
    }

    void Read ()
    {
        cout << m_name << " has " << m_life << " life." << endl;
    }

    void Kill (People &o)
    {
        o.m_life --;
        if (o.m_life) 
        {
            cout << m_name << " kill " << o.m_name << " a life." << endl;
            o.Read();
        }
        else cout << o.m_name << " has died!" << endl;
    }

    void Cure ()
    {
        m_life ++ ;
        cout << m_name << " eat a taozi!" << endl;
        Read();
    }

private :
    string m_name;
    int m_age;
    int m_life;
    const int m_max;
};

class Kill 
{
public :
    Kill (People &k, People &o)
    {
        k.Kill(o);
    }
};

class Cure
{
public :
    Cure (People &o)
    {
        o.Cure();
    }
};

int main()
{
    People p1("Yjh", 19, 4);
    People p2("Cy", 19, 3);
    Kill k(p1,p2);
    Cure c(p2);
}