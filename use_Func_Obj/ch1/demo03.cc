#include <iostream>
#include <vector>
#include <algorithm>

// 2.二元谓词
class MyCompare
{
public:
    bool operator()(int num1, int num2) // 返回值是 bool 类型 且 只接受一个参数
    {
        return num1 > num2;
    }
};

void test01()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    // 默认从小到大
    sort(v.begin(), v.end());
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;

    // 使用函数对象改变算法策略，排序从大到小
    sort(v.begin(), v.end(), MyCompare());
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}