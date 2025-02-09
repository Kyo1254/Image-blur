// ImageObject.cpp : 정적 라이브러리를 위한 함수를 정의합니다.
#include "pch.h"
#include "ImageObject.h"

ImageObject::ImageObject() : imageData(nullptr), width(0), height(0) {}

ImageObject::~ImageObject()
{
	if (imageData)
	{
		delete[] imageData;
		imageData = nullptr;
	}
}

cv::Mat ImageObject::ToMat() const
{
	cv::Mat mat(height, width, CV_8UC1, imageData);
	return mat;
}

bool ImageObject::FromMat(const cv::Mat& mat)
{
	width = mat.cols;
	height = mat.rows;

	delete[] imageData;
	imageData = new unsigned char[width * height * 1];

	memcpy(imageData, mat.data, width * height * 1);

	return true;
}