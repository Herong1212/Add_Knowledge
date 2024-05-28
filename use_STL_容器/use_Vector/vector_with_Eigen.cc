#include <iostream>
#include <Eigen/Dense>

int main()
{
    // 定义一个3D向量
    Eigen::Vector3d v(1.0, 2.0, 3.0);

    // 输出向量的x、y、z分量
    std::cout << "v = \n";
    std::cout << v << std::endl;
    std::cout << "v.x() = " << v.x() << std::endl;
    std::cout << "v.y() = " << v.y() << std::endl;
    std::cout << "v.z() = " << v.z() << std::endl;

    // 向量加法
    Eigen::Vector3d u(2.0, 3.0, 4.0);
    Eigen::Vector3d w = v + u;
    // std::cout << "w = " << w << std::endl;
    std::cout << "w = \n";
    std::cout << w << std::endl;

    // 向量点积
    double dot_product = v.dot(u);
    std::cout << "v . u = " << dot_product << std::endl;

    // 向量叉积
    Eigen::Vector3d cross_product = v.cross(u);
    // std::cout << "v x u = " << cross_product << std::endl;
    std::cout << "v x u = \n";
    std::cout << cross_product << std::endl;

    return 0;
}
