#ifndef _BASIC_EFFECT_H__
#define _BASIC_EFFECT_H__

#include "typedef.h"
//////////////////////////////////////////////////////////////////////////
// At first, bitmap data is 32bits with format ARGB
//					byte 0 | byte 1 | byte 2 | byte 3
//Windows format	   B	   G	     R	     A	
//////////////////////////////////////////////////////////////////////////
#define INVERT_RED

class ConvMatrix
{
	public:
		ConvMatrix()
		{
			TopLeft = 0;	TopMid = 0;		TopRight = 0;
			MidLeft = 0;	Pixel = 1;		MidRight = 0;			
			BottomLeft = 0; BottomMid = 0;	BottomRight = 0;
			Factor = 1;
			Offset = 0;
		}

		int TopLeft, TopMid, TopRight;
		int MidLeft, Pixel, MidRight;
		int BottomLeft, BottomMid, BottomRight;
		int Factor;
		int Offset;

		void SetAll(int nVal)
		{
			TopLeft = TopMid = TopRight = MidLeft = Pixel = MidRight = BottomLeft = BottomMid = BottomRight = nVal;
		}
};

byte* CreateGamma(double color);
//////////////////////////////////////////////////////////////////////////
//BMP_ARGB *data:		image data
//int width:			image width
//int height:			image height

//////////////////////////////////////////////////////////////////////////
//COLOR_FILTER filter	color filter
//////////////////////////////////////////////////////////////////////////
void AFX_EXT_API ColorFilter(BMP_ARGB *data, int width, int height, COLOR_FILTER filter);

//////////////////////////////////////////////////////////////////////////
//double red, green, blue:			value 0->1
//////////////////////////////////////////////////////////////////////////
void AFX_EXT_API Gamma(BMP_ARGB *data, int width, int height, double red, double green, double blue);

//////////////////////////////////////////////////////////////////////////
//int brightness					value -255->255
//////////////////////////////////////////////////////////////////////////
void AFX_EXT_API Brightness(BMP_ARGB *data, int width, int height, int brightness);

//////////////////////////////////////////////////////////////////////////
//double contrast					value -100->100
//////////////////////////////////////////////////////////////////////////
void AFX_EXT_API Contrast(BMP_ARGB *data, int width, int height, double contrast);

void AFX_EXT_API Grayscale(BMP_ARGB *data, int width, int height);

void AFX_EXT_API Invert(BMP_ARGB *data, int width, int height);

//////////////////////////////////////////////////////////////////////////
void AFX_EXT_API Conv3x3(BMP_ARGB *data, int width, int height, ConvMatrix* m);
void AFX_EXT_API Smooth(BMP_ARGB *data, int width, int height, int nWeight /* default to 1 */);
void AFX_EXT_API GaussianBlur(BMP_ARGB *data, int width, int height, int nWeight /* default to 4*/);
void AFX_EXT_API MeanRemoval(BMP_ARGB *data, int width, int height, int nWeight /* default to 9*/ );
void AFX_EXT_API Sharpen(BMP_ARGB *data, int width, int height, int nWeight /* default to 11*/ );
void AFX_EXT_API EmbossLaplacian(BMP_ARGB *data, int width, int height);



#endif

