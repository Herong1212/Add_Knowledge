#include <iostream>
#include <deque>

void printDeque(const std::deque<int> &d)
{
    for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 数据存取
void test01()
{

    std::deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200); // 200 100 10 20

    for (int i = 0; i < d.size(); i++)
    {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < d.size(); i++)
    {
        std::cout << d.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "front:" << d.front() << std::endl;
    std::cout << "back:" << d.back() << std::endl;
}

int main()
{
    test01();
    return 0;
}