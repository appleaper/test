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

	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	Mat output_image;
	//cvtColor(src, output_image,CV_BGR2GRAY);	//RGB转灰度图片
	cvtColor(src, output_image, CV_BGR2HSV);	//RGB TO HSV
	//cvtColor(src, output_image, CV_BGR2HLS);	//RGB转HLS
	imshow("output window", output_image);

	//imwrite("F://1.jpg", output_image);		文件保存
	waitKey(0);
	return 0;
}


/*
imread是将加载图片文件成为一个Mat对象
在读图片的后面加上参数:<0表示加载原图，不做任何变换，=0表示作为灰度图，>0表示以RGB格式加载进入
<0也可以写作IMERAD_UNCHANGED,=0：IMREAD_GRAYSCALE,>0:IMREAD_COLOR
*/
