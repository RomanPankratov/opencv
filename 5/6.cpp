#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
//ÇÀÄÀÍÈÅ 6
IplImage* img1 = cvLoadImage("2.jpg", CV_LOAD_IMAGE_GRAYSCALE);
IplImage* src = cvLoadImage("2.jpg");
IplImage* dst = cvCloneImage(img1);

CvMemStorage* storage = cvCreateMemStorage(0);

cvSmooth(img1, img1, CV_GAUSSIAN, 5, 5);

//cvLaplace(img1, dst, 5);
//cvSobel(img1, dst, 1, 1, 3);
cvNamedWindow("Sobel", 1);
cvShowImage("Sobel", dst);

CvSeq* results = cvHoughCircles(img1, storage, CV_HOUGH_GRADIENT, 3, img1->width / 5.5, 100, 100, 20, 27);

cout << results->total;

for (int i = 0; i < results->total; i++) {
	float* p = (float*)cvGetSeqElem(results, i);
	CvPoint pt = cvPoint(cvRound(p[0]), cvRound(p[1]));
	cvCircle(src, pt, cvRound(p[2]), CV_RGB(255, 0, 0));
}
cvNamedWindow("cvHoughCircles", 1);
cvShowImage("cvHoughCircles", src);
cvNamedWindow("original", 1);
cvShowImage("original", img1);
cvWaitKey(0);
cvReleaseMemStorage(&storage);
cvDestroyAllWindows();
return 0;


}