#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

// 选手类
class Person
{
public:
    Person(std::string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }

    std::string m_Name; // 姓名
    int m_Score;        // 平均分
};

void createPerson(std::vector<Person> &v)
{
    std::string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        std::string name = "选手";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);

        // 将创建的 person 对象 放入到容器中
        v.push_back(p);
    }
}

// 打分
void setScore(std::vector<Person> &v)
{
    for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 将评委的分数 放入到 deque 容器中
        std::deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60; // 60 ~ 100
            d.push_back(score);
        }

        // cout << "选手： " << it->m_Name << " 打分： " << endl;
        // for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        //{
        //     cout << *dit << " ";
        // }
        // cout << endl;

        // 排序
        sort(d.begin(), d.end());

        // 去除最高和最低分
        d.pop_back();
        d.pop_front();

        // 取平均分
        int sum = 0;
        for (std::deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit; // 累加每个评委的分数
        }

        int avg = sum / d.size();

        // 将平均分 赋值给选手身上
        it->m_Score = avg;
    }
}

void showScore(std::vector<Person> &v)
{
    for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << "姓名： " << it->m_Name << " 平均分： " << it->m_Score << std::endl;
    }
}

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    // 1、创建 5 名选手
    std::vector<Person> v; // 存放选手容器
    createPerson(v);

    // 测试
    // for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    //{
    //     cout << "姓名： " << (*it).m_Name << " 分数： " << (*it).m_Score << endl;
    // }

    // 2、给5名选手打分
    setScore(v);

    // 3、显示最后得分
    showScore(v);
    return 0;
}