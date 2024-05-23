#include <iostream>
#include <stack>

// 栈容器常用接口
void test01()
{
    // 创建栈容器：栈容器必须符合--先进后出--
    std::stack<int> s;

    // 向栈中添加元素，叫做---压栈-入栈---
    s.push(10);
    s.push(20);
    s.push(30); // 只能从 顶部 入栈

    while (!s.empty())
    {
        // 输出栈顶元素
        std::cout << "栈顶元素为： " << s.top() << std::endl;
        // 弹出栈顶元素
        s.pop(); // 只能从 顶部 往外出栈
    }
    std::cout << "栈的大小为：" << s.size() << std::endl;
}

int main()
{
    test01();
    return 0;
}