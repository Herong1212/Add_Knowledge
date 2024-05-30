#include <iostream>
#include <map>

void printMap(std::map<int, int> &m)
{
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        std::cout << "key = " << it->first << " value = " << it->second << std::endl;
    std::cout << std::endl;
}

void test01()
{
    std::map<int, int> m;
    m.insert(std::pair<int, int>(1, 10));
    m.insert(std::pair<int, int>(2, 20));
    m.insert(std::pair<int, int>(3, 30));

    if (m.empty())
        std::cout << "m为空" << std::endl;
    else
        std::cout << "m不为空" << std::endl;
        std::cout << "m的大小为: " << m.size() << std::endl;
}

// 交换
void test02()
{
    std::map<int, int> m;
    m.insert(std::pair<int, int>(1, 10));
    m.insert(std::pair<int, int>(2, 20));
    m.insert(std::pair<int, int>(3, 30));

    std::map<int, int> m2;
    m2.insert(std::pair<int, int>(4, 100));
    m2.insert(std::pair<int, int>(5, 200));
    m2.insert(std::pair<int, int>(6, 300));

    std::cout << "交换前" << std::endl;
    printMap(m);
    printMap(m2);

    std::cout << "交换后" << std::endl;
    m.swap(m2);
    printMap(m);
    printMap(m2);
}

int main()
{
    test01();
    test02();
    return 0;
}