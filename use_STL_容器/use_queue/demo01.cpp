#include <iostream>
#include <queue>
#include <string>
class Person
{
public:
    Person(std::string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    std::string m_Name;
    int m_Age;
};

void test01()
{

    // 创建队列
    std::queue<Person> q;

    // 准备数据
    Person p1("唐僧", 30);
    Person p2("孙悟空", 1000);
    Person p3("猪八戒", 900);
    Person p4("沙僧", 800);

    // 向队列中添加元素---入队---操作
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    // 队列不提供迭代器，更不支持随机访问
    while (!q.empty())
    {
        // 输出-队头-元素
        std::cout << "队头元素-- 姓名： " << q.front().m_Name
                  << " 年龄： " << q.front().m_Age << std::endl;

        std::cout << "队尾元素-- 姓名： " << q.back().m_Name
                  << " 年龄： " << q.back().m_Age << std::endl;

        std::cout << std::endl;
        // 弹出-队头-元素
        q.pop();
    }

    std::cout << "队列大小为：" << q.size() << std::endl;
}

int main()
{
    test01();
    return 0;
}