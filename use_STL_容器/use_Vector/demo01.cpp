#include <iostream>
using namespace std;
#include <vector>
#include <list>

void test01()
{
    vector<int> V1;
    V1.push_back(10);
    V1.push_back(20);
    V1.push_back(30);
    V1.push_back(40);
    V1.push_back(50);
    V1.push_back(666);

    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);

    cout << "V1 的第一个元素为: " << V1.front() << endl;
    cout << "V1 的最后一个元素为: " << V1.back() << endl;
    cout << "L1 的第一个元素为： " << L1.front() << endl;
    cout << "L1 的最后一个元素为： " << L1.back() << endl;

    // list 容器的迭代器是双向迭代器，不支持随机访问；但是 vector 容器支持随机访问，即可以 +2、+3等
    vector<int>::iterator itv = V1.begin();
    itv = itv + 3;
    cout << "V1 的第四个元素为: " << (*itv) << endl;
    list<int>::iterator itl = L1.begin();
    // itl = itl + 3;           // 错误，不可以跳跃访问，即使是 +1
    // cout << "L1 的第四个元素为: " << (*itl) << endl;

    // cout << L1.at(0) << endl;    // 错误  不支持 at 访问数据
    // cout << L1[0] << endl;       // 错误  不支持 [] 方式访问数据
    cout << V1.at(3) << endl; // 正确，支持 at() 访问数据
    cout << V1[3] << endl;    // 正确，支持 [] 访问数据
}

int main()
{
    test01();
    return 0;
}