#include <iostream>
#include <algorithm>
#include <vector>

// 普通函数
void print01(int val)
{
    std::cout << val << " ";
}
// 函数对象
class print02
{
public:
    void operator()(int val)
    {
        std::cout << val << " ";
    }
};

// for_each算法基本用法
void test01()
{
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    
    // 遍历算法
    std::for_each(v.begin(), v.end(), print01);
    std::cout << std::endl;

    std::for_each(v.begin(), v.end(), print02());
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}