#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include "/opencv/build/include/opencv2/core/types_c.h"

using namespace std;

	int main() {
		//ЗАДАНИЕ 5

		Mat mat = Mat::zeros(210, 210, CV_8UC1);

		Mat image;
		image = imread("IMG_5436.jpg", CV_LOAD_IMAGE_COLOR);

		IplImage tmp = mat;



		Mat img2;

		img2 += CV_RGB(0, 0, 255);

		for (int j = 0; j <= 200; j++)
			for (int i = 20; i < 200; i++) {
				int x = i + 120;
				int y = j + 10;
				Rect r(x, y, i + 260, i + 30);  // Создание региона
				image(r) += CV_RGB(0, 0, 255);
				image(r).copyTo(img2);
			}

		namedWindow("Display window", CV_WINDOW_AUTOSIZE);
		imshow("Display window", image);

		cvWaitKey(0);

		cvDestroyAllWindows;

		// interest_img - исходное изображение
		// interest_rect - запрашиваемая область
		// sub_img - контейнер под запрашиваемую область

		// Создание заголовка изображения (контейнер)
		// 

			Mat interest_img;
		interest_img = imread("1.jpg", CV_LOAD_IMAGE_COLOR);


			IplImage interest_img1 = interest_img;

			int_rect = cvRect(200, 200, 260, 300);

			int_rect = cvRectangle(&interest_img1, Point(20, 20), Point(150, 150), Scalar(0, 0, 255));

			char* filename = argc >= 2 ? argv[1] : "1.jpg";
			// получаем картинку


		
			image = cvLoadImage("1.jpg", 1);

			Rect r(200, 200, 260, 300);

			IplImage* sub_img = cvCreateImageHeader(
				cvSize(
					20
					, 30
				)
				, image->depth
				, image->nChannels
			);

			// Начало координат
			//
			sub_img->origin = image->origin;

			// Шаг
			//
			sub_img->widthStep = image->widthStep;

			cvNot(image, sub_img);

			namedWindow("Display window", CV_WINDOW_AUTOSIZE);
			cvShowImage("Display window", sub_img);

			cvWaitKey(0);

			return 0;
}