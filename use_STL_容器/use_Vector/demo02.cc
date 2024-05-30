#include<iostream>
#include<vector>

void printfV(std::vector<int> &v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end();it++)
    {
        std::cout << *it << " ";
        *it = *it * 2;
    }
} 

int main(int argc, char const *argv[])
{

   
    return 0;
}
