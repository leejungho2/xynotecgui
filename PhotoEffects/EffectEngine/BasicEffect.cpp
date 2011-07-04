#include "StdAfx.h"
#include <math.h>
#include "BasicEffect.h"

byte* CreateGamma(double color)
{
	byte* gammaArray = new byte[256];
	for (int i = 0; i < 256; ++i)
	{
		gammaArray[i] = (byte)min(255,
			(int)((255.0 * pow(i / 255.0, 1.0 / color)) + 0.5));
	}
	return gammaArray;
}

void ColorFilter(BMP_ARGB *data, int width, int height, COLOR_FILTER filter)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			byte* bData = (byte*)data; 			
			
			int nPixelR = 0;
			int nPixelG = 0;
			int nPixelB = 0;
			if (filter == COLOR_RED)
			{
#ifdef INVERT_RED
				nPixelR = bData[2];
				nPixelB = bData[0] - 255;
#else
				nPixelR = bData[0];
				nPixelB = bData[2] - 255;
#endif	

				nPixelG = bData[1] - 255;
				
			}
			else if (filter == COLOR_GREEN)
			{
#ifdef INVERT_RED
				nPixelR = bData[2] - 255;				
				nPixelB = bData[0] - 255;
#else
				nPixelR = bData[0] - 255;				
				nPixelB = bData[2] - 255;
#endif

				nPixelG = bData[1];
			}
			else if (filter == COLOR_BLUE)
			{
#ifdef INVERT_RED
				nPixelR = bData[2] - 255;
				nPixelB = bData[0];
#else
				nPixelR = bData[0] - 255;
				nPixelB = bData[2];
#endif				
				nPixelG = bData[1] - 255;
			}
			nPixelR = max(nPixelR, 0);
			nPixelR = min(255, nPixelR);

			nPixelG = max(nPixelG, 0);
			nPixelG = min(255, nPixelG);

			nPixelB = max(nPixelB, 0);
			nPixelB = min(255, nPixelB);

#ifdef INVERT_RED
			bData[2] = nPixelR;			
			bData[0] = nPixelB;
#else
			bData[0] = nPixelR;			
			bData[2] = nPixelB;
#endif

			bData[1] = nPixelG;

			data++;
		}
	}
}

void Gamma(BMP_ARGB *data, int width, int height, double red, double green, double blue)
{
	byte* redGamma = CreateGamma(red);
	byte* greenGamma = CreateGamma(green);
	byte* blueGamma = CreateGamma(blue);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			byte* bData = (byte*)data; 		
#ifdef INVERT_RED

			bData[0] = redGamma[bData[2]];	
			bData[2] = blueGamma[bData[0]];
#else
			bData[0] = redGamma[bData[0]];	
			bData[2] = blueGamma[bData[2]];
#endif

			bData[1] = greenGamma[bData[1]];
			
			data++;
		}
	}

	if (redGamma)
	{
		delete [] redGamma;
		redGamma = NULL;
	}

	if (greenGamma)
	{
		delete [] greenGamma;
		greenGamma = NULL;
	}

	if (blueGamma)
	{
		delete [] blueGamma;
		blueGamma = NULL;
	}
}

void Brightness(BMP_ARGB *data, int width, int height, int brightness)
{
	if (brightness < -255) brightness = -255;
	if (brightness > 255) brightness = 255;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			byte* bData = (byte*)data; 		

#ifdef INVERT_RED
			int cR = bData[2] + brightness;
			int cB = bData[0] + brightness;
#else
			int cR = bData[0] + brightness;
			int cB = bData[2] + brightness;
#endif
			
			int cG = bData[1] + brightness;

			if (cR < 0) cR = 1;
			if (cR > 255) cR = 255;

			if (cG < 0) cG = 1;
			if (cG > 255) cG = 255;

			if (cB < 0) cB = 1;
			if (cB > 255) cB = 255;

#ifdef INVERT_RED
			bData[2] = cR;
			bData[0] = cB;
#else
			bData[0] = cR;
			bData[2] = cB;
#endif
			bData[1] = cG;

			data++;
		}
	}
}

void Contrast(BMP_ARGB *data, int width, int height, double contrast)
{
	if (contrast < -100) contrast = -100;
	if (contrast > 100) contrast = 100;
	contrast = (100.0 + contrast) / 100.0;
	contrast *= contrast;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			byte* bData = (byte*)data; 		

#ifdef INVERT_RED
			double pR = bData[2] / 255.0;
#else
			double pR = bData[0] / 255.0;
#endif
			pR -= 0.5;
			pR *= contrast;
			pR += 0.5;
			pR *= 255;
			if (pR < 0) pR = 0;
			if (pR > 255) pR = 255;

			double pG = bData[1] / 255.0;
			pG -= 0.5;
			pG *= contrast;
			pG += 0.5;
			pG *= 255;
			if (pG < 0) pG = 0;
			if (pG > 255) pG = 255;

#ifdef INVERT_RED
			double pB = bData[0] / 255.0;
#else
			double pB = bData[2] / 255.0;
#endif
			pB -= 0.5;
			pB *= contrast;
			pB += 0.5;
			pB *= 255;
			if (pB < 0) pB = 0;
			if (pB > 255) pB = 255;

#ifdef INVERT_RED
			bData[2] = pR;			
			bData[0] = pB;
#else
			bData[0] = pR;			
			bData[2] = pB;
#endif

			bData[1] = pG;
			
			data++;
		}
	}
}

void Grayscale(BMP_ARGB *data, int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			byte* bData = (byte*)data; 	

#ifdef INVERT_RED
			byte gray = (byte)(.299 * bData[2] + .587 * bData[1] + .114 * bData[0]);
#else			
			byte gray = (byte)(.299 * bData[0] + .587 * bData[1] + .114 * bData[2]);
#endif

			bData[0] = gray;
			bData[1] = gray;
			bData[2] = gray;
			
			data++;
		}
	}
}

void Invert(BMP_ARGB *data, int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			byte* bData = (byte*)data; 	
			
			bData[0] = 255 - bData[0];
			bData[1] = 255 - bData[1];
			bData[2] = 255 - bData[2];

			data++;
		}
	}
}

void Conv3x3(BMP_ARGB *data, int width, int height, ConvMatrix* m)
{
	// Avoid divide by zero errors
	if (0 == m->Factor) 
		return;

	int nPixel;
	int stride = width * 4;//4 bytes per pixel
	int stride2 = stride * 2;

	BMP_ARGB* cloneData = new BMP_ARGB[width*height];
	memcpy(cloneData, data, width*height*sizeof(BMP_ARGB));

	byte * p = (byte *)data;
	byte* pSrc = (byte*)cloneData; 	
	
	int nWidth = width - 2;
	int nHeight = height - 2;

	for(int y=0;y < nHeight;++y)
	{
		for(int x=0; x < nWidth; ++x )
		{
			/*
			nPixel = ( ( ( (pSrc[2] * m->TopLeft) + (pSrc[5] * m->TopMid) + (pSrc[8] * m->TopRight) +
				(pSrc[2 + stride] * m->MidLeft) + (pSrc[5 + stride] * m->Pixel) + (pSrc[8 + stride] * m->MidRight) +
				(pSrc[2 + stride2] * m->BottomLeft) + (pSrc[5 + stride2] * m->BottomMid) + (pSrc[8 + stride2] * m->BottomRight)) / m->Factor) + m->Offset); 

			if (nPixel < 0) nPixel = 0;
			if (nPixel > 255) nPixel = 255;

			p[5 + stride]= (byte)nPixel;

			nPixel = ( ( ( (pSrc[1] * m->TopLeft) + (pSrc[4] * m->TopMid) + (pSrc[7] * m->TopRight) +
				(pSrc[1 + stride] * m->MidLeft) + (pSrc[4 + stride] * m->Pixel) + (pSrc[7 + stride] * m->MidRight) +
				(pSrc[1 + stride2] * m->BottomLeft) + (pSrc[4 + stride2] * m->BottomMid) + (pSrc[7 + stride2] * m->BottomRight)) / m->Factor) + m->Offset); 

			if (nPixel < 0) nPixel = 0;
			if (nPixel > 255) nPixel = 255;

			p[4 + stride] = (byte)nPixel;

			nPixel = ( ( ( (pSrc[0] * m->TopLeft) + (pSrc[3] * m->TopMid) + (pSrc[6] * m->TopRight) +
				(pSrc[0 + stride] * m->MidLeft) + (pSrc[3 + stride] * m->Pixel) + (pSrc[6 + stride] * m->MidRight) +
				(pSrc[0 + stride2] * m->BottomLeft) + (pSrc[3 + stride2] * m->BottomMid) + (pSrc[6 + stride2] * m->BottomRight)) / m->Factor) + m->Offset); 

			if (nPixel < 0) nPixel = 0;
			if (nPixel > 255) nPixel = 255;

			p[3 + stride] = (byte)nPixel;
			*/

			nPixel = ( ( ( (pSrc[2] * m->TopLeft) + (pSrc[6] * m->TopMid) + (pSrc[10] * m->TopRight) +
				(pSrc[2 + stride] * m->MidLeft) + (pSrc[6 + stride] * m->Pixel) + (pSrc[10 + stride] * m->MidRight) +
				(pSrc[2 + stride2] * m->BottomLeft) + (pSrc[6 + stride2] * m->BottomMid) + (pSrc[10 + stride2] * m->BottomRight)) / m->Factor) + m->Offset); 

			if (nPixel < 0) nPixel = 0;
			if (nPixel > 255) nPixel = 255;

			p[6 + stride]= (byte)nPixel;

			nPixel = ( ( ( (pSrc[1] * m->TopLeft) + (pSrc[5] * m->TopMid) + (pSrc[9] * m->TopRight) +
				(pSrc[1 + stride] * m->MidLeft) + (pSrc[5 + stride] * m->Pixel) + (pSrc[9 + stride] * m->MidRight) +
				(pSrc[1 + stride2] * m->BottomLeft) + (pSrc[5 + stride2] * m->BottomMid) + (pSrc[9 + stride2] * m->BottomRight)) / m->Factor) + m->Offset); 

			if (nPixel < 0) nPixel = 0;
			if (nPixel > 255) nPixel = 255;

			p[5 + stride] = (byte)nPixel;

			nPixel = ( ( ( (pSrc[0] * m->TopLeft) + (pSrc[4] * m->TopMid) + (pSrc[8] * m->TopRight) +
				(pSrc[0 + stride] * m->MidLeft) + (pSrc[4 + stride] * m->Pixel) + (pSrc[8 + stride] * m->MidRight) +
				(pSrc[0 + stride2] * m->BottomLeft) + (pSrc[4 + stride2] * m->BottomMid) + (pSrc[8 + stride2] * m->BottomRight)) / m->Factor) + m->Offset); 

			if (nPixel < 0) nPixel = 0;
			if (nPixel > 255) nPixel = 255;

			p[4 + stride] = (byte)nPixel;

			p += 4;
			pSrc += 4;
		}
	}

	if (cloneData)
	{
		delete[] cloneData;
		cloneData = NULL;
	}
	
}

void Smooth(BMP_ARGB *data, int width, int height, int nWeight /* default to 1 */)
{
	ConvMatrix* m = new ConvMatrix();
	m->SetAll(1);
	m->Pixel = nWeight;
	m->Factor = nWeight + 8;

	Conv3x3(data, width, height, m);

	if (m)
	{
		delete m;
		m = NULL;
	}
}

void GaussianBlur(BMP_ARGB *data, int width, int height, int nWeight /* default to 4*/)
{
	ConvMatrix* m = new ConvMatrix();
	m->SetAll(1);
	m->Pixel = nWeight;
	m->TopMid = m->MidLeft = m->MidRight = m->BottomMid = 2;
	m->Factor = nWeight + 12;

	Conv3x3(data, width, height, m);

	if (m)
	{
		delete m;
		m = NULL;
	}
}

void MeanRemoval(BMP_ARGB *data, int width, int height, int nWeight /* default to 9*/ )
{
	ConvMatrix* m = new ConvMatrix();
	m->SetAll(-1);
	m->Pixel = nWeight;
	m->Factor = nWeight - 8;

	Conv3x3(data, width, height, m);

	if (m)
	{
		delete m;
		m = NULL;
	}
}

void Sharpen(BMP_ARGB *data, int width, int height, int nWeight /* default to 11*/ )
{
	ConvMatrix* m = new ConvMatrix();
	m->SetAll(0);
	m->Pixel = nWeight;
	m->TopMid = m->MidLeft = m->MidRight = m->BottomMid = -2;
	m->Factor = nWeight - 8;

	Conv3x3(data, width, height, m);

	if (m)
	{
		delete m;
		m = NULL;
	}
}

void EmbossLaplacian(BMP_ARGB *data, int width, int height)
{
	ConvMatrix* m = new ConvMatrix();
	m->SetAll(-1);
	m->TopMid = m->MidLeft = m->MidRight = m->BottomMid = 0;
	m->Pixel = 4;
	m->Offset = 127;

	Conv3x3(data, width, height, m);

	if (m)
	{
		delete m;
		m = NULL;
	}
}
void EdgeDetectQuick(BMP_ARGB *data, int width, int height)
{
	ConvMatrix* m = new ConvMatrix();
	m->TopLeft = m->TopMid = m->TopRight = -1;
	m->MidLeft = m->Pixel = m->MidRight = 0;
	m->BottomLeft = m->BottomMid = m->BottomRight = 1;

	m->Offset = 127;

	Conv3x3(data, width, height, m);

	if (m)
	{
		delete m;
		m = NULL;
	}
}
