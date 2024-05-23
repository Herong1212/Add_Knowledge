#include <iostream>
using namespace std;

#include<list>


class Person
{
public:
    string mName;
    int mAge;
    int mHeight;

public:
    Person(string name, int age, int height);
    ~Person();
};

Person::Person(string name, int age, int height)
{
    mName = name;
    mAge = age;
    mHeight = height;
}

Person::~Person()
{
}

void printPerson(list<Person> &l)
{
    for (list<Person>::iterator it = l.begin(); it != l.end();it++)
        cout << "姓名：" << it->mName << " 年龄：" << (*it).mAge << " 身高：" << it->mHeight << endl;
}

bool doCompare(Person &p1,Person &p2)
{
    if(p1.mAge==p2.mAge)
        return p1.mHeight > p2.mHeight;
    else
        return p1.mAge < p2.mAge;
}

int main(int argc, char *argv[])
{
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    list<Person> l;
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);

    cout << "排序前：" << endl;
    printPerson(l);

    l.sort(doCompare);

    cout << "排序后：" << endl;
    printPerson(l);

    return 0;
}
