#include <iostream>
#include <Eigen/Dense>

int main(int argc, char *argv[])
{
    // step1：矩阵定义
    // 1.定义矩阵
    // Eigen::Matrix3f matrix3f; // 定义 3x3 float 矩阵 matrix3f
    // Eigen::Matrix3d matrix3d; // 定义 3x3 double 矩阵 matrix3d
    // Eigen::Matrix3i matrix3i; // 定义 3x3 int 矩阵 matrix3i

    // Eigen::Matrix<double, 3, 3> matrix_33;                           // 定义 3x3 double 矩阵（方阵） matrix_33，等价于 Eigen::Matrix3d matrix3d;
    // Eigen::Matrix<double, 3, Eigen::Dynamic> matrix_3D;              // 定义 3xn double 矩阵，列为动态变化
    // Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_DD; // 定义行、列动态变化 double 矩阵 matrix_DD
    // Eigen::MatrixXd matrix_Xd;                                       // 定义行、列动态变化 double 矩阵 matrix_Xd
    // Eigen::Matrix3Xd matrix_3Xd(3, 4);                               // 定义 3xn double 矩阵 matrix_3Xd
    // Eigen::Matrix<double, 3, 3, Eigen::RowMajor> A;                  // 定义 3x3 double 矩阵，按行储存，默认按列储存效率较高。

    // 2.定义向量
    // Eigen::Vector3f vector_3f; // 定义 3x1 float 列向量 vector_3f
    // Eigen::Vector3d vector_3d; // 定义 3x1 double 列向量 vector_3d
    // Eigen::Vector3i vector_3i; // 定义 3x1 int 列向量 vector_3i

    // Eigen::VectorXd vector_Xd; // 定义动态 double 列向量 vector_Xd

    // Eigen::RowVector3f rowVector_3f; // 定义 3x1 float 列向量 rowVector_3f
    // Eigen::RowVectorXd rowVector_Xd; // 定义动态 double 列向量 rowVector_Xd

    // 3.多维矩阵定义
    // Eigen::Matrix3d B[4];
    // Eigen::Matrix<Eigen::Matrix<double, 3, 3>, 4, 1> M;

    // step2：矩阵赋值
    // Eigen::Vector3d vector_3d(1.2, 2.4, 3.6); // case1 ：初始化的时候直接赋值

    // Eigen::Vector3f vector_3f; // case2 ：初始化与赋值分开写
    // vector_3f << 1.1, 2.2, 3.3;

    // Eigen::Matrix<double, 3, 1> matrix_31 = Eigen::MatrixXd::Zero(3, 1); // Zero() 函数设为 0；在使用 Xd 时，必须指定【行数】【列数】
    // std::cout << matrix_31 << std::endl;

    // Eigen::Vector3d vector_3d = Eigen::Vector3d::Zero(3);

    // Eigen::Matrix<double, 4, 5> matrix_45;
    // matrix_45.setConstant(6); // 设置所有的元素值都等于 val
    // matrix_45.fill(7);        // 设置所有的元素值都等于 val

    // std::cout << matrix_45 << std::endl;

    // 逐元素赋值:
    // Eigen::Matrix3d mat;
    // mat(0, 0) = 1;
    // mat(0, 1) = 2;
    // mat(0, 2) = 3;
    // mat(1, 0) = 4;
    // mat(1, 1) = 5;
    // mat(1, 2) = 6;
    // mat(2, 0) = 7;
    // mat(2, 1) = 8;
    // mat(2, 2) = 9;

    // 使用随机值初始化:
    // Eigen::MatrixXd matrix_Xd = Eigen::MatrixXd::Random(5, 8); // 需要随机数种子
    // Eigen::Matrix3d matrix_3d = Eigen::Matrix3d::Random();
    // std::cout << matrix_Xd << std::endl;
    // std::cout << matrix_3d << std::endl;

    // 使用常量值初始化:
    // Eigen::MatrixXd matrixXd = Eigen::MatrixXd::Constant(5, 9, 2.6);
    // Eigen::Matrix3d matrix3d = Eigen::Matrix3d::Constant(666);
    // std::cout << matrixXd << std::endl;
    // std::cout << matrix3d << std::endl;

    // 创建一个 3x3 的矩阵，所有元素的值都为常数 2.0
    // 方法一：
    // Eigen::Matrix<double, 3, 3> matrix1;
    // matrix1.fill(2.0);
    // matrix1.setConstant(2.0);
    // std::cout << matrix1 << std::endl;

    // 方法二：
    // Eigen::Matrix<double, 3, 3> matrix2 = Eigen::Matrix<double, 3, 3>::Constant(2.0);
    // std::cout << matrix2 << std::endl;

    // 方法三：
    // Eigen::Matrix<double, 3, 3> matrix3 = Eigen::MatrixXd::Constant(3, 3, 2.0);
    // std::cout << matrix2 << std::endl;

    // 创建一个大小为 5 的向量，所有元素的值都为常数 1.5
    // Eigen::VectorXd vector1 = Eigen::VectorXd::Constant(5, 1, 1.5);  // 最多写 4 维向量，再高就只能用 Xd 来动态定义了！
    // std::cout << vector1 << std::endl;

    // 定义 5维 向量，全部设置为 6
    // Eigen::VectorXd vector_51;
    // vector_51.setConstant(5, 1, 6);
    // std::cout << vector_51 << std::endl;

    // 定义 6维 向量，设置为随机数
    //  Eigen::VectorXd vector_6;
    //  vector_6.Random(6, 1); // 错误
    //  vector_6 = Eigen::VectorXd::Random(6, 1);
    //  std::cout << vector_6 << std::endl;

    // step3：特殊矩阵
    // 1.零矩阵定义
    // Eigen::MatrixXd matrix_Xd = Eigen::MatrixXd::Zero(5, 8); // 对于行数、列数不确定的矩阵
    // // matrix_Xd.setZero(8, 8); // 这样也可以设置 8x8 的零矩阵
    // Eigen::Matrix3d matrix_3d = Eigen::Matrix3d::Zero(); // 对于固定大小的矩阵
    // Eigen::Matrix4f matrix_4f;
    // matrix_4f.setZero();
    // std::cout << matrix_Xd << std::endl;
    // std::cout << matrix_3d << std::endl;
    // std::cout << matrix_4f << std::endl;

    // 2.单位矩阵定义
    // Eigen::MatrixXd matrix_Xd1 = Eigen::MatrixXd::Identity(5, 8); // 对于行数、列数不确定的矩阵
    // Eigen::Matrix3d matrix_3d1 = Eigen::Matrix3d::Identity();     // 对于固定大小的矩阵
    // Eigen::Matrix4f matrix_4f1;
    // matrix_4f1.setIdentity();
    // std::cout << matrix_Xd1 << std::endl;
    // std::cout << matrix_3d1 << std::endl;
    // std::cout << matrix_4f1 << std::endl;

    // 3.全 1 矩阵
    // Eigen::MatrixXd matrix_Xd2 = Eigen::MatrixXd::Ones(5, 8); // 对于行数、列数不确定的矩阵
    // Eigen::Matrix3d matrix_3d2 = Eigen::Matrix3d::Ones();     // 对于固定大小的矩阵
    // Eigen::Matrix4f matrix_4f2;
    // matrix_4f2.setOnes(); // 是 setOnes() ，不是 Ones() ！
    // std::cout << matrix_Xd2 << std::endl;
    // std::cout << matrix_3d2 << std::endl;
    // std::cout << matrix_4f2 << std::endl;

    // 4.随机矩阵定义
    // Eigen::Matrix<double, 3, 4> matrix_34 = Eigen::Matrix<double, 3, 4>::Random(); // 对于已经已经固定大小的矩阵
    // std::cout << matrix_34 << std::endl;
    // std::cout << "--------------------\n";
    // Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic_83 = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>::Random(8, 3);
    // Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic_25;
    // matrix_dynamic_25.setRandom(2, 5);
    // std::cout << matrix_dynamic_25 << std::endl;

    // 5.线性阵定义
    // 方法一：VectorXd::LinSpaced(size, low, high);
    // 方法二：v.setLinSpaced(size, low, high);
    // Eigen::VectorXd vector_Xd1 = Eigen::VectorXd::LinSpaced(5, 1, 10);
    // std::cout << vector_Xd1 << std::endl;
    // Eigen::VectorXd vector_Xd2;
    // vector_Xd2.setLinSpaced(5, 2, 10);
    // std::cout << vector_Xd2 << std::endl;

    // 6.对角矩阵（DiagonalMatrix）是一种特殊的矩阵类型，其中只有对角线上的元素非零，而其它元素都是零。
    Eigen::DiagonalMatrix<double, 6> matrix_D1; // 创建对角矩阵 D，大小为 6x6
    matrix_D1.diagonal() << 1.0, 2.0, 3.0, 3.0, 2.0, 1.0;
    // Eigen::MatrixXd D = Eigen::MatrixXd::Zero(3, 3);
    // D.diagonal() << 1.0, 2.0, 3.0;
    // Eigen::DiagonalMatrix<double, 3> M(3.0, 8.0, 6.0);
    // std::cout << matrix_D1 << std::endl;
    std::cout << static_cast<Eigen::MatrixXd>(matrix_D1) << std::endl; // 必须将转换为 DenseMatrix 类型才能打印
    std::cout << matrix_D1.toDenseMatrix() << std::endl;               // 或者使用 toDenseMatrix() 方法打印

    std::cout << "--------------------\n";

    Eigen::Matrix<double, 3, 4> matrix_34;
    matrix_34 << 1.7, 5.4, 4.5, 6.2, 1.5, 4.1, 1.0, 5.4, 4.5, 6.2, 1.5, 4.1;
    std::cout << matrix_34 << std::endl;

    std::cout << "--------------------\n";

    Eigen::DiagonalMatrix<double, 4> matrix_4x4 = matrix_34.row(1).asDiagonal(); // 将行或列向量、矩阵的某一列或某一行转化为一个对角矩阵
    std::cout << matrix_4x4.toDenseMatrix() << std::endl;

    // R.diagonal()方法用于访问矩阵 R 的对角线元素。
    matrix_4x4.diagonal() << 1, 2, 3, 4; // 修改对角线元素
    std::cout << "--------------------\n";
    std::cout << matrix_4x4.toDenseMatrix() << std::endl;
    matrix_4x4.diagonal() *= 2;          // 对对角线元素进行运算
    std::cout << "--------------------\n";
    std::cout << matrix_4x4.toDenseMatrix() << std::endl;
    Eigen::DiagonalMatrix<double, Eigen::Dynamic> weight_R;
    weight_R.resize(6);

    return 0;
}
