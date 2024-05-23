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
// 赋值操作
void test01()
{
    std::deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    std::deque<int> d2;
    d2 = d1;
    printDeque(d2);

    std::deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    std::deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);
}

int main()
{
    test01();
    return 0;
}