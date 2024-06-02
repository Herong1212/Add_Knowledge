#include <iostream>
#include <functional>

// 1.negate --- 唯一一个一元运算
void test01()
{
    std::negate<int> n;
    std::cout << n(50) << std::endl; // -50
}

// 2.plus
void test02()
{
    std::plus<int> p;
    std::cout << p(10, 20) << std::endl; // 30
}

int main()
{
    test01();
    test02();
    return 0;
}