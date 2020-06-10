#include <iostream>
#include "\opencv\build\include\opencv\cv.h"
#include "/opencv/build/include/opencv/highgui.h"
#include "/opencv/build/include/opencv2/opencv.hpp"
#include <stdlib.h>
#include "opencv/cv.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv/highgui.h"
#include "opencv2/imgproc.hpp"
#include <stdio.h>
#include <conio.h>
#include "windows.h"


int main()
{

	// «¿ƒ¿Õ»≈ 3

	int rows = 100;
	int cols = 100;
	int size = rows * cols;
	float* data = new float[size];
	for (int i = 0; i < size; i++)
		data[i] = 0.0;

	CvMat* Picture1 = new CvMat();
	Picture1[0] = cvMat(rows, cols, CV_8UC1, data);
	for (int row = 20; row < 40; row++)
	{
		for (int col = 5; col < 20; col++)
		{
			*cvPtr2D(Picture1, row, col) = 255;
		}
	}

	cvNamedWindow("Square", CV_WINDOW_AUTOSIZE);
	cvShowImage("Square", Picture1);
	cvWaitKey(0);
	cvDestroyWindow("Square");

}