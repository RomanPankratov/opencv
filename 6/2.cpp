#include <iostream>
#include <vector>

#include <cxcore.h>
#include <cv.h> 
#include <_highgui.h>

static CvMemStorage* storage = 0;

int main()
{
	//«¿ƒ¿Õ»≈  6

	IplImage* src = cvLoadImage("../3/picture/lol.png");
	IplImage* dst = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);

	float kernel[9] = { 1 / 16,  2 / 16,  1 / 16, 2 / 16,  4 / 16, 2 / 16, 1 / 16, 2 / 16, 1 / 16 };
	CvMat kernel_matrix = cvMat(3, 3, CV_32FC1, kernel);
	cvFilter2D(src, dst, &kernel_matrix);

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", dst);
	cvWaitKey(0);
	cvDestroyWindow("Square");


}

/*int main()
{

//«¿ƒ¿Õ»≈ 2 ¡

	IplImage* src = cvLoadImage("../Part3/picture/88.png");
	IplImage* dst = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);

	float kernel1[9] = { 1 / 4, 2 / 4, 1 / 4, 1 / 4, 2 / 4, 1 / 4 , 1 / 4, 2 / 4, 1 / 4 };
	float kernel2[9] = { 1 / 4, 1 / 4, 1 / 4, 2 / 4, 2 / 4, 2 / 4 , 1 / 4, 1 / 4, 1 / 4 };
	CvMat kernel_matrix1 = cvMat(3, 3, CV_32FC1, kernel1);
	CvMat kernel_matrix2 = cvMat(3, 3, CV_32FC1, kernel2);
	cvFilter2D(src, dst, &kernel_matrix1);
	cvFilter2D(dst, dst, &kernel_matrix2);

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", dst);
	cvWaitKey(0);
	cvDestroyWindow("Square");


}*/