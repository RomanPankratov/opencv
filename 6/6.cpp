#include <iostream>
#include <vector>

#include <cxcore.h>
#include <cv.h> 
#include <_highgui.h>

static CvMemStorage* storage = 0;

int main()
{

	//«¿ƒ¿Õ»≈ 6


	static CvScalar colors[] =
	{
		{{0,0,255}},
		{{0,128,255}},
		{{0,255,255}},
		{{0,255,0}},
		{{255,128,0}},
		{{255,255,0}},
		{{255,0,0}},
		{{255,0,255}}
	};


	IplImage* src = cvLoadImage("../6/picture/LICO.jpg");
	IplImage* gray = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	cvCvtColor(src, gray, CV_BGR2GRAY);

	
	CvMemStorage* storage = cvCreateMemStorage(0);
	cvSmooth(gray, gray, CV_GAUSSIAN, 9, 9);
	CvSeq* circles = cvHoughCircles(gray, storage, CV_HOUGH_GRADIENT, 1, 20, 50, 30, 1, 30);
	for (int j = 0; j < circles->total; j++)
	{
		float* p = (float*)cvGetSeqElem(circles, j);
		cvCircle(src, cvPoint(p[0], p[1]), p[2], colors[3], 2);
	}

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", src);
	cvWaitKey(0);
	cvDestroyWindow("Square");

}