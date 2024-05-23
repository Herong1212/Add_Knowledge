#include <iostream>
#include <string>
// 类模板
template <class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        std::cout << "name: " << this->mName << " age: " << this->mAge << std::endl;
    }

public:
    NameType mName;
    AgeType mAge;
};

// 1、指定传入的类型
void printPerson1(Person<std::string, int> &p)
{
    p.showPerson();
}
void test01()
{
    Person<std::string, int> p("孙悟空", 100);
    printPerson1(p);
}

// 2、参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    p.showPerson();
    std::cout << "T1的类型为: " << typeid(T1).name() << std::endl;
    std::cout << "T2的类型为: " << typeid(T2).name() << std::endl;
}
void test02()
{
    Person<std::string, int> p("猪八戒", 90);
    printPerson2(p);
}

// 3、整个类模板化
template <class T>
void printPerson3(T &p)
{
    std::cout << "T的类型为: " << typeid(T).name() << std::endl;
    p.showPerson();
}
void test03()
{
    Person<std::string, int> p("唐僧", 30);
    printPerson3(p);
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}