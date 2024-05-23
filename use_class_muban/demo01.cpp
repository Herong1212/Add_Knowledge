#include <iostream>
#include <string>

// 类模板
template <class NameType, class AgeType>
// class Person
// {
// public:
//     NameType mName;
//     AgeType mAge;

//     Person(NameType name, AgeType age)
//     {
//         mName = name;
//         mAge = age;
//     }

//     void showPerson()
//     {
//         std::cout << "name: " << mName << " age: " << mAge << std::endl;
//     }
// };

class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		std::cout << "name: " << this->mName << " age: " << this->mAge << std::endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

void test01()
{
    // 指定 NameType 为 string 类型，AgeType 为 int 类型
    Person<std::string, int> p1("豆豆", 24); // C++ provides <string>, and then it should be referred to as std::string.
    p1.showPerson();
}

int main()
{
    test01();
    return 0;
}
