#include <iostream>
#include <map>

// 查找和统计
void test01()
{
    std::map<int, int> m;
    m.insert(std::pair<int, int>(1, 10));
    m.insert(std::pair<int, int>(2, 20));
    m.insert(std::pair<int, int>(3, 30));

    // 查找
    std::map<int, int>::iterator pos = m.find(3); // 返回一个迭代器

    if (pos != m.end())
    {
        std::cout << "找到了元素 key = " << (*pos).first << " value = " << pos->second << std::endl;
    }
    else
    {
        std::cout << "未找到元素" << std::endl;
    }

    // 统计
    int num = m.count(3);
    std::cout << "num = " << num << std::endl;
}

int main()
{
    test01();
    return 0;
}