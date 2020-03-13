// 3_3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string window_name = "binaryMat";

void threshod_Mat(int th, void* data)
{
	Mat src = *(Mat*)(data);

	Mat dst;

	threshold(src, dst, th, 255, 0);

	imshow(window_name, dst);
}

int main()
{
	Mat srcMat;
	Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;

	srcMat = imread("D:\\1.jpg");
	if (!srcMat.data)
	{
		cout << "ͼ������ʧ�ܣ�" << endl;
		return 0;
	}

	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
	imshow(window_name, gryMat);
	createTrackbar("threshould",
		            window_name,
		            &lowTh,
		            maxTh,
		            threshod_Mat,
		            &gryMat);
    waitKey(0);
   
    return 0;
}

