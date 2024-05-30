#include <iostream>
#include <set>

// 查找和统计
void test01()
{
    std::set<int> s1;
    // 插入
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    // 查找
    std::set<int>::iterator pos = s1.find(30);

    if (pos != s1.end())
        std::cout << "找到了元素 : " << *pos << std::endl;
    else
        std::cout << "未找到元素" << std::endl;
    // 统计
    int num = s1.count(30); // 不能存在重复元素，所以只能找到一个
    std::cout << "num = " << num << std::endl;
}

int main()
{
    test01();
    return 0;
}