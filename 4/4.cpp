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


//ÇÀÄÀÍÈÅ 4	

	int iterations = 1;
	int radius = 1;



	IplImage* img = cvLoadImage("1.png");
	IplImage* erode = 0;
	IplImage* dilate = 0;

	Mat img1 = imread("1.png");
	Mat img2 = imread("1.png");

	Mat dst = img1 - img2;
	
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("smooth 3õ3", CV_WINDOW_AUTOSIZE);
	imshow("original", dst);
	cvWaitKey(0);
	
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("erode", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("dilate", CV_WINDOW_AUTOSIZE);
	erode = cvCloneImage(img);
	dilate = cvCloneImage(img);

	// ñîçäà¸ì ÿäðî
	IplConvKernel* Kern = cvCreateStructuringElementEx(radius * 2 + 1, radius * 2 + 1, radius, radius, CV_SHAPE_ELLIPSE);
	cvErode(img, erode, Kern, iterations);
	cvDilate(img, dilate, Kern, iterations);
	//IplImage* image = cvCloneImage(&(IplImage)img1);


	//cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvShowImage("erode", erode);
	cvShowImage("dilate", dilate);
	cvReleaseStructuringElement(&Kern);
	cvWaitKey(0);
	return 0;
	}
