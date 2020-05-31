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

int main(int argc, char* argv[])
{
	//ЗАДАНИЕ 1


	capture = cvCreateFileCapture("Megamind.avi");

	double framesCount = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
	printf("[i] count: %.0f\n", framesCount);
	int frames = (int)framesCount;



	namedWindow("original image", CV_WINDOW_AUTOSIZE);
	namedWindow("nonoriginal image", CV_WINDOW_AUTOSIZE);

	while (1) {
		// получаем следующий кадр
		frame = cvQueryFrame(capture);
		dst = cvCloneImage(frame);

		Mat img1 = cvarrToMat(frame);
		Mat img2 = cvarrToMat(dst);
		Mat img3 = cvarrToMat(dst);

		cvtColor(img1, img2, CV_RGB2GRAY);

		if (!frame) {
			break;
		}

		Canny(img2, img3, 50, 100, 5);


		imshow("original image", img1);
		imshow("nonoriginal image", img2);
		imshow("nonoriginal image1", img3);



		char c = cvWaitKey(33);
		if (c == 27) { // если нажата ESC - выходим
			break;
		}
	}

	// освобождаем память
	cvReleaseCapture(&capture);
	// удаляем окно
	cvDestroyWindow("original");
	return 0;
}
