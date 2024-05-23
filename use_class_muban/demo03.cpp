#include <iostream>
class Person1
{
public:
    void showPerson1()
    {
        std::cout << "Person1 show" << std::endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        std::cout << "Person2 show" << std::endl;
    }
};

template <class T>
class MyClass
{
public:
    T obj;

    // 类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成。

    void fun1() { obj.showPerson1(); }
    void fun2() { obj.showPerson2(); }
};

void test01()
{
    MyClass<Person1> m; // 这里是创建一个对象 m，类型是 MyClass，只能选择--显式指定类型方式--， 所以必须加类型 Person1 或者 Person2。

    m.fun1();

    // m.fun2();//编译会出错，说明函数调用才会去创建成员函数；若上面 <> 中改为 Person2 就可以了。
}

int main()
{
    test01();
    return 0;
}