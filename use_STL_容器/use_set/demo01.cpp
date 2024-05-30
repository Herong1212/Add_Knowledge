#include <iostream>
#include <set>

void printSet(std::set<int> &s)
{
    for (std::set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 构造和赋值
void test01()
{
    std::set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);

    // 拷贝构造
    std::set<int> s2(s1);
    printSet(s2);

    // 赋值
    std::set<int> s3;
    s3 = s2;
    printSet(s3);
}

int main()
{
    test01();
    return 0;
}