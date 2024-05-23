#include <iostream>
// #include <Eigen/Core>
#include<opencv2/opencv.hpp>
// #include <opencv2/core/mat.hpp>
// #include <opencv2/core/types.hpp>

int main(int argc, char *argv[])
{
    // cv::Mat matrix_4i << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16;
    // cv::Mat4i matrix_4i = cv::Mat(cv::Size(4, 4), CV_8U);
    cv::Mat matrix_4i = (cv::Mat_<int>(4, 4) << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    std::cout << matrix_4i << std::endl;

    // Eigen::Matrix3i matrix_3i;
    // matrix_3i = cv::Mat::matrix_4i.rowRange();

    cv::waitKey(0);

    return 0;
}
