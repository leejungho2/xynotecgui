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
