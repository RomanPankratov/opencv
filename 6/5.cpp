#include <iostream>
#include <vector>

#include <cxcore.h>
#include <cv.h> 
#include <_highgui.h>

static CvMemStorage* storage = 0;

int main()
{

	IplImage* src = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
	cvZero(src);
	for (int i = 0; i <= src->height; i += 2)
	{
		cvLine(src, cvPoint(0, i), cvPoint(src->height - i, src->height), cvScalarAll(255), 1);
		cvLine(src, cvPoint(i, 0), cvPoint(src->height, src->height - i), cvScalarAll(255), 1);
	}
	IplImage* dst = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 3);
	float kernel_x[9] = { -3, 0, 3, -10, 0, 10, -3, 0, 3 };
	float kernel_y[9] = { -3, -10, -3, 0, 0, 0, 3, 10, 3 };
	CvMat kernel_matrix = cvMat(13, 13, CV_32FC1, kernel_y);
	cvFilter2D(src, dst, &kernel_matrix);
	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", dst);
	cvWaitKey(0);
	cvDestroyWindow("Square");
}