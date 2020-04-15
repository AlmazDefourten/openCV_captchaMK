#include <opencv/cv.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/imgcodecs.hpp>
#include <string>
#include <iostream>
using namespace cv;
int main(int argc, char* argv[])
{
	IplImage* src = 0, * dst = 0;
	for (int i = 1000; i <= 10000; i++)
	{
		String mm = "C://Users/almaz/source/repos/mk_cheat/resources/captcha/";
		String png = ".png";
		String dva = "(2)";
		String filenames = mm + std::to_string(i) + dva + png;
		char filename[20];
		
			strcpy(filename, filenames.c_str());
			// получаем картинку
			src = cvLoadImage(filename, 0);
			
			printf("[i] image: %s\n", filename);
			if (src == 0)
			{
				std::cout << filenames << "dont exist";
			}
			else {
			
			dst = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);
			cvInRangeS(src, cvScalar(50), cvScalar(255), dst);
			// показываем результаты
			Mat m = cvarrToMat(dst);
			String pp = "C://Users/almaz/source/repos/mk_cheat/resources/captcha_bin/";
			char exitfile[100];
			String fileexs = pp + std::to_string(i) + dva + png;
			strcpy(exitfile, fileexs.c_str());
			cv::imwrite(exitfile, m);
		}
	}
	return 0;
}
