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
        std::cout << "������" << name <<"������:" << std::endl;
        std::cin >> mail;
    }

    void get_address (void)
    {
        std::cout << "������"<< name <<"�ĵ�ַ" << std::endl;
        std::cin >> address;
    }

    void get_age (void)
    {
        std::cout << "������" << name <<"������" << std::endl;
        std::cin >> age;
    }

    void get_sex (void)
    {
        std::cout << "������" << name << "���Ա�" << std::endl;
        std::cin >> sex;
    }

    void get_name (void)
    {
        std::cout << "����������" << std::endl;
        std::cin >> name;
    }

    void get_phone (void)
    {
        std::cout << "������" << name << "�ĵ绰" << std::endl;
        std::cin >> phone;
    }
};

void print (People* peoples)
{
    int i=0;
    while (peoples[i].extre == true)
    {
        std::cout << "��" << i+1 << "λ��ϵ��:" << std::endl; 
        if (peoples[i].name == "0")
        {
            std::cout << "����:δ֪" << std::endl;
        }
        else
        {
            std::cout << "����:" << peoples[i].name << std::endl;
        }
        if (peoples[i].sex == "0")
        {
            std::cout << "�Ա�:δ֪" << std::endl;
        }
        else
        {
            std::cout << "�Ա�:" << peoples[i].sex << std::endl;
        }
        if (peoples[i].age == 0)
        {
            std::cout << "����:δ֪" << std::endl;
        }
        else 
        {
            std::cout << "����:" << peoples[i].age << std::endl;
        }
        if (peoples[i].phone == 0)
        {
            std::cout << "�绰:δ֪" << std::endl; 
        }
        else 
        {
            std::cout << "�绰:" << peoples[i].phone << std::endl;
        }
        if (peoples[i].mail == "0")
        {
            std::cout << "����:δ֪" << std::endl;
        }
        else
        {
            std::cout << "����:" << peoples[i].mail << std::endl;
        }
        if (peoples[i].address == "0")
        {
            std::cout << "��ַ:δ֪" << std::endl;
        }
        else
        {
            std::cout << "��ַ:" << peoples[i].address << std::endl;
        }
        i++;
    }
    std::cout << "��ӡ���." << std::endl;
}

void check (People* peoples)
{
    int i=0;
    int num=0;
    while (peoples[0].extre == false)
    {
        std::cout << "ͨѶ¼Ϊ��." << std::endl;
    }
    while (peoples[i].extre == true)
    {
        i++;
        num++;
    }
    char X;
    std::cout << "��" << num << "λ��ϵ��" << std::endl
    << "�Ƿ��ӡ��������ϵ��(��ΪY, ��ΪN):" << std::endl;
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
        std::cout << "������Ϣ����֪������0" << std::endl; 
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
    std::cout << "��������Ҫ�ҵ���ϵ������" << std::endl;
    std::cin >> names;
    int i=0;
    int num=0;
    while (peoples[i].extre == true)
    {
        if (peoples[i].name == names)
        {
            std::cout << "��" << i+1 << "λ��ϵ��:" << std::endl; 
            if (peoples[i].name == "0")
            {
                std::cout << "����:δ֪" << std::endl;
            }
            else
            {
                std::cout << "����:" << peoples[i].name << std::endl;
            }
            if (peoples[i].sex == "0")
            {
                std::cout << "�Ա�:δ֪" << std::endl;
            }
            else
            {
                std::cout << "�Ա�:" << peoples[i].sex << std::endl;
            }
            if (peoples[i].age == 0)
            {
                std::cout << "����:δ֪" << std::endl;
            }
            else 
            {
                std::cout << "����:" << peoples[i].age << std::endl;
            }
            if (peoples[i].phone == 0)
            {
                std::cout << "�绰:δ֪" << std::endl; 
            }
            else 
            {
                std::cout << "�绰:" << peoples[i].phone << std::endl;
            }
            if (peoples[i].mail == "0")
            {
                std::cout << "����:δ֪" << std::endl;
            }
            else
            {
                std::cout << "����:" << peoples[i].mail << std::endl;
            }
            if (peoples[i].address == "0")
            {
                std::cout << "��ַ:δ֪" << std::endl;
            }
            else
            {
                std::cout << "��ַ:" << peoples[i].address << std::endl;
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
        std::cout << "ͨѶ¼��û��:" << names << std::endl;
        break;
    }
}

void del (People* peoples)
{
    std::string names;
    std::cout << "��������Ҫɾ����ϵ�˵�����:" << std::endl;
    std::cin >> names;
    int i=0;
    while (peoples[i].extre == true)
    {
        if (peoples[i].name == names)
        {
            std::cout << names << "�ѱ�ɾ��" << std::endl;
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
        std::cout << "ͨѶ¼�в�����:"<< names << std::endl;
        break;
    }
}