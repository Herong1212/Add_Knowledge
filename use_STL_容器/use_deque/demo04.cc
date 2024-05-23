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
// 1. 两端操作
void test01()
{
    std::deque<int> d;
    // 尾插
    d.push_back(10);
    d.push_back(20);
    // 头插
    d.push_front(100);
    d.push_front(200);

    printDeque(d); // 200 100 10 20

    // 尾删
    d.pop_back();
    // 头删
    d.pop_front();
    printDeque(d); // 100 10
}

// 2. 指定位置
// 插入
void test02()
{
    std::deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d); // 200 100 10 20

    d.insert(d.begin(), 1000);
    printDeque(d); // 1000 200 100 10 20

    d.insert(d.begin(), 2, 10000);
    printDeque(d); // 10000 10000 1000 200 100 10 20

    std::deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d.insert(d.begin(), d2.begin(), d2.end());
    printDeque(d); // 1 2 3 10000 10000 1000 200 100 10 20
}

// 删除
void test03()
{
    std::deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d); // 200 100 10 20

    d.erase(d.begin());
    printDeque(d); // 100 10 20

    d.erase(d.begin(), d.end());
    printDeque(d); // (null)

    d.clear();
    printDeque(d); // (null)
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}
