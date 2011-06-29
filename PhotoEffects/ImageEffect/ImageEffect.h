// ImageEffect.h

#pragma once

using namespace System;

//#include "BasicEffect.h"
namespace ImageEffect {

	public ref class ApplyImageEffect
	{
		// TODO: Add your methods for this class here.
		public:
			System::Drawing::Image^ mImg;

			ApplyImageEffect(System::Drawing::Image^ img);	

			void ApplyColorFilter(/*COLOR_FILTER filter*/);
			void ApplyGamma(double red, double green, double blue);
			void ApplyBrightness(int brightness);
			void ApplyContrast(double contrast);
			void ApplyGrayscale();
			void ApplyInvert();
		
	};
}
