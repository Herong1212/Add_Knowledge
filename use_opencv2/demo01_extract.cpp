#include <iostream>
// #include <Eigen/Core>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
// #include <opencv2/core/mat.hpp>
// #include <opencv2/core/types.hpp>

int main(int argc, char *argv[])
{
    // cv::Mat T = (cv::Mat_<int>(4, 4) << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    // cv::Mat m(4, 4, CV_8UC1, cv::Scalar(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
    // std::cout << m << std::endl;

    // step1：创建变换矩阵 T 并赋值 + 输出
    cv::Mat T = cv::Mat_<int>(4, 4);

    // 赋值
    for (int i = 0; i < T.rows; i++)
    {
        for (int j = 0; j < T.cols; j++)
        {
            T.at<int>(i, j) = i + j;
        }
    }

    // cv::MatIterator_<int> it = T.begin<int>();
    // for (cv::MatIterator_<int> iti = T.begin<int>(); iti != T.end<int>(); iti++)
    // {
    //     for (cv::MatIterator_<int> itj = T.begin<int>(); itj != T.end<int>(); itj++)
    //     {
    //         std::cout << (*itj) << std::endl;
    //     }
    // }

    // 遍历每个元素
    for (int i = 0; i < T.rows; i++)
    {
        int *p = T.ptr<int>(i);
        for (int j = 0; j < T.cols; j++)
        {
            std::cout << T.ptr<int>(i)[j] << " ";
        }
        std::cout << std::endl;
    }

    // step2： 提取 R 并输出
    cv::Mat R = cv::Mat_<int>(3, 3);
    R = T.rowRange(0, 3).colRange(0, 3);
    for (int i = 0; i < R.rows; i++)
    {
        int *p = R.ptr<int>(i);
        for (int j = 0; j < R.cols; j++)
        {
            std::cout << R.ptr<int>(i)[j] << " ";
        }
        std::cout << std::endl;
    }

    // step3：提取 t 并输出
    cv::Mat t = cv::Mat_<int>(3, 1);
    t = T.rowRange(0, 3).col(3);
    for (cv::MatIterator_<int> it = t.begin<int>(); it != t.end<int>();it++)
    {
        std::cout << (*it) << std::endl;
    }
        // Eigen::Matrix3i matrix_3i;
        // matrix_3i = cv::Mat::matrix_4i.rowRange();

        return 0;
}
