#include <iostream>
#include <map>

void printMap(std::map<int, int> &m)
{
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << "key = " << it->first << " value = " << it->second << std::endl;
    }
    std::cout << std::endl;
}

void test01()
{
    std::map<int, int> m; // 默认构造

    m.insert(std::pair<int, int>(1, 10));
    m.insert(std::pair<int, int>(2, 20));
    m.insert(std::pair<int, int>(3, 30));
    
    printMap(m);

    std::map<int, int> m2(m); // 拷贝构造
    printMap(m2);

    std::map<int, int> m3;
    m3 = m2; // 赋值
    printMap(m3);
}

int main()
{
    test01();
    return 0;
}