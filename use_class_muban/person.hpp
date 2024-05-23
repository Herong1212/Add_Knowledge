#pragma once // 防止头文件重复包含

#include <iostream>
#include <string>

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    void showPerson();

public:
    T1 m_Name;
    T2 m_Age;
};

// 1. 构造函数 类外实现
template <class T1, class T2>
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