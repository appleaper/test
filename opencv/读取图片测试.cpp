#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <iostream>

using namespace cv;

int main(int argc,char** argv) {
	Mat src = imread("C:\\Users\\Administrator\\Desktop\\test\\1.jpg");
	if (src.empty()) {
		printf("没有图片");
		return -1;
	}
	namedWindow("test open setup", CV_WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);
	waitKey(0);
	return 0;
}
