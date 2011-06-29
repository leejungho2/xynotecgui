// This is the main DLL file.

#include "stdafx.h"
#include "ImageEffect.h"

ImageEffect::ApplyImageEffect::ApplyImageEffect(System::Drawing::Image^ img)
{
	mImg = img;
}

void ImageEffect::ApplyImageEffect::ApplyColorFilter(/*COLOR_FILTER filter*/)
{

}
void ImageEffect::ApplyImageEffect::ApplyGamma(double red, double green, double blue)
{

}
void ImageEffect::ApplyImageEffect::ApplyBrightness(int brightness)
{

}
void ImageEffect::ApplyImageEffect::ApplyContrast(double contrast)
{

}
void ImageEffect::ApplyImageEffect::ApplyGrayscale()
{

}
void ImageEffect::ApplyImageEffect::ApplyInvert()
{

}
