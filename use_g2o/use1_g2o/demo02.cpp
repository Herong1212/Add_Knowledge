#include <Eigen/Core>
#include <iostream>

#include "g2o/stuff/sampler.h"
#include "g2o/core/sparse_optimizer.h"
#include "g2o/core/block_solver.h"
#include <g2o/core/optimization_algorithm_factory.h>
#include "g2o/core/optimization_algorithm_levenberg.h"
#include "g2o/core/base_vertex.h"
#include "g2o/core/base_unary_edge.h"
#include "g2o/solvers/dense/linear_solver_dense.h"
#include "g2o/core/robust_kernel_impl.h"

using namespace std;

// linerSolver 三种求解器，用于计算迭代过程中最关键的一步 HΔx=−b
G2O_USE_OPTIMIZATION_LIBRARY(pcg)
G2O_USE_OPTIMIZATION_LIBRARY(cholmod)
G2O_USE_OPTIMIZATION_LIBRARY(csparse)

/*!
 * 继承BaseVertex类，构造顶点
 */
class VertexParams : public g2o::BaseVertex<3, Eigen::Vector3d>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

    VertexParams() = default;

    bool read(std::istream & /*is*/) override
    {
        cerr << __PRETTY_FUNCTION__ << " not implemented yet" << endl;
        return false;
    }

    bool write(std::ostream & /*os*/) const override
    {
        cerr << __PRETTY_FUNCTION__ << " not implemented yet" << endl;
        return false;
    }

    // 该函数作用是更新顶点的估计值
    void setToOriginImpl() override
    {
        cerr << __PRETTY_FUNCTION__ << " not implemented yet" << endl;
    }

    // 更新优化之后的顶点
    void oplusImpl(const double *update) override
    {
        Eigen::Vector3d::ConstMapType v(update);
        _estimate += v;
    }
};

/*!
 * 从BaseUnaryEdge继承得到一元边
 */
class EdgePointOnCurve : public g2o::BaseUnaryEdge<1, Eigen::Vector2d, VertexParams>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    EdgePointOnCurve() = default;

    bool read(std::istream & /*is*/) override
    {
        cerr << __PRETTY_FUNCTION__ << " not implemented yet" << endl;
        return false;
    }

    bool write(std::ostream & /*os*/) const override
    {
        cerr << __PRETTY_FUNCTION__ << " not implemented yet" << endl;
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

int main(int argc, char **argv)
{
    int numPoints = 200;
    int maxIterations = 50;
    bool verbose = true;

    double a = 1.;
    double b = 2;
    double c = 3;
    Eigen::Vector2d *points = new Eigen::Vector2d[numPoints];
    ofstream points_file("../points.txt", ios::out);

    // 准备用于拟合的数据  加上噪声
    for (int i = 0; i < numPoints; ++i)
    {
        double x = g2o::Sampler::uniformRand(0, 10);
        double y = sin(a * x) + cos(b * x) + c;
        y += g2o::Sampler::gaussRand(0, 0.1);

        // if (i == 20) {
        //     x = 8;
        //     y = 2.5;
        // }

        points[i].x() = x;
        points[i].y() = y;
        points_file << x << " " << y << endl;
    }
    points_file.close();

    g2o::SparseOptimizer optimizer;
    // 优化器类型
    string solver_type = "lm_var";
    // 优化器生成器
    g2o::OptimizationAlgorithmFactory *solver_factory = g2o::OptimizationAlgorithmFactory::instance();
    // 存储优化器性质
    g2o::OptimizationAlgorithmProperty solver_property;
    // 生成优化器
    g2o::OptimizationAlgorithm *solver = solver_factory->construct(solver_type, solver_property);

    optimizer.setAlgorithm(solver);

    if (!optimizer.solver())
    {
        std::cout << "G2O 优化器创建失败！" << std::endl;
    }

    VertexParams *params = new VertexParams();
    params->setId(0);
    params->setEstimate(Eigen::Vector3d(0.7, 2.4, 2)); // 初始化顶点的估计值
    optimizer.addVertex(params);

    for (int i = 0; i < numPoints; ++i)
    {
        EdgePointOnCurve *e = new EdgePointOnCurve;
        e->setInformation(Eigen::Matrix<double, 1, 1>::Identity());

        // if (i == 20) 
        // {
        //     e->setInformation(Eigen::Matrix<double, 1, 1>::Identity() * 10);
        // }

        e->setVertex(0, params);
        e->setMeasurement(points[i]);

        // g2o::RobustKernelHuber *robust_kernel_huber = new g2o::RobustKernelHuber;
        // robust_kernel_huber->setDelta(0.1);
        // e->setRobustKernel(robust_kernel_huber);

        optimizer.addEdge(e);
    }

    optimizer.initializeOptimization();
    optimizer.computeInitialGuess();
    optimizer.computeActiveErrors();

    optimizer.setVerbose(false);

    optimizer.optimize(maxIterations);

    ofstream result_file("../result.txt");
    result_file << params->estimate()[0] << " "
                << params->estimate()[1] << " "
                << params->estimate()[2];
    result_file.close();

    cout << endl
         << "a, b, c: "
         << params->estimate()[0] << ", "
         << params->estimate()[1] << ", "
         << params->estimate()[2] << endl;

    delete[] points;

    return 0;
}
