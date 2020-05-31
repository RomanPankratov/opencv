#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "/opencv/build/include/opencv/highgui.h"
#include "/opencv/build/include/opencv/cv.h"
#include "/opencv/build/include/opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main() {
	//«¿ƒ¿Õ»≈ 2
		
		Mat img = Mat::zeros(200, 200, CV_8UC3);

		img.at<Vec3b>(100, 100)[0] = 255;
		img.at<Vec3b>(100, 100)[1] = 255;
		img.at<Vec3b>(100, 100)[2] = 255;

		IplImage* image = cvCloneImage(&(IplImage)img);
		IplImage* image5x5 = cvCloneImage(&(IplImage)img);
		IplImage* image9x9 = cvCloneImage(&(IplImage)img);

		cvSmooth(image, image5x5, CV_GAUSSIAN, 5, 5);
		cvSmooth(image, image9x9, CV_GAUSSIAN, 9, 9);

		cvShowImage("original", image);
		cvShowImage("original5x5", image5x5);
		cvShowImage("original9x9", image9x9);

		waitKey(0);
		return 0;
		
}