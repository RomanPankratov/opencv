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


//«¿ƒ¿Õ»≈ 3

	
	IplImage* img = cvLoadImage("1.png");
	IplImage* dst9x9 = cvCloneImage(img);
	IplImage* dst9x9_1 = cvCloneImage(img);
	IplImage* dst9x9_2 = cvCloneImage(img);
	

	cvSmooth(img, dst9x9, CV_GAUSSIAN, 9, 9, 1);
	cvSmooth(img, dst9x9_1, CV_GAUSSIAN, 9, 9, 4);
	cvSmooth(img, dst9x9_2, CV_GAUSSIAN, 9, 9, 6);
	
	cvSmooth(img, dst9x9, CV_GAUSSIAN, 0, 0, 1);
	cvSmooth(img, dst9x9_1, CV_GAUSSIAN, 0, 0, 4);
	cvSmooth(img, dst9x9_2, CV_GAUSSIAN, 0, 0, 6);
	
	cvSmooth(img, dst9x9, CV_GAUSSIAN, 0, 0, 1, 9);
	cvSmooth(img, dst9x9_1, CV_GAUSSIAN, 0, 0, 1, 9);
	cvSmooth(img, dst9x9_2, CV_GAUSSIAN, 0, 0, 1, 9);
	
	cvSmooth(img, dst9x9, CV_GAUSSIAN, 0, 0, 9, 1);
	cvSmooth(img, dst9x9_1, CV_GAUSSIAN, 0, 0, 9, 1);
	cvSmooth(img, dst9x9_2, CV_GAUSSIAN, 0, 0, 9, 1);
	
	cvSmooth(img, dst9x9, CV_GAUSSIAN, 0, 0, 1, 9);
	cvSmooth(img, dst9x9, CV_GAUSSIAN, 0, 0, 9, 1);
	
	cvSmooth(img, dst9x9, CV_GAUSSIAN, 0, 0, 9, 9);
	cvSmooth(img, dst9x9_1, CV_GAUSSIAN, 0, 0, 0, 0);
	
	
	cvShowImage("original", img);
	cvShowImage("smooth 1", dst9x9);
	cvShowImage("smooth 4", dst9x9_1);
	cvShowImage("smooth 6", dst9x9_2);

	cvWaitKey(0);
	return 0;
	}
