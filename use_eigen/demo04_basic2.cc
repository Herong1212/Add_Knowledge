#include <iostream>
#include <Eigen/Dense>

int main(int argc, char *argv[])
{
    // step4：矩阵索引
    Eigen::Vector4d v1(2.4, 5.4, 9.5, 8.7);
    std::cout << "v1 = \n"
              << v1 << std::endl;
    std::cout << "-----------\n";
    // 访问元素的三种方式👇
    std::cout << "v1 中的第 3 个元素为：" << v1[2] << std::endl;
    std::cout << "v1 中的第 3 个元素为：" << v1(2) << std::endl;
    std::cout << "v1 中的第 3 个元素为：" << v1.z() << std::endl;
    
    std::cout << v1.rows() << std::endl;
    std::cout << v1.cols() << std::endl;

    // step5：矩阵操作

    // step6：矩阵运算

    // step7：动态矩阵

    return 0;
}
