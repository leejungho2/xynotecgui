// This is the main DLL file.

#include "stdafx.h"
#include "ImageEffect.h"

ImageEffect::ApplyBasicEffect::ApplyBasicEffect(System::Drawing::Bitmap^ img)
{
	if (img)
	{
		mImg = img;
		imgWidth = mImg->Width;
		imgHeight = mImg->Height;
	}
}
void ImageEffect::ApplyBasicEffect::SetImage(System::Drawing::Bitmap^ img)
{
	if (img)
	{
		mImg = img;
		imgWidth = mImg->Width;
		imgHeight = mImg->Height;
	}
}

void ImageEffect::ApplyBasicEffect::ApplyColorFilter(Color_Filter filter)
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
					System::Drawing::Imaging::ImageLockMode::ReadWrite, 
					System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	
	
	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;
	
	ColorFilter(data, imgWidth, imgHeight, (COLOR_FILTER)filter);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyGamma(double red, double green, double blue)
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Gamma(data, imgWidth, imgHeight, red, green, blue);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyBrightness(int brightness)
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Brightness(data, imgWidth, imgHeight, brightness);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyContrast(double contrast)
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Contrast(data, imgWidth, imgHeight, contrast);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyGrayscale()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Grayscale(data, imgWidth, imgHeight);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyInvert()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Invert(data, imgWidth, imgHeight);

	mImg->UnlockBits(bmData);

}
