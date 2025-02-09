#pragma once
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;

class ImageObject
{
public:
	int width;
	int height;
	unsigned char* imageData;
	int type; // 

	ImageObject();
	~ImageObject();

	cv::Mat ToMat() const;

	bool FromMat(const cv::Mat& mat);
};