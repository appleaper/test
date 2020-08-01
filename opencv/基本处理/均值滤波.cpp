#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat src, src_gray, dst;
int threshold_value = 100;
int threshold_max = 255;
const char* output_win = "convex hull demo";
void Threshold_Callback(int, void*);
RNG rng(12345);

int main(int argc, char** argv) {
	src = imread("C:\\Users\\Administrator\\Desktop\\opencv\\meinv1.jpg");
	if (!src.data)
	{
		printf("could not load image...\n");
		return -1;
	}
	const char* input_win = "input image";
	namedWindow(input_win, WINDOW_AUTOSIZE);
	namedWindow(output_win, WINDOW_AUTOSIZE);
	const char* trackbar_label = "Threshold";

	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	blur(src_gray, src_gray, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);

	createTrackbar(trackbar_label, output_win, &threshold_value, threshold_max, Threshold_Callback);
	Threshold_Callback(0, 0);
	imshow(input_win, src_gray);
	waitKey(0);
	return 0;
}

void Threshold_Callback(int, void*) {
	Mat bin_output;
	vector<vector<Point>> contours;		//双重向量，就是一个向量里面又装了一个向量
	vector<Vec4i> hierachy;

	threshold(src_gray, bin_output, threshold_value, threshold_max, THRESH_BINARY);		//二值化，THRESH_BINARY大于阀值的置为255，小于部分置为0
	//凸包，一般先进行边缘检测完，再用这个。
	//bin_output：输入图像，contours：默认，hierachy：默认，RETR_TREE：检测所有轮廓，CHAIN_APPROX_SIMPLE：仅保存轮廓的拐点信息，Point(0, 0)：偏移
	//https://www.cnblogs.com/GaloisY/p/11062065.html
	findContours(bin_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));	
	vector<vector<Point>> convexs(contours.size());
	for (size_t i = 0; i < contours.size(); i++)
	{
		//https://www.cnblogs.com/jclian91/p/9728488.html
		convexHull(contours[i], convexs[i], false, true);	//得到轮廓的凸包,这个可以用作手势识别
	}

	dst = Mat::zeros(src.size(), CV_8UC3);
	for (size_t k = 0; k < contours.size(); k++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));	//随机颜色
		//轮廓绘制：dst:输入图像，contours轮廓数组,k：轮廓数组中的哪一个，color：颜色，2轮廓宽度，LINE_8:线的种类
		drawContours(dst, contours, k, color, 2, LINE_8, hierachy, 0, Point(0, 0));
		drawContours(dst, contours, k, color, 2, LINE_8, Mat(), 0, Point(0, 0));
	}
	imshow(output_win, dst);
}
