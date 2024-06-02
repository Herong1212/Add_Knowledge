#include <iostream>
#include <vector>
#include <algorithm>

// 常用遍历算法  搬运 transform
class TransForm
{
public:
    int operator()(int val)
    {
        return val;
    }
};

class MyPrint
{
public:
    void operator()(int val)
    {
        std::cout << val << " ";
    }
};

void test01()
{
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    std::vector<int> vTarget; // 目标容器

    vTarget.resize(v.size()); // 目标容器需要提前开辟空间

    std::transform(v.begin(), v.end(), vTarget.begin(), TransForm());

    std::for_each(vTarget.begin(), vTarget.end(), MyPrint());
}

int main()
{
    test01();
    return 0;
}