#include <opencv/cv.h>
#include <opencv2/highgui.hpp>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	IplImage* src = 0, * dst = 0;

	// имя картинки задаётся первым параметром
	const char* filename = argc >= 2 ? argv[1] : "lena.png";
	// получаем картинку
	src = cvLoadImage(filename, 0);

	printf("[i] image: %s\n", filename);
	assert(src != 0);

	// покажем изображение
	cvNamedWindow("original", 1);
	cvShowImage("original", src);

	dst = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);

	cvInRangeS(src, cvScalar(50), cvScalar(255), dst);
	IplImage dar = cvSetImageROI(src, cvRect(20, 20, 20, 20));
	// показываем результаты
	cvNamedWindow("cvInRangeS", 1);
	cvShowImage("cvInRangeS", dst);

	// ждём нажатия клавиши
	cvWaitKey(0);

	// освобождаем ресурсы
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	// удаляем окна
	cvDestroyAllWindows();
	return 0;
}