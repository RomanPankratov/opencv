#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{


	CvConnectedComp mask;
	for (int i = 0; i < mop->width; i++)
	{
		for (int j = 0; j < mop->height; j++)
		{
			CvScalar Pixel = cvGet2D(mop, j, i);

			if (Pixel.val[0] == 255)
			{
				cvFloodFill(mop, cvPoint(j, i), cvScalarAll(100), cvScalarAll(10), cvScalarAll(10), &mask, CV_FLOODFILL_FIXED_RANGE + 8, 0);
			}
		}
	}
	//«¿ƒ¿Õ»≈ 7

	IplImage* dst = cvCreateImage(cvGetSize(src1), IPL_DEPTH_8U, 3);
	cvCopy(src1, dst, mop);


	getchar();

}