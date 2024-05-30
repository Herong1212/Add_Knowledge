#include <iostream>
#include <set>

// set 和 multiset 区别
void test01()
{
    // 1.set
    std::set<int> s;
    std::pair<std::set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second)
        std::cout << "第一次插入成功!" << std::endl;
    else
        std::cout << "第一次插入失败!" << std::endl;
    ret = s.insert(10);
    if (ret.second)
        std::cout << "第二次插入成功!" << std::endl;
    else
        std::cout << "第二次插入失败!" << std::endl;

    // 2.multiset
    std::multiset<int> ms;
    ms.insert(10);
    ms.insert(10);

    for (std::multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        std::cout << *it << " ";
        // *it = +3; // 不支持随机访问
    }
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}