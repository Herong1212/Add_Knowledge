#include <iostream>
#include <Eigen/Eigen>
#include <fstream>

#include <g2o/stuff/sampler.h> // 包含了 g2o::Sampler

#include <g2o/core/base_vertex.h>
#include <g2o/core/base_unary_edge.h>
#include <g2o/core/block_solver.h>                 // 包含了 g2o::BlockSolver
#include <g2o/solvers/dense/linear_solver_dense.h> //包含了 Block::LinearSolverType *linearSolver
#include <g2o/solvers/eigen/linear_solver_eigen.h> //包含了 Block::LinearSolverType *linearSolver
#include <g2o/core/optimization_algorithm_levenberg.h>
#include <g2o/core/optimization_algorithm_factory.h>

// #include<g2o/core/base_binary_edge.h>
// #include<g2o/core/base_multi_edge.h>
// #include<g2o/types/sba/types_sba.h>

// ps 待优化曲线 : y = sin (ax) + cos (bx) + c      其中 a=1, b=2, c=3

// 1.构造顶点
class VertexParams : public g2o::BaseVertex<3, Eigen::Vector3d>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

    VertexParams() = default;

    bool read(std::istream & /*is*/) override
    {
        std::cerr << __PRETTY_FUNCTION__ << " not implemented yet" << std::endl;
        return false;
    }

    bool write(std::ostream & /*os*/) const override
    {
        std::cerr << __PRETTY_FUNCTION__ << " not implemented yet" << std::endl;
        return false;
    }

    // 该函数作用是更新顶点的估计值
    void setToOriginImpl() override
    {
        std::cerr << __PRETTY_FUNCTION__ << " not implemented yet" << std::endl;
    }

    // 更新优化之后的顶点
    void oplusImpl(const double *update) override
    {
        Eigen::Vector3d::ConstMapType v(update);
        _estimate += v;
    }
};

// 2.构造边，从 BaseUnaryEdge 继承得到一元边
class EdgePointOnCurve : public g2o::BaseUnaryEdge<1, Eigen::Vector2d, VertexParams>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    EdgePointOnCurve() = default;

    bool read(std::istream & /*is*/) override
    {
        std::cerr << __PRETTY_FUNCTION__ << " not implemented yet" << std::endl;
        return false;
    }

    bool write(std::ostream & /*os*/) const override
    {
        std::cerr << __PRETTY_FUNCTION__ << " not implemented yet" << std::endl;
        return false;
    }

    // 边的误差计算
    void computeError() override
    {
        const VertexParams *params = dynamic_cast<const VertexParams *>(vertex(0)); // 顶点
        const double &a = params->estimate()(0);
        const double &b = params->estimate()(1);
        const double &c = params->estimate()(2);
        // double fval = a * exp(-lambda * measurement()(0)) + b;
        double fval = sin(a * measurement()(0)) + cos(b * measurement()(0)) + c;
        _error(0) = std::abs(fval - measurement()(1));
    }
};

int main(int argc, char const *argv[])
{
    int numPoints = 200; // 数据点
    double a = 1.;
    double b = 2;
    double c = 3;
    Eigen::Vector2d *points = new Eigen::Vector2d[numPoints];
    std::ofstream points_file("../points.txt", std::ios::out);

    // 准备用于拟合的数据  加上噪声
    for (int i = 0; i < numPoints; ++i)
    {
        double x = g2o::Sampler::uniformRand(0, 10);
        double y = sin(a * x) + cos(b * x) + c;
        y += g2o::Sampler::gaussRand(0, 0.1);

        points[i].x() = x;
        points[i].y() = y;
        points_file << x << " " << y << std::endl;
    }
    points_file.close();

    // 每个误差项优化变量维度为 3，误差值维度为 1
    typedef g2o::BlockSolver<g2o::BlockSolverTraits<3, 1>> Block;

    // step1：创建线性求解器（LinearSolver）、块求解器（BlockSolver）、总求解器（Solver）和大BOSS--稀疏求解器（optimizer）
    Block::LinearSolverType *linearSolver = new g2o::LinearSolverDense<Block::PoseMatrixType>();

    Block *solver_ptr = new Block(linearSolver);

    // g2o::OptimizationAlgorithmLevenberg *solver = new g2o::OptimizationAlgorithmLevenberg(std::unique_ptr<g2o::Solver> solver_ptr);
    g2o::OptimizationAlgorithmLevenberg *solver = new g2o::OptimizationAlgorithmLevenberg(std::make_unique<g2o::Solver> solver_ptr);

    // // 优化器类型
    // std::string solver_type = "lm_var";
    // // 优化器生成器
    // g2o::OptimizationAlgorithmFactory *solver_factory = g2o::OptimizationAlgorithmFactory::instance();
    // // 存储优化器性质
    // g2o::OptimizationAlgorithmProperty solver_property;
    // // 生成优化器
    // g2o::OptimizationAlgorithm *solver = solver_factory->construct(solver_type, solver_property);

    g2o::SparseOptimizer optimizer;
    optimizer.setAlgorithm(solver); // 设置求解器，用前面定义好的求解器作为求解方法
    optimizer.setVerbose(true);     // 在优化过程中输出调试输出

    // 判断是否构建成功
    if (!optimizer.solver())
    {
        std::cout << "g2o 优化器构建失败！" << std::endl;
    }

    // step2：定义图的顶点（只有一个）和图的边（有多个），并添加到优化器中
    VertexParams *params = new VertexParams();
    params->setEstimate(Eigen::Vector3d(0, 0, 0)); // 初始化顶点的估计值为 0
    params->setId(0);                              // 初始 ID 设置为 0

    optimizer.addVertex(params); // 将顶点（待求解的a、b、c）添加到优化器中

    for (int i = 0; i < numPoints; i++) // 边可以有多个，所以用循环添加
    {
        EdgePointOnCurve *edge = new EdgePointOnCurve();
        edge->setId(i);
        edge->setVertex(0, params);                                    // 设置连接的顶点
        edge->setMeasurement(points[i]);                               // 观测数值
        edge->setInformation(Eigen::Matrix<double, 1, 1>::Identity()); // 信息矩阵：协方差矩阵之逆
        optimizer.addEdge(edge);                                       // 添加边
    }

    // step3：设置优化参数，开始执行优化
    std::cout << "开始优化！" << std::endl;
    optimizer.initializeOptimization();

    optimizer.computeActiveErrors();
    optimizer.computeInitialGuess();

    optimizer.optimize(100); // 设置迭代次数

    // 输出优化值
    Eigen::Vector3d abc_estimate = params->estimate();
    std::cout << "estimate model: " << abc_estimate << std::endl;

    return 0;
}
