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

int main(){
	//ЗАДАНИЕ 5
		// имя картинки задаётся первым параметром
	IplImage* img = cvLoadImage("2.png");
	// получаем картинку

	// клонируем картинку 
	src = cvCloneImage(img);


	// окно для отображения картинки
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);

	// вешаем обработчик мышки
	cvSetMouseCallback("original", myMouseCallback, (void*)img);

	while (1) {
		char key = cvWaitKey(40);
		if (key == 'o') {
			printf("Oval");
			k = 1;
		}
		if (key == 'l') {
			printf("Line");
			k = 2;
		}
		if (key == 'r') {
			printf("rectangle");
			k = 3;
		}
		if (key == 'q') {
			printf("rectangle");
			k = 4;
		}

		// показываем картинку
		cvCopyImage(img, src);
		cvShowImage("original", src);

		char c = cvWaitKey(33);
		if (c == 27) { // если нажата ESC - выходим
			break;
		}

	}

	// освобождаем ресурсы
	cvReleaseImage(&image);
	cvReleaseImage(&src);
	// удаляем окно
	cvDestroyWindow("original");
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
