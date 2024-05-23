// #include "person.h"
// #include "person.cpp" // 解决方式 1，包含 cpp 源文件

// 解决方式 2，将声明文件 .h 和实现文件 .cpp 中的内容写到一起，文件后缀名改为 .hpp
#include "person.hpp"
void test01()
{
    Person<std::string, int> p("Tom", 10);
    p.showPerson();
}

int main()
{
    test01();
    return 0;
}