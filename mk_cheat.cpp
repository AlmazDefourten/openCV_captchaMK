#include <opencv/cv.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/imgcodecs.hpp>
#include <string>
using namespace cv;
int main(int argc, char* argv[])
{
	IplImage* src = 0, * dst = 0;
	for (int i = 1000; i <= 1003; i++)
	{
		String png = ".png";
		// имя картинки задаётся первым параметром
		String filenames =  std::to_string(i) + png;
		char filename[20];
		strcpy(filename, filenames.c_str());
		// получаем картинку
		src = cvLoadImage(filename, 0);
		printf("[i] image: %s\n", filename);
		assert(src != 0);
		dst = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);
		cvInRangeS(src, cvScalar(50), cvScalar(255), dst);
		// показываем результаты
		Mat m = cvarrToMat(dst);
		cv::imwrite("opencv.jpg", m);
	}
	return 0;
}
