//opencv读取视频 c++

#include <opencv2/core/core.hpp> 
#include <opencv2/imgcodecs.hpp> 
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <iostream>

using namespace cv;
using namespace std;



int main(int argc, char** args) {
	VideoCapture capture("C:\\Users\\Administrator\\Desktop\\opencv\\1.mp4");
	if (capture.isOpened() == false) {		//是否能打开
		cout << "fail open" << endl;
	}

	long totalFrameNumber = capture.get(CAP_PROP_FRAME_COUNT);		//获取视频总共帧数
	cout << "整个视频共" << totalFrameNumber << "帧" << endl;

	//设置开始读取的帧数
	long frameToStart = 1;
	capture.set(CAP_PROP_POS_FRAMES, frameToStart);
	cout << "从第" << frameToStart << "帧开始读" << endl;

	//设置结束的帧数
	int frameToStop = 300;
	if (frameToStop < frameToStart) {
		cout << "结束帧小于开始帧，错误！" << endl;
		return -1;
	}
	else {
		cout << "结束帧为：第" << frameToStop << "帧" << endl;
	}

	//获取帧率
	double rate = capture.get(CAP_PROP_FPS);
	cout << "帧率为" << rate << endl;

	bool stop = false;
	Mat frame;

	double delay = 1000 / rate;
	long currentFrame = frameToStart;

	while (stop == false) {
		if (capture.read(frame) == false) {		//读取视频，frame是Mat，capture是已经读取的图片
			cout << "读取视频失败" << endl;
			return -1;
		}
		if (currentFrame % 50 == 0) {
			cout << "正在写第" << currentFrame << "帧" << endl;
			stringstream str;
			str << "C:\\Users\\Administrator\\Desktop\\opencv\\" << currentFrame << ".png";
			cout << str.str() << endl;
			imwrite(str.str(), frame);		//写图片
		}
		currentFrame++;
		int c = waitKey(delay);
		if ((char)c == 27 || currentFrame > frameToStop) {
			stop = true;
			if (c >= 0) {
				waitKey(0);
			}
		}
	}
	capture.release();
	waitKey(0);
	return 0;
}
