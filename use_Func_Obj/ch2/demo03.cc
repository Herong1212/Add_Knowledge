#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
void test01()
{
    std::vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    for (std::vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 逻辑非 ---- 将v容器搬运到v2中，并执行逻辑非运算
    std::vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), std::logical_not<bool>());

    for (std::vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}