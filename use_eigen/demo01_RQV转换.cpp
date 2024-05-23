#include <iostream>
// #include <Eigen/Core>     // 包含了 Matrix
#include <Eigen/Geometry> // 包含了 AngleAxisd、Quaterniond
// #include <Eigen/Eigen> // 包含了 Core 和 Geometry 模块

// using namespace std;

int main(int argc, char *argv[])
{
    Eigen::Matrix<double, 3, 3> Matrix1;
    Eigen::AngleAxisd rotation_vector(M_PI_4, Eigen::Vector3d(0, 0, 1));
    // std::cout << precision(3);
    std::cout << "旋转向量的旋转轴 = \n"
              << rotation_vector.axis() << "\n旋转角度 = " << rotation_vector.angle() << std::endl;

    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    // 法一：直接给旋转矩阵赋值
    rotation_matrix << 0.707, -0.707, 0,
        0.707, 0.707,
        0, 0, 0, 1;

    // 法二：用旋转向量转换为旋转矩阵，两个函数都可以用
    // rotation_matrix = rotation_vector.toRotationMatrix();
    // rotation_matrix = rotation_vector.matrix();

    std::cout << "旋转矩阵 = \n"
              << rotation_matrix << std::endl;

    Eigen::Quaterniond quat = Eigen::Quaterniond(0, 0, 0.383, 0.924);
    std::cout << "四元数的输出方法 1: 四元数 = \n"
              << quat.coeffs() << std::endl; // todo coeffs()的顺序是：(x, y, z, w)，w 为实部，其余为虚部

    std::cout << "四元数的输出方法 2: 四元数 ="
              << "\n x = " << quat.x()
              << "\n y = " << quat.y()
              << "\n z = " << quat.z()
              << "\n w = " << quat.w() << std::endl;
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    // step1：旋转矩阵 ——> 旋转向量、四元数
    // todo R ——> V
    // 法一：
    rotation_vector.fromRotationMatrix(rotation_matrix);
    std::cout << "旋转向量的旋转轴 = \n"
              << rotation_vector.axis() << "\n旋转角度 = " << rotation_vector.angle() << std::endl;

    // 法二：
    rotation_vector = rotation_matrix;
    std::cout << "旋转向量的旋转轴 = \n"
              << rotation_vector.axis() << "\n旋转角度 = " << rotation_vector.angle() << std::endl;

    // 法三：
    rotation_vector = Eigen::AngleAxisd(rotation_matrix);
    std::cout << "旋转向量的旋转轴 = \n"
              << rotation_vector.axis() << "\n旋转角度 = " << rotation_vector.angle() << std::endl;

    // todo R ——> Q
    quat = rotation_matrix;
    std::cout << "旋转矩阵转换为四元数,方法1: Q = \n"
              << quat.coeffs() << std::endl;

    quat = Eigen::Quaterniond(rotation_matrix);
    std::cout << "旋转矩阵转换为四元数,方法2: Q = \n"
              << quat.coeffs() << std::endl;

    // step2：旋转向量 ——> 旋转矩阵、四元数
    // todo V ——> R
    rotation_matrix = rotation_vector.toRotationMatrix();
    std::cout << "旋转向量转换为旋转矩阵,方法1: 旋转矩阵 R = \n"
              << rotation_matrix << std::endl;
    rotation_matrix = rotation_vector.matrix();
    std::cout << "旋转向量转换为旋转矩阵,方法1: 旋转矩阵 R = \n"
              << rotation_matrix << std::endl;

    // todo V ——> Q
    quat = rotation_vector;
    std::cout << quat.coeffs() << std::endl;

    quat = Eigen::Quaterniond(rotation_vector);
    std::cout << quat.coeffs() << std::endl;

    // step3：四元数 ——> 旋转向量、旋转矩阵
    // todo Q ——> V
    rotation_vector = quat;
    std::cout << "旋转轴：\n"
              << rotation_vector.axis() << "\n 旋转角度为：" << rotation_vector.angle() << std::endl;

    rotation_vector = Eigen::Quaterniond(quat);
    std::cout << "旋转轴：\n"
              << rotation_vector.axis() << "\n 旋转角度为：" << rotation_vector.angle() << std::endl;

    // todo Q ——> R
    rotation_matrix = quat.matrix();
    std::cout << "旋转矩阵为：\n"
              << rotation_matrix << std::endl;

    rotation_matrix = quat.toRotationMatrix();
    std::cout << "旋转矩阵为：\n"
              << rotation_matrix << std::endl;

    return 0;
}
