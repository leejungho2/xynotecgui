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

	//Invert(data, imgWidth, imgHeight);
	Vignette(data, imgWidth, imgHeight);

	mImg->UnlockBits(bmData);

}

void ImageEffect::ApplyBasicEffect::ApplySmooth()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Smooth(data, imgWidth, imgHeight, 1);

	mImg->UnlockBits(bmData);
}

void ImageEffect::ApplyBasicEffect::ApplyGaussianBlur()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	GaussianBlur(data, imgWidth, imgHeight, 4);

	mImg->UnlockBits(bmData);
}

void ImageEffect::ApplyBasicEffect::ApplyMeanRemoval()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	MeanRemoval(data, imgWidth, imgHeight, 9);

	mImg->UnlockBits(bmData);
}

void ImageEffect::ApplyBasicEffect::ApplySharpen()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Sharpen(data, imgWidth, imgHeight, 11);

	mImg->UnlockBits(bmData);
}

void ImageEffect::ApplyBasicEffect::ApplyEmbossLaplacian()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	EmbossLaplacian(data, imgWidth, imgHeight);

	mImg->UnlockBits(bmData);
}

void ImageEffect::ApplyBasicEffect::ApplyEdgeDetectQuick()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	EdgeDetectQuick(data, imgWidth, imgHeight);

	mImg->UnlockBits(bmData);
}

void ImageEffect::ApplyBasicEffect::ApplyFlip()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Flip(data, imgWidth, imgHeight, true, true);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyRandomJitter()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	RandomJitter(data, imgWidth, imgHeight, 5);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplySwirl()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Swirl(data, imgWidth, imgHeight, .04, false);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplySphere()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Sphere(data, imgWidth, imgHeight, false);
	
	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyTimeWarp()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	TimeWarp(data, imgWidth, imgHeight, 15, false);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyMoire()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Moire(data, imgWidth, imgHeight, 3);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyWater()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Water(data, imgWidth, imgHeight, 15, false);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyPixelate()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Pixelate(data, imgWidth, imgHeight, 15, false);

	mImg->UnlockBits(bmData);
}
void ImageEffect::ApplyBasicEffect::ApplyFishEye()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	FishEye(data, imgWidth, imgHeight, 0.03, false, false);

	mImg->UnlockBits(bmData);
}