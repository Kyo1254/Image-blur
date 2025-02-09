#pragma once
#include "ImageObject.h"
#include <stdexcept>

extern "C"
{
	__declspec(dllexport) bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize)
	{
		if (src->type != 1)
		{
			throw std::runtime_error{ "Gray Image°¡ ¾Æ´Õ´Ï´Ù." };
		}
		dst->width = src->width;
		dst->height = src->height;
		dst->type = src->type;
		dst->imageData = new unsigned char[dst->width * dst->height];

		int halfKernel = kernelSize / 2;

		for (int y = halfKernel; y < src->height - halfKernel; y++)
		{
			for (int x = halfKernel; x < src->width - halfKernel; x++)
			{
				int sum = 0;
				for (int ky = -halfKernel; ky <= halfKernel; ky++)
				{
					for (int kx = -halfKernel; kx <= halfKernel; kx++)
					{
						unsigned char* pixel = src->imageData + (y + ky) * src->width + (x + kx);
						sum += *pixel;
					}
				}
				int avg = sum / (kernelSize * kernelSize);

				unsigned char* pixel = dst->imageData + y * dst->width + x;
				*pixel = avg;
			}
		}

		return true;
	}
}