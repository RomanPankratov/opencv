#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//ЗАДАНИЕ 1

	IplImage* img1 = cvLoadImage("1.png");

	IplImage* dst = cvCreateImage(cvGetSize(img1), IPL_DEPTH_8U, 1);
	IplImage* color_dst = cvCreateImage(cvGetSize(img1), IPL_DEPTH_8U, 3);

	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* lines = 0;
	int i = 0;

	cvCanny(img1, dst, 50, 200, 3);

	cvCvtColor(dst, color_dst, CV_GRAY2BGR);

	//нахождение линий
	lines = cvHoughLines2(dst, storage, CV_HOUGH_PROBABILISTIC, 1, CV_PI / 3, 50, 50, 10);

	//рисуем найденные линии
	for (i = 0; i < lines->total; i++) {
		CvPoint* line = (CvPoint*)cvGetSeqElem(lines, i);
		cvLine(color_dst, line[0], line[1], CV_RGB(255, 0, 0), 3, CV_AA, 0);
	}

	cvNamedWindow("Source", 1);
	cvShowImage("Source", img1);

	cvNamedWindow("Hough", 1);
	cvShowImage("Hough", color_dst);

	cvWaitKey(0);
	cvReleaseMemStorage(&storage);
	cvReleaseImage(&img1);
	cvReleaseImage(&dst);
	cvReleaseImage(&color_dst);
	cvDestroyAllWindows();
	return 0;
}
