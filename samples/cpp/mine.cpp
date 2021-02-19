#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


int main( int argc, char** argv )
{
//    const int width  = 1280;
//    const int height = 800;
//
//    std::ifstream file_in;
//    file_in.open("../image_yuv_nv21_1280_800_01.raw", std::ios::binary);
//    std::filebuf *p_filebuf = file_in.rdbuf();
//    size_t size = p_filebuf->pubseekoff(0, std::ios::end, std::ios::in);
//    p_filebuf->pubseekpos(0, std::ios::in);
//
//    char *buf_src = new char[size];
//    p_filebuf->sgetn(buf_src, size);
//
//    cv::Mat mat_src = cv::Mat(height*1.5, width, CV_8UC1, buf_src);
//    cv::Mat mat_dst = cv::Mat(height, width, CV_8UC3);
//
//    cv::cvtColor(mat_src, mat_dst, cv::COLOR_YUV2BGR_NV21);
//    cv::imwrite("yuv.png", mat_dst);
//
//    file_in.close();
//    delete []buf_src;
//
//    return 0;

    std::vector<uchar> y_data(700 * 480, 100);
    std::vector<uchar> uv_data(640 * 240, 100);

    cv::Mat y_plane_padding(480, 640, CV_8UC1, y_data.data(), 700);  // with stride
    cv::Mat uv_plane(240, 320, CV_8UC2, uv_data.data());

    cv::Mat result;

    cv::cvtColorTwoPlane(y_plane_padding, uv_plane, result, cv::COLOR_YUV2RGB_NV21);

    cv::imshow("", result);
    cv::waitKey();
}