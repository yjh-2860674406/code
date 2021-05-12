#include <iostream>
#include "Character.h"
#include "Equipment.h"

enum ID {主公, 忠臣, 反贼};

class Player
{
    public:
    ID id;
    Character crt;
    EquipmentPlace eqp;
    Judge jde;
   
    void Check ()
    {
        cout << "血量：" << crt.life << endl;
        cout << "人物：" << crt.name << endl;
        cout << "派别：" << crt.nation << endl;
        cout << "技能：" << endl;
        cout << "准备区：" << endl;
        cout << "   " << "武器：" << eqp.weapon.name << endl;
        cout << "   " << "防具：" << eqp.armor.name << endl;
        cout << "   " << "进攻马：" << eqp.ahouse.name << endl; 
        cout << "   " << "防御马：" << eqp.bhouse.name << endl;
    }

    void Distance ()
    {
        int distance = crt.distance+eqp.weapon.distance+eqp.ahouse.distance;
        cout << "攻击距离：" << distance << endl;
    }
};