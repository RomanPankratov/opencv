#include <iostream>
#include "/opencv/build/include/opencv2/core/types_c.h"
#include <cv.h> 
#include <highgui.h> 

int g_slider_position = 0;
CvCapture*  g_capture = NULL;

void onTrackbarSlide(int pos) {
	cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}
//«¿ƒ¿Õ»≈ 2
int main(int argc, char* argv[])
{
	CvCapture* capture = 0;

	cvNamedWindow("TrackBar", CV_WINDOW_AUTOSIZE);
	capture = cvCreateFileCapture(argv[1]);

	if (!capture) {
		return -1;
	}

	IplImage* bgr_frame = cvQueryFrame(capture);
	double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);


	CvSize size = cvSize((int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH), (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));
	CvVideoWriter* writer = cvCreateVideoWriter(argv[2], CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
	IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 3);

	cvReleaseImage(&logpolar_frame);
	cvReleaseVideoWriter(&writer);
	cvReleaseCapture(&capture);

	getchar();

	return(0);
}