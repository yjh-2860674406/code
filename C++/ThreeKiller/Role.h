#include <iostream>
#include <string.h>

using namespace std;

enum country {魏国, 蜀国, 吴国, 群雄};
enum identity {主公, 忠臣, 反贼, 内奸};

class Role {
protected : 
    string name;
    country coun;
    identity id;
    int life;
    int life_max;

public :
    Role (string name, int country, int identity, int life_max);
    void Hurt (Role hurter);
    void Treat ();
    virtual void SkillOne ();
    virtual void SkillTwo ();
};

Role::Role (string name, country coun, identity id, int life_max) {
    this->name = name; this->coun = coun; this->id = id; this->life = life_max; this->life_max = life_max;
}

void Role::Hurt (Role hurter) { 
    life-=1;
    while (life <= 0) {
        cout << "是否吃桃（y/n）：" << endl;
        char n; cin >> n;
        while (n != 'y' && n != 'n') cout << "请重新输入！（y/n）" << endl;
        if (n == 'y') life += 1;
        else {
            cout << this->name << " 已被 " << hurter.name << " 击杀！" << endl;
            break;
        }
    }
}

void Role::Treat () {
    life += 1;
}

// 刘备
class LiuBei () : public Role {
public :
    LiuBei() {
        name = "刘备";
        id = 主公;
        coun = 蜀国;
        life = 4;
    }

    void SkillOne (Role someone);
}

void LiuBei::SkillOne (Role someone) {
    life += 1;
}