#include <iostream>
#include <deque>
#include <algorithm>

void printDeque(const std::deque<int> &d)
{
    for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    printDeque(d); // 200 100 10 20
    // sort(d.begin(), d.end()); // 排序规则，默认--从小到大--

    std::sort(d.begin(), d.end()); // 只有支持随机访问迭代器的的 容器，如 vector、deque 等，才可以使用 std::sort() 方法。
    printDeque(d); // 10 20 100 200
}

int main()
{
    test01();
    return 0;
}