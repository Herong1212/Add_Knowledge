#include <iostream>

#include <g2o/core/sparse_optimizer.h>
#include <g2o/core/block_solver.h>
#include <g2o/solvers/dense/linear_solver_dense.h>
#include <g2o/core/optimization_algorithm_levenberg.h>

#include <g2o/core/base_vertex.h>     // 定义顶点
#include <g2o/core/base_unary_edge.h> // 定义边
#include<g2o/core/base_edge.h>

// step3：定义顶点和边
// ps1：顶点👇
// 根据【图2】的顶点构造关系，需要从基类中继承，然后对基类BaseVertex中的一些虚函数进行实现
class MyVertexParams : public g2o::BaseVertex<3, Eigen::Vector3d>
{
public:
    // Eigen 自动内存对齐
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

    MyVertexParams() = default; // 默认构造函数

    // 存盘
    virtual bool read(std::istream & /*is*/) override
    {
        std::cerr << __PRETTY_FUNCTION__ << "not implemented yet" << std::endl;
        return false;
    }

    // 读盘
    virtual bool write(std::ostream & /*os*/) const override
    {
        std::cerr << __PRETTY_FUNCTION__ << "not implemented yet" << std::endl;
        return false;
    }

    // 顶点的重置函数
    virtual void setToOriginImpl() override
    {
        std::cerr << __PRETTY_FUNCTION__ << "not implemented yet" << std::endl;
    }

    // 设置顶点估计值的更新
    virtual void oplusImpl(const double *update) override
    {
        _estimate += Eigen::Vector3d(update);
        // Eigen::Vector3d::ConstMapType v(update);
        // _estimate += v;
    }
};

// ps2：边👇
// 按照图2的流程，需要从基类中继承，由于我们这里顶点只有一个，所以就选用一元边，
// 那么就从一元边的基类BaseUnaryEdge中继承，然后重写其中的一些重要虚函数
class EdgePointOnCurve : public g2o::BaseUnaryEdge<1, Eigen::Vector2d, MyVertexParams>
{
public:
    // Eigen 自动内存对齐
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

    EdgePointOnCurve() = default; // 默认构造函数，比手动效率高

    virtual bool read(std::istream & /*is*/) override
    {
        std::cerr << __PRETTY_FUNCTION__ << " not implemented yet" << std::endl;
        return false;
    }

    virtual bool write(std::ostream & /*os*/) const override
    {
        std::cerr << __PRETTY_FUNCTION__ << " not implemented yet" << std::endl;
        return false;
    }

    // 计算曲线模型误差
    virtual void computeError() override
    {
        const MyVertexParams *params = dynamic_cast<const MyVertexParams *>(vertex(0));
        const double &a = params->estimate()(0);
        const double &b = params->estimate()(1);
        const double &lambda = params->estimate()(2);
        _error(0) = std::abs(a * std::exp(-lambda * measurement()(0) + b) - measurement()(1));
    }

    // 有时还需要计算雅可比矩阵
};

int main(int argc, char *argv[])
{
    // step0：生成数据
    int N = 100;
    double a_r = 2, b_r = 0.4, lambda_r = 0.2;

    std::vector<double> x_data, y_data;
    for (int i = 0; i < N; i++)
    {
        double x = i / 100.0;

        x_data.push_back(x);
        y_data.push_back(a_r * exp(-lambda_r * x + b_r));
    }

    // step1：构造优化器
    // 为了代码简洁
    typedef g2o::BlockSolver<g2o::BlockSolverTraits<Eigen::Dynamic, Eigen::Dynamic>> MyBlockSolver;
    typedef g2o::LinearSolverDense<MyBlockSolver::PoseMatrixType> MyLinearSolver;

    g2o::SparseOptimizer optimizer;

    // 初始化一个优化算法
    g2o::OptimizationAlgorithmLevenberg *solver = new g2o::OptimizationAlgorithmLevenberg(
        g2o::make_unique<MyBlockSolver>(g2o::make_unique<MyLinearSolver>()));

    optimizer.setAlgorithm(solver); // 将优化算法设置给 SparseOptimizer

    // step4.添加顶点和边到优化器中
    // step4.1 添加顶点
    MyVertexParams *v = new MyVertexParams(); // class VertexParams 里的函数必须加关键词 virtual

    v->setId(0);
    v->setEstimate(Eigen::Vector3d(0, 0, 0));

    optimizer.addVertex(v);

    // step4.2 添加边
    for (int i = 0; i < N; i++)
    {
        EdgePointOnCurve *e = new EdgePointOnCurve(); // 新建一个边

        e->setId(i);
        e->setVertex(0, v); // 设置边对应的顶点
        e->setInformation(Eigen::Matrix<double, 1, 1>::Identity()); //信息矩阵

        // double x = i / 100.0;
        // double point[i] = a_r * exp(-lambda_r * x + b_r);
        e->setMeasurement(point[i]); // 设置边的测量值

        // e->setMeasurement(y_data[i]);

        optimizer.addEdge(e);
    }

    // step5：执行优化
    optimizer.initializeOptimization(); // 初始化整个优化器
    optimizer.optimize(100);

    // 输出最终优化得到的结果
    std::cout << v->estimate()(0) << ", " << v->estimate()(1) << ", " << v->estimate()(2) << std::endl;

    return 0;
}
