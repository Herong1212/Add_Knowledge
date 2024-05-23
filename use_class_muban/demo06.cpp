#include <string>
#include <iostream>
// 类模板中成员函数类外实现
template <class T1, class T2>
class Person
{
public:
    // 成员函数类内声明
    Person(T1 name, T2 age);
    void showPerson();

public:
    T1 m_Name;
    T2 m_Age;
};

// 1. 构造函数 类外实现
template <class T1, class T2> // 这一步是为了让下面的 T1 T2 知道自己是什么东西
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}

// 2. 成员函数 类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    std::cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << std::endl;
}
void test01()
{
    Person<std::string, int> p("Jerry", 20);
    p.showPerson();
}

int main()
{
    test01();
    return 0;
}