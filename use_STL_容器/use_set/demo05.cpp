#include <iostream>
#include <string>

// 对组创建
void test01()
{
    std::pair<std::string, int> p(std::string("Tom"), 20);
    std::cout << "姓名： " << p.first << " 年龄： " << p.second << std::endl;

    std::pair<std::string, int> p2 = std::make_pair("Jerry", 10);
    std::cout << "姓名： " << p2.first << " 年龄： " << p2.second << std::endl;
}

int main()
{
    test01();
    return 0;
}