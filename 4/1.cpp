#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "/opencv/build/include/opencv/highgui.h"
#include "/opencv/build/include/opencv/cv.h"
#include "/opencv/build/include/opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {

	//«¿ƒ¿Õ»≈ 1

	IplImage* img = cvLoadImage("1.png");
	IplImage* dst3x3 = cvCloneImage(img);
	IplImage* dst5x5 = cvCloneImage(img);
	IplImage* dst9x9 = cvCloneImage(img);
	IplImage* dst11x11 = cvCloneImage(img);

	cvSmooth(img, dst3x3, CV_GAUSSIAN, 3, 3);
	cvSmooth(img, dst5x5, CV_GAUSSIAN, 5, 5);
	cvSmooth(img, dst9x9, CV_GAUSSIAN, 9, 9);
	cvSmooth(img, dst11x11, CV_GAUSSIAN, 11, 11);


	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("smooth 3ı3", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("smooth 5ı5", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("smooth 9ı9", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("smooth 11ı11", CV_WINDOW_AUTOSIZE);

	cvShowImage("original", img);
	cvShowImage("smooth 3ı3", dst3x3);
	cvShowImage("smooth 5ı5", dst5x5);
	cvShowImage("smooth 9ı9", dst9x9);
	cvShowImage("smooth 11ı11", dst11x11);

	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("original");
	cvDestroyWindow("smooth 3ı3");
	cvDestroyWindow("smooth 5ı5");
	cvDestroyWindow("smooth 9ı9");
	cvDestroyWindow("smooth 11ı11");
	return 0;
}
