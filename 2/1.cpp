#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include "/opencv/build/include/opencv2/core/types_c.h"

using namespace std;

int main() { 
	//A
	double b = 0;
	double a = -5.8;
	int c_r = 0;
	b = abs(a);
	c_r = round(b);
	int c_c = ceil(b);
	int c_f = floor(b);

	cout << "ABS " << b << " ROUND" << c_r << " celing  " << c_c << " floor " << c_f;
//B
	srand(4541); // устанавливаем стартовое значение 

// ¬ыводим 100 случайных чисел
	for (int count = 0; count < 100; ++count)
	{
		cout << rand() << "\t";

		// ≈сли вывели 5 чисел, то вставл€ем символ новой строки
		if ((count + 1) % 5 == 0)
			cout << "\n";

	}
	//C
	CvPoint2D32f cvPoint2D32f(double x, double y);

	CvPoint cvPointFrom32f(CvPoint2D32f point);
	//D
	CvPoint2D32f cvPointTo32f(CvPoint point);

	return 0;
}




	


