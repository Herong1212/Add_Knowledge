#include <iostream>
#include <set>

void printSet(std::set<int> &s)
{
    std::set<int>::iterator it;
    for (auto &&it : s) // 等价于 === for (std::set<int>::iterator it = s.begin(); it != s.end();it++)
    {
        std::cout << it << " ";
        // it = it + 2; // 迭代器不支持随机访问，所以不能进行修改操作！
    }
    std::cout << std::endl;
}

void test01()
{
    std::set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    // 大小
    if (s1.empty())
        std::cout << "s1 为空" << std::endl;
    else
    {
        std::cout << "s1 不为空，"
                  << "s1 的大小为：" << s1.size() << std::endl;
    }
    printSet(s1);
}

void test02()
{
    std::set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    std::set<int> s2;
    s2.insert(100);
    s2.insert(300);
    s2.insert(200);
    s2.insert(400);

    std::cout << "交换前" << std::endl;
    printSet(s1);
    printSet(s2);

    s2.swap(s1);
    std::cout << "交换后" << std::endl;
    printSet(s1);
    printSet(s2);
}

int main(int argc, char *argv[])
{
    // test01();
    test02();
    return 0;
}
