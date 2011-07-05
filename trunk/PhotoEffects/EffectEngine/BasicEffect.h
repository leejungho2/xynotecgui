#ifndef _BASIC_EFFECT_H__
#define _BASIC_EFFECT_H__

#include "typedef.h"
#include "ConvMatrix.h"

//////////////////////////////////////////////////////////////////////////
// At first, bitmap data is 32bits with format ARGB
//					byte 0 | byte 1 | byte 2 | byte 3
//Windows format	   B	   G	     R	     A	
//////////////////////////////////////////////////////////////////////////
#define INVERT_RED

//class ConvMatrix
//{
//	public:
//		ConvMatrix()
//		{
//			TopLeft = 0;	TopMid = 0;		TopRight = 0;
//			MidLeft = 0;	Pixel = 1;		MidRight = 0;			
//			BottomLeft = 0; BottomMid = 0;	BottomRight = 0;
//			Factor = 1;
//			Offset = 0;
//		}
//
//		int TopLeft, TopMid, TopRight;
//		int MidLeft, Pixel, MidRight;
//		int BottomLeft, BottomMid, BottomRight;
//		int Factor;
//		int Offset;
//
//		void SetAll(int nVal)
//		{
//			TopLeft = TopMid = TopRight = MidLeft = Pixel = MidRight = BottomLeft = BottomMid = BottomRight = nVal;
//		}
//};

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
void AFX_EXT_API Vignette(BMP_ARGB *data, int width, int height);

//////////////////////////////////////////////////////////////////////////
void AFX_EXT_API Conv3x3(BMP_ARGB *data, int width, int height, ConvMatrix* m);
void AFX_EXT_API Smooth(BMP_ARGB *data, int width, int height, int nWeight /* default to 1 */);
void AFX_EXT_API GaussianBlur(BMP_ARGB *data, int width, int height, int nWeight /* default to 4*/);
void AFX_EXT_API MeanRemoval(BMP_ARGB *data, int width, int height, int nWeight /* default to 9*/ );
void AFX_EXT_API Sharpen(BMP_ARGB *data, int width, int height, int nWeight /* default to 11*/ );
void AFX_EXT_API EmbossLaplacian(BMP_ARGB *data, int width, int height);
void AFX_EXT_API EdgeDetectQuick(BMP_ARGB *data, int width, int height);

//////////////////////////////////////////////////////////////////////////
void OffsetFilterAbs(BMP_ARGB *data, int width, int height, IntPoint** offset);
void OffsetFilter(BMP_ARGB *data, int width, int height, IntPoint** offset);
void OffsetFilterAntiAlias(BMP_ARGB *data, int width, int height, FloatPoint** fp);

void AFX_EXT_API Flip(BMP_ARGB *data, int width, int height, bool bHorz, bool bVert);
void AFX_EXT_API RandomJitter(BMP_ARGB *data, int width, int height, short nDegree);
void AFX_EXT_API Swirl(BMP_ARGB *data, int width, int height, double fDegree, bool bSmoothing /* default fDegree to .05 */);
void AFX_EXT_API Sphere(BMP_ARGB *data, int width, int height, bool bSmoothing);
void AFX_EXT_API TimeWarp(BMP_ARGB *data, int width, int height, byte factor, bool bSmoothing);
void AFX_EXT_API Moire(BMP_ARGB *data, int width, int height, double fDegree);
void AFX_EXT_API Water(BMP_ARGB *data, int width, int height, short nWave, bool bSmoothing);
void AFX_EXT_API Pixelate(BMP_ARGB *data, int width, int height, short pixel, bool bGrid);




#endif

