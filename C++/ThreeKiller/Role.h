#include <iostream>
#include <string.h>

using namespace std;

enum country {κ��, ���, ���, Ⱥ��};
enum identity {����, �ҳ�, ����, �ڼ�};

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
        cout << "�Ƿ���ң�y/n����" << endl;
        char n; cin >> n;
        while (n != 'y' && n != 'n') cout << "���������룡��y/n��" << endl;
        if (n == 'y') life += 1;
        else {
            cout << this->name << " �ѱ� " << hurter.name << " ��ɱ��" << endl;
            break;
        }
    }
}

void Role::Treat () {
    life += 1;
}

// ����
class LiuBei () : public Role {
public :
    LiuBei() {
        name = "����";
        id = ����;
        coun = ���;
        life = 4;
    }

    void SkillOne (Role someone);
}

void LiuBei::SkillOne (Role someone) {
    life += 1;
}