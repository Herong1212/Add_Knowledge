#include <vector>
#include <string>
#include <iostream>
using namespace std;

// 自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        mName = name;
        mAge = age;
    }

public:
    string mName; // m_Name
    int mAge;
};
// step1：存放对象
void test01()
{
    vector<Person> v;

    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "Name:" << (*it).mName << " Age:" << it->mAge << endl;
    }
}

// step2：放对象指针
void test02()
{
    vector<Person *> v;

    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        // Person *p = (*it); // why？这句话有啥作用 —— 原来是为了整花活啊～
        // cout << "Name:" << p->mName << " Age:" << (*it)->mAge << endl;
        cout << "Name:" << (*it)->mName << " Age:" << (*it)->mAge << endl; // todo 也可以只用这一句
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}