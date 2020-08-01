
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <math.h>

using namespace std;
using namespace cv;

Mat src, dst;
const char* output_win = "findcontours-demo";
int threshold_value = 100;
int threshold_max = 255;
RNG rng;
void Demo_Contours(int, void*);
int main(int argc, char** argv) {
	src = imread("C:\\Users\\Administrator\\Desktop\\opencv\\meinv1.jpg");
	if (src.empty())
	{
		printf("could not load image...\n");
	}
	namedWindow("input-image", WINDOW_AUTOSIZE);
	namedWindow(output_win, WINDOW_AUTOSIZE);
	imshow("input-image", src);
	cvtColor(src, src, COLOR_BGR2GRAY);

	const char* trackbar_title = "Threshold Valur";
	createTrackbar(trackbar_title, output_win, &threshold_value, threshold_max, Demo_Contours);
	Demo_Contours(0, 0);
	waitKey(0);
	return 0;
}

void Demo_Contours(int, void*) {
	Mat canny_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;
	Mat srcGray;
	GaussianBlur(src, srcGray, Size(3, 3),0, 0, BORDER_DEFAULT);
	//边缘检测算法主要基于图像的一阶和二阶微分操作，但是导数通常对噪声很敏感，边缘检测算法需要预处理操作，
	//因此采用滤波器来改善边缘检测的性能。在进行Canny之前，应该对图像进行高斯模糊来平滑降噪
	Canny(srcGray, canny_output, threshold_value, threshold_value * 3, 3, false);	//threshold_value:低阀值，threshold_value * 3高阀值，3：kernel大小，false默认
	findContours(canny_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));	//保留全部
	
	dst = Mat::zeros(src.size(), CV_8UC3);
	RNG rng(123);
	for (size_t i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(dst, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));	//dst需要三通道才显示轮廓，contours轮廓本身，
	}
	imshow(output_win, dst);
}
