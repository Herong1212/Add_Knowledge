#include <iostream>
#include <set>

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
void test01()
{
    std::set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);

    // 1.默认从小到大
    for (std::set<int>::iterator it = s1.begin(); it != s1.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // 2.指定排序规则
    std::set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);
    s2.insert(50);

    for (std::set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}