/****************************
 * 题目：给定一个融合后的点云（结果来自《从零开始一起学习SLAM | 你好，点云》），
 * 请先对其进行下采样，再进行滤波，最后输出滤波后的结果及被滤掉的离群点。
 *
 * 本程序学习目标：
 * 熟悉PCL的滤波。
 *
 * 公众号：计算机视觉life。发布于公众号旗下知识星球：从零开始学习SLAM
 * 时间：2018.12
 ****************************/
#include <pcl/point_types.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>

// 滤波模块
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>

typedef pcl::PointXYZRGB PointT;

int main(int argc, char **argv)
{

    // 加载点云初始化
    pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>);
    pcl::PointCloud<PointT>::Ptr cloud_downSampled(new pcl::PointCloud<PointT>);
    pcl::PointCloud<PointT>::Ptr cloud_filtered(new pcl::PointCloud<PointT>);
    pcl::PointCloud<PointT>::Ptr noise(new pcl::PointCloud<PointT>);
    if (pcl::io::loadPCDFile("../data/fusedCloud.pcd", *cloud) == -1)
    {
        cout << "点云数据读取失败！" << endl;
    }

    std::cout << "Points number after filtering: " << cloud->points.size() << std::endl;
    // ----------- 开始你的代码，参考http://docs.pointclouds.org/trunk/group__filters.html --------
    
    // 下采样，同时保持点云形状特征

    // 统计滤波

    // 试试半径滤波效果

    std::cout << "Points number after filtering: " << cloud_filtered->points.size() << std::endl;

    // 输出内点

    // 输出离群点

    // ----------- 结束你的代码 --------

    // 显示滤波结果，或者用 pcl_viewer 命令查看
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));
    viewer->setBackgroundColor(0, 0, 0);
    pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb(cloud_filtered);
    viewer->addPointCloud<PointT>(cloud_filtered, rgb, "sample cloud");
    while (!viewer->wasStopped())
    {
        viewer->spinOnce(100);
        boost::this_thread::sleep(boost::posix_time::microseconds(100000));
    }
    return (0);
}
