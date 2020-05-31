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

int main() {


	//ЗАДАНИЕ 4

	Mat img1;
	Mat img2;
	// получаем информацию о видео-файле
	capture = cvCreateFileCapture("Megamind.avi");
	VideoCapture cap;
	cap.open("Megamind.avi");

	// получаем число кадров
	double framesCount = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
	printf("[i] count: %.0f\n", framesCount);
	int frames = (int)framesCount;

	namedWindow("original image", CV_WINDOW_AUTOSIZE);
	int currentPosition = 0;
	if (frames != 0) {
		// показываем ползунок
		cvCreateTrackbar("Position", "original image", &currentPosition, frames, myTrackbarCallback);
	}

	bool playVideo = true;
	while (1) {

		// получаем следующий кадр
		frame = cvQueryFrame(capture);
		dst = cvCloneImage(frame);
		img2 = cvarrToMat(frame);


		if (!frame) {
			break;
		}
		//преобразование в Mat, чтобы отобразить
		if (playVideo) {
			cap >> img1;
		}
		imshow("original image", img1);
		char key = waitKey(33);
		if (key == 'p')
			playVideo = !playVideo;

		char c = cvWaitKey(33);
		if (c == 27) { // если нажата ESC - выходим
			break;
		}
	}

	// освобождаем ресурсы
	cvReleaseCapture(&capture);
	// удаляем окно
	cvDestroyWindow("original image");
	return 0;
}

void myTrackbarCallback(int pos) {
	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, pos);
}

	
