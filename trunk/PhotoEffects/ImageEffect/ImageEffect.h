// ImageEffect.h

#pragma once

using namespace System;
using namespace System::Drawing;

#include "BasicEffect.h"
namespace ImageEffect {

	public enum class Color_Filter
	{
		Color_Red = COLOR_RED,
		Color_Green = COLOR_GREEN,
		Color_Blue = COLOR_BLUE
	};

	public ref class ApplyBasicEffect
	{
		// TODO: Add your methods for this class here.
		public:
			ApplyBasicEffect(System::Drawing::Bitmap^ img);	

			void SetImage(System::Drawing::Bitmap^ img);

			void ApplyColorFilter(Color_Filter filter);
			void ApplyGamma(double red, double green, double blue);
			void ApplyBrightness(int brightness);
			void ApplyContrast(double contrast);
			void ApplyGrayscale();
			void ApplyInvert();

			//////////////////////////////////////////////////////////////////////////
			void ApplySmooth();
			void ApplyGaussianBlur();
			void ApplyMeanRemoval();
			void ApplySharpen();
			void ApplyEmbossLaplacian();
			void ApplyEdgeDetectQuick();

			//////////////////////////////////////////////////////////////////////////
			void ApplyFlip();
			void ApplyRandomJitter();
			void ApplySwirl();
			void ApplySphere();
			void ApplyTimeWarp();
			void ApplyMoire();
			void ApplyWater();
			void ApplyPixelate();

			void ApplyFishEye();
			
		private:
			System::Drawing::Bitmap^ mImg;
			int imgWidth;
			int imgHeight;
		
	};
}
