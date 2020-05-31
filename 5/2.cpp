#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {


	//«¿ƒ¿Õ»≈ 2
	IplImage* img1 = cvLoadImage("1.png");
	IplImage* dst = cvCloneImage(img1);
	IplImage* dst1 = cvCloneImage(img1);
	IplImage* dst2 = cvCloneImage(img1);
	IplImage* dst3 = cvCloneImage(img1);

	float kernel[9];
	kernel[0] = 0.0625;
	kernel[1] = 0.125;
	kernel[2] = 0.0625;

	kernel[3] = 0.125;
	kernel[4] = 0.25;
	kernel[5] = 0.125;

	kernel[6] = 0.0625;
	kernel[7] = 0.125;
	kernel[8] = 0.0625;

	float kernel1[3];
	kernel1[0] = 0.25;
	kernel1[1] = 0.5;
	kernel1[2] = 0.25;

	float kernel2[3];
	kernel2[0] = 0.25;
	kernel2[1] = 0.5;
	kernel2[2] = 0.25;
}