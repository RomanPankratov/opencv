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


	//ÇÀÄÀÍÈÅ 5

	int iterations = 5;
	int radius = 1;
	IplImage* gray = 0;
	IplImage* gray1 = 0;
	IplImage* img = cvLoadImage("1.png");
	IplImage* img1 = cvLoadImage("2.png");
	gray = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_8U, 1);
	gray1 = cvCreateImage(cvSize(img1->width, img1->height), IPL_DEPTH_8U, 1);
	cvConvertImage(img, gray, CV_BGR2GRAY);
	cvConvertImage(img1, gray1, CV_BGR2GRAY);
	IplImage* dst = cvCloneImage(gray);
	IplImage* dst1 = cvCloneImage(gray1);
	IplImage* dst2 = cvCloneImage(gray);


	cvAbsDiff(gray, gray1, dst);

	IplImage* Temp = 0;
	Temp = cvCreateImage(cvSize(gray->width, gray->height), IPL_DEPTH_8U, 1);

	IplConvKernel* Kern = cvCreateStructuringElementEx(radius * 2 + 1, radius * 2 + 1, radius, radius, CV_SHAPE_ELLIPSE);
	cvDilate(dst, dst1, Kern, 2);

	cvShowImage("orig", img);
	cvShowImage("mask", img1);
	cvShowImage("gray", gray);
	cvShowImage("gray1", gray1);
	cvShowImage("DIFF", dst);

	cvThreshold(gray, dst, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 3);

	//cvDilate(dst, dst1, Kern, iterations);

	cvMorphologyEx(dst1, dst2, Temp, Kern, CV_MOP_OPEN, iterations);

	cvShowImage("Dilate", dst1);
	cvShowImage("Morpho", dst2);

	cvReleaseStructuringElement(&Kern);
	cvWaitKey(0);
	return 0;
}
