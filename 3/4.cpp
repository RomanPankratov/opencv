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


	//������� 4

	Mat img1;
	Mat img2;
	// �������� ���������� � �����-�����
	capture = cvCreateFileCapture("Megamind.avi");
	VideoCapture cap;
	cap.open("Megamind.avi");

	// �������� ����� ������
	double framesCount = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
	printf("[i] count: %.0f\n", framesCount);
	int frames = (int)framesCount;

	namedWindow("original image", CV_WINDOW_AUTOSIZE);
	int currentPosition = 0;
	if (frames != 0) {
		// ���������� ��������
		cvCreateTrackbar("Position", "original image", &currentPosition, frames, myTrackbarCallback);
	}

	bool playVideo = true;
	while (1) {

		// �������� ��������� ����
		frame = cvQueryFrame(capture);
		dst = cvCloneImage(frame);
		img2 = cvarrToMat(frame);


		if (!frame) {
			break;
		}
		//�������������� � Mat, ����� ����������
		if (playVideo) {
			cap >> img1;
		}
		imshow("original image", img1);
		char key = waitKey(33);
		if (key == 'p')
			playVideo = !playVideo;

		char c = cvWaitKey(33);
		if (c == 27) { // ���� ������ ESC - �������
			break;
		}
	}

	// ����������� �������
	cvReleaseCapture(&capture);
	// ������� ����
	cvDestroyWindow("original image");
	return 0;
}

void myTrackbarCallback(int pos) {
	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, pos);
}

	
