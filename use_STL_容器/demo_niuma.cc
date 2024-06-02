#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>

/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
    std::string m_Name;
    int m_Salary;
};

// 创建员工函数
void createWorker(std::vector<Worker> &v)
{
    std::string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000; // 10000 ~ 19999
        
        // 将员工放入到容器中
        v.push_back(worker);
    }
}

// 员工分组函数
void setGroup(std::vector<Worker> &v, std::multimap<int, Worker> &m)
{
    for (std::vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 产生随机部门编号
        int deptId = rand() % 3; // 0 1 2

        // 将员工插入到分组中
        // key 部门编号，value 具体员工
        m.insert(std::make_pair(deptId, *it));
    }
}

// 显示员工函数
void showWorkerByGourp(std::multimap<int, Worker> &m)
{
    // 0  A  B  C   1  D  E   2  F G ...
    std::cout << "策划部门：" << std::endl;

    std::multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA); // 统计具体人数
    int index = 0;
    for (auto &&pos = m.begin(); pos != m.end() && index < count; pos++, index++)
        std::cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << std::endl;

    std::cout << "----------------------" << std::endl;
    std::cout << "美术部门： " << std::endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU); // 统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
        std::cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << std::endl;

    std::cout << "----------------------" << std::endl;
    std::cout << "研发部门： " << std::endl;
    pos = m.find(YANFA);
    count = m.count(YANFA); // 统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
        std::cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << std::endl;
}

int main()
{
    srand((unsigned int)time(NULL));

    // 1、创建员工
    std::vector<Worker> vWorker;
    createWorker(vWorker);

    // 2、员工分组
    std::multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    // 3、分组显示员工
    showWorkerByGourp(mWorker);

    // 测试
    // for (std::vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    //     std::cout << "姓名： " << it->m_Name << " 工资： " << it->m_Salary << std::endl;

    return 0;
}