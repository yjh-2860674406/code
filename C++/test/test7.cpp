#include <iostream>

using namespace std;

class MyCar
{
public:
    string color;       // 颜色
    string engine;      // 引擎
    float gas_tank;     // 油箱
    unsigned int Wheel; // 轮子

    MyCar(void);        // 构造器
    void fill_tank(float liter);
    void running (void);
};

int main ()
{
    MyCar car1;
    car1.gas_tank = 2;
    car1.fill_tank(12.22);
    cout << car1.gas_tank << endl;
    return 0;
}

void MyCar::fill_tank(float liter)
{
    gas_tank += liter;
}

MyCar::MyCar(void)
{
    color = "black";
    engine = "V8";
    gas_tank = 12.33;
    Wheel = 4;
}