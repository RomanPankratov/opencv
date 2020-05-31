#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {


//«¿ƒ¿Õ»≈ 4
	
	IplImage* img1 = cvLoadImage("2.png");
	IplImage* dst = cvCloneImage(img1);
	IplImage* dst1 = cvCloneImage(img1);
	IplImage* dst2 = cvCloneImage(img1);


	cvSobel(img1, dst1, 1, 1, 3);
	cvSobel(img1, dst, 1, 1, 5);
	cvSobel(img1, dst2, 1, 1, 13);
	//cvLaplace(img1, dst, 5);
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cvFilter2D", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cvFilter2D1", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cvFilter2D2", CV_WINDOW_AUTOSIZE);
	cvShowImage("original", img1);
	cvShowImage("cvFilter2D", dst1);
	cvShowImage("cvFilter2D1", dst);
	cvShowImage("cvFilter2D2", dst2);
	cvWaitKey(0);
	return 0;
	}
