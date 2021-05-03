#include <iostream>

class People
{
public:
    std::string name;
    std::string sex;
    unsigned int age;
    unsigned long long phone;
    std::string address;
    std::string mail;
    bool extre;

    public:
    People()
    {
        extre = false;
    }

    void get_email (void)
    {
        std::cout << "请输入" << name <<"的邮箱:" << std::endl;
        std::cin >> mail;
    }

    void get_address (void)
    {
        std::cout << "请输入"<< name <<"的地址" << std::endl;
        std::cin >> address;
    }

    void get_age (void)
    {
        std::cout << "请输入" << name <<"的年龄" << std::endl;
        std::cin >> age;
    }

    void get_sex (void)
    {
        std::cout << "请输入" << name << "的性别" << std::endl;
        std::cin >> sex;
    }

    void get_name (void)
    {
        std::cout << "请输入姓名" << std::endl;
        std::cin >> name;
    }

    void get_phone (void)
    {
        std::cout << "请输入" << name << "的电话" << std::endl;
        std::cin >> phone;
    }
};

void print (People* peoples)
{
    int i=0;
    while (peoples[i].extre == true)
    {
        std::cout << "第" << i+1 << "位联系人:" << std::endl; 
        if (peoples[i].name == "0")
        {
            std::cout << "姓名:未知" << std::endl;
        }
        else
        {
            std::cout << "姓名:" << peoples[i].name << std::endl;
        }
        if (peoples[i].sex == "0")
        {
            std::cout << "性别:未知" << std::endl;
        }
        else
        {
            std::cout << "性别:" << peoples[i].sex << std::endl;
        }
        if (peoples[i].age == 0)
        {
            std::cout << "年龄:未知" << std::endl;
        }
        else 
        {
            std::cout << "年龄:" << peoples[i].age << std::endl;
        }
        if (peoples[i].phone == 0)
        {
            std::cout << "电话:未知" << std::endl; 
        }
        else 
        {
            std::cout << "电话:" << peoples[i].phone << std::endl;
        }
        if (peoples[i].mail == "0")
        {
            std::cout << "邮箱:未知" << std::endl;
        }
        else
        {
            std::cout << "邮箱:" << peoples[i].mail << std::endl;
        }
        if (peoples[i].address == "0")
        {
            std::cout << "地址:未知" << std::endl;
        }
        else
        {
            std::cout << "地址:" << peoples[i].address << std::endl;
        }
        i++;
    }
    std::cout << "打印完成." << std::endl;
}

void check (People* peoples)
{
    int i=0;
    int num=0;
    while (peoples[0].extre == false)
    {
        std::cout << "通讯录为空." << std::endl;
    }
    while (peoples[i].extre == true)
    {
        i++;
        num++;
    }
    char X;
    std::cout << "有" << num << "位联系人" << std::endl
    << "是否打印出所有联系人(是为Y, 否为N):" << std::endl;
    std::cin >> X;
    if (X = 'Y' || 'y')
    {
        print(peoples);   
    }
}

void push (People* peoples)
{
    int i=0;
    while (peoples[i].extre == true)
    {
        i++;
    }
    if (peoples[i].extre == false) 
    {
        People people;
        std::cout << "以下信息若不知道则填0" << std::endl; 
        people.get_name();
        people.get_sex();
        people.get_age();
        people.get_phone();
        people.get_email();
        people.get_address();
        people.extre = true;
        peoples[i] = people;
    }
}

void index (People* peoples)
{
    std::string names;
    std::cout << "请输入您要找的联系人名字" << std::endl;
    std::cin >> names;
    int i=0;
    int num=0;
    while (peoples[i].extre == true)
    {
        if (peoples[i].name == names)
        {
            std::cout << "第" << i+1 << "位联系人:" << std::endl; 
            if (peoples[i].name == "0")
            {
                std::cout << "姓名:未知" << std::endl;
            }
            else
            {
                std::cout << "姓名:" << peoples[i].name << std::endl;
            }
            if (peoples[i].sex == "0")
            {
                std::cout << "性别:未知" << std::endl;
            }
            else
            {
                std::cout << "性别:" << peoples[i].sex << std::endl;
            }
            if (peoples[i].age == 0)
            {
                std::cout << "年龄:未知" << std::endl;
            }
            else 
            {
                std::cout << "年龄:" << peoples[i].age << std::endl;
            }
            if (peoples[i].phone == 0)
            {
                std::cout << "电话:未知" << std::endl; 
            }
            else 
            {
                std::cout << "电话:" << peoples[i].phone << std::endl;
            }
            if (peoples[i].mail == "0")
            {
                std::cout << "邮箱:未知" << std::endl;
            }
            else
            {
                std::cout << "邮箱:" << peoples[i].mail << std::endl;
            }
            if (peoples[i].address == "0")
            {
                std::cout << "地址:未知" << std::endl;
            }
            else
            {
                std::cout << "地址:" << peoples[i].address << std::endl;
            }
            i++;
            continue;
        }
        else
        {
            num++;
        }
    }
    while (num == 0)
    {
        std::cout << "通讯录中没有:" << names << std::endl;
        break;
    }
}

void del (People* peoples)
{
    std::string names;
    std::cout << "请输入您要删除联系人的名字:" << std::endl;
    std::cin >> names;
    int i=0;
    while (peoples[i].extre == true)
    {
        if (peoples[i].name == names)
        {
            std::cout << names << "已被删除" << std::endl;
            for (int j=i; j<99; j++)
            {
                peoples[j] = peoples[j+1];
            }
            People people;
            peoples[99] = people;
            break;
        }
        else
        {
            i++;
        }
    }
    while (peoples[i].extre == false)
    {
        std::cout << "通讯录中不存在:"<< names << std::endl;
        break;
    }
}