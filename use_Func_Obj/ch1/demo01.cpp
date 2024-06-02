#include <iostream>
#include <string>

// 1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test01()
{
    MyAdd myAdd;
    std::cout << myAdd(10, 10) << std::endl;
}

// 2、函数对象可以有自己的状态
class MyPrint
{
public:
    MyPrint()
    {
        count = 0;
    }
    void operator()(std::string test)
    {
        std::cout << test << std::endl;
        count++; // 统计使用次数
    }

    int count; // 内部自己的状态
};
void test02()
{
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    std::cout << "myPrint调用次数为: " << myPrint.count << std::endl;
}

// 3、函数对象可以作为参数传递
void doPrint(MyPrint &mp, std::string test)
{
    mp(test);
}

void test03()
{
    MyPrint myPrint;
    doPrint(myPrint, "Hello C++");
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}