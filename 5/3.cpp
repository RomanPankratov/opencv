#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {


	//«¿ƒ¿Õ»≈ 3
	float kernel3[9];
	kernel3[0] = -3;
	kernel3[1] = 0;
	kernel3[2] = 3;

	kernel3[3] = -10;
	kernel3[4] = 0;
	kernel3[5] = 10;

	kernel3[6] = -3;
	kernel3[7] = 0;
	kernel3[8] = 3;




	float kernel2[9];
	kernel1[0] = -3;
	kernel1[1] = -10;
	kernel1[2] = -3;

	kernel1[3] = 0;
	kernel1[4] = 0;
	kernel1[5] = 0;

	kernel1[6] = 3;
	kernel1[7] = 10;
	kernel1[8] = 3;*/

	CvMat kernel_matrix2 = cvMat(3, 3, CV_32FC1, kernel);
	cvFilter2D(img1, dst2, &kernel_matrix2, cvPoint(-1, -1));

	CvMat kernel_matrix = cvMat(3, 1, CV_32FC1, kernel1);
	cvFilter2D(img1, dst, &kernel_matrix, cvPoint(-1, -1));

	CvMat kernel_matrix1 = cvMat(1, 3, CV_32FC1, kernel2);
	cvFilter2D(dst, dst1, &kernel_matrix1, cvPoint(-1, -1));

	CvMat kernel_matrix3 = cvMat(3, 3, CV_32FC1, kernel3);
	cvFilter2D(img1, dst3, &kernel_matrix3, cvPoint(-1, -1));

	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cvFilter2D", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cvFilter2D1", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cvFilter2D2", CV_WINDOW_AUTOSIZE);
	cvShowImage("original", img1);
	cvShowImage("cvFilter2D", dst2);
	cvShowImage("cvFilter2D1", dst1);
	cvShowImage("cvFilter2D2", dst3);
	cvWaitKey(0);
	return 0;
}
