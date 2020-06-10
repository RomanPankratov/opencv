#include <iostream>
#include "/opencv/build/include/opencv2/core/types_c.h"
#include <cv.h> 
#include <highgui.h> 

int g_slider_position = 0;
CvCapture*  g_capture = NULL;

void onTrackbarSlide(int pos) {
	cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}

int main(int argc, char* argv[])
{

	while ((bgr_frame = cvQueryFrame(capture)) != NULL) {
		//ЗАДАНИЕ 3
		cvLogPolar(bgr_frame, logpolar_frame, cvPoint2D32f(bgr_frame->width / 2, bgr_frame->height / 2), 40, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
		IplImage* logpolar_frame_wr = cvCreateImage(cvSize(logpolar_frame->width / 2, logpolar_frame->height / 2), logpolar_frame->depth, logpolar_frame->nChannels);
		cvPyrDown(logpolar_frame, logpolar_frame_wr); // сжатие изображения в 2 раза
		cvWriteFrame(writer, logpolar_frame_wr);

	}

	cvReleaseImage(&logpolar_frame);
	cvReleaseVideoWriter(&writer);
	cvReleaseCapture(&capture);

	getchar();

	return(0);
}