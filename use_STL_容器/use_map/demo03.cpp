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
    // 插入
    std::map<int, int> m;
    // 第一种插入方式
    m.insert(std::pair<int, int>(1, 10));

    // 第二种插入方式
    m.insert(std::make_pair(2, 20)); // orb-slam3 中用的这种

    // 第三种插入方式
    m.insert(std::map<int, int>::value_type(3, 30));

    // 第四种插入方式
    m[4] = 40;
    printMap(m);

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3);
    printMap(m);

    // 清空
    m.erase(m.begin(), m.end());
    m.clear();
    printMap(m);
}

int main()
{
    test01();
    return 0;
}