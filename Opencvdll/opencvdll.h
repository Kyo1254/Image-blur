#pragma once
#include "ImageObject.h"
#include "opencv2/opencv.hpp"

extern "C"
{
	__declspec(dllexport) bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize) {
		if (src->type != 1)
		{
			throw std::runtime_error{ "Gray Image°¡ ¾Æ´Õ´Ï´Ù." };
		}
		
		cv::Mat srcMat = src->ToMat();

		cv::Mat dstMat;
		cv::blur(srcMat, dstMat, cv::Size(kernelSize, kernelSize));

		return true;
	}
}

