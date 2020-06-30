#include <opencv2/opencv.hpp>
int main(int argc, char** argv) {

	//读取图片
	cv::Mat img = cv::imread("./1.jpg", -1);

	if (img.empty()) return -1;

	//WINDOW_AUTOSIZE：图片窗口不能进行拉伸
	//WINDOW_NORMAL:窗口可以拉伸
	cv::namedWindow("Example 2-1", cv::WINDOW_AUTOSIZE);	
	cv::imshow("Example 2-1", img);
	cv::waitKey(0);
	cv::destroyWindow("Example 2-1");

	return 0;
}
