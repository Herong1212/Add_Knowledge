#include <deque>
#include <iostream>

void printDeque(const std::deque<int> &d)
{
    for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 大小操作
void test01()
{
    std::deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    // 判断容器是否为空
    if (d1.empty())
    {
        std::cout << "d1为空!" << std::endl;
    }
    else
    {
        std::cout << "d1不为空!" << std::endl;
        // 统计大小
        std::cout << "d1的大小为:" << d1.size() << std::endl;
    }

    // 重新指定大小
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}

int main()
{
    test01();
    return 0;
}