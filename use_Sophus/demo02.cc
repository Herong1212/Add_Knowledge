#include <iostream>

#include<Eigen/Dense>

#include<sophus/se3.hpp>

int main(int argc, char *argv[])
{
    Eigen::AngleAxisd A1(M_PI / 2, Eigen::Vector3d(0, 0, 1));
    Eigen::Matrix3d M1 = A1.toRotationMatrix();

    Eigen::Quaterniond Q1(M1);
    Sophus::SO3d SO3_M1(M1);

    std::cout << "SO(3) from matrix:\n"
               << SO3_M1.matrix() << std::endl;

    return 0;
}
