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


using namespace cv;
using namespace std;

CvCapture* capture = 0;
IplImage* frame = 0;
IplImage* im_gray;
IplImage* dst = 0;
IplImage* image = 0;
IplImage* src = 0;

int k = 0;

//ЗАДАНИЕ 2
int main() {

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	src = imread("2.png");
	imshow(window_name, src);

	setMouseCallback(window_name, onMouse, 0);

	waitKey(0);

	return 0;
}

void myMouseCallback(int event, int x, int y, int flags, void* param)
{
	IplImage* img = (IplImage*)param;

	switch (event) {
	case CV_EVENT_MOUSEMOVE:
		break;
	case CV_EVENT_LBUTTONDOWN:
		printf("%d x %d\n", x, y);
		drawTarget(img, x, y, 10);
		break;

	case CV_EVENT_LBUTTONUP:
		break;
	}
}

void drawTarget(IplImage* img, int x, int y, int radius)
{

	switch (k) {
	case 1:
		cvCircle(img, Point(x, y), radius, CV_RGB(250, 0, 0), 1, 8);
		break;

	case 2:
		cvLine(img, Point(x - radius / 2, y - radius / 2), Point(x + radius / 2, y + radius / 2), CV_RGB(250, 0, 0), 1, 8);
		break;
	case 3:
		cvRectangle(img, Point(x - radius, y + radius), Point(x + radius, y - radius), CV_RGB(255, 0, 0), 1, 8);
		break;
	case 4:
		cvRectangle(img, Point(x - radius, y + radius), Point(x + radius, y - radius), CV_RGB(255, 255, 255), 20, 8);
		break;
	}
}

void onMouse(int event, int x, int y, int f, void*) {
	image = src.clone();
	//В vec3 хранятся цвета
	Vec3b pix = image.at<Vec3b>(y, x);
	int B = pix.val[0];
	int G = pix.val[1];
	int R = pix.val[2];


	char name[30];
	//printf(name, "R=%s", R);
	cout << "Red" << R << endl;
	cout << "Blue" << B << endl;
	cout << "Green" << G << endl;

}

