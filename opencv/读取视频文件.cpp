

#include <opencv2/opencv.hpp>
using namespace cv;

void main() {
	VideoCapture cap;
	cap.open("./tree.avi");
	if (!cap.isOpened())
		return;
	Mat frame;
	while (1) {
		cap >> frame;
		if (frame.empty())
			break;
		imshow("video", frame);
		waitKey(20);
	}
	cap.release();
}
