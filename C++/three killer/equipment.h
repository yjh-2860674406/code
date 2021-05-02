#include <iostream>

class Equipment
{
    public:
    string name;
    int distance;
};

class Weapon : public Equipment
{
    
};

class Armor : public Equipment
{

};

class Ahouse : public Equipment
{

};

class Bhouse : public Equipment
{
    
};

class EquipmentPlace
{
    public:
    Weapon weapon;
    Armor armor;
    Ahouse ahouse;
    Bhouse bhouse;
};