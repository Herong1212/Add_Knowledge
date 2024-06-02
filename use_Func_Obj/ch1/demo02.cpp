#include <iostream>
#include <vector>
#include <algorithm>

// 1.一元谓词
struct GreaterFive
{
    bool operator()(int val) // 返回值是 bool 类型 且 只接受一个参数
    {
        return val > 5;
    }
};

void test01()
{
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    std::vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
        std::cout << "没找到!" << std::endl;
    else
        std::cout << "找到:" << *it << std::endl;
}

int main()
{
    test01();
    return 0;
}