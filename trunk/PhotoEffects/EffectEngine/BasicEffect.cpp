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
				nPixelR = bData[1];
				nPixelG = bData[2] - 255;
				nPixelB = bData[3] - 255;
			}
			else if (filter == COLOR_GREEN)
			{
				nPixelR = bData[1] - 255;
				nPixelG = bData[2];
				nPixelB = bData[3] - 255;
			}
			else if (filter == COLOR_BLUE)
			{
				nPixelR = bData[1] - 255;
				nPixelG = bData[2] - 255;
				nPixelB = bData[3];
			}
			nPixelR = max(nPixelR, 0);
			nPixelR = min(255, nPixelR);

			nPixelG = max(nPixelG, 0);
			nPixelG = min(255, nPixelG);

			nPixelB = max(nPixelB, 0);
			nPixelB = min(255, nPixelB);

			bData[1] = nPixelR;
			bData[2] = nPixelG;
			bData[3] = nPixelB;
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
			bData[1] = redGamma[bData[1]];
			bData[2] = greenGamma[bData[2]];
			bData[3] = blueGamma[bData[3]];
			
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
			int cR = bData[1] + brightness;
			int cG = bData[2] + brightness;
			int cB = bData[3] + brightness;

			if (cR < 0) cR = 1;
			if (cR > 255) cR = 255;

			if (cG < 0) cG = 1;
			if (cG > 255) cG = 255;

			if (cB < 0) cB = 1;
			if (cB > 255) cB = 255;

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

			double pR = bData[1] / 255.0;
			pR -= 0.5;
			pR *= contrast;
			pR += 0.5;
			pR *= 255;
			if (pR < 0) pR = 0;
			if (pR > 255) pR = 255;

			double pG = bData[2] / 255.0;
			pG -= 0.5;
			pG *= contrast;
			pG += 0.5;
			pG *= 255;
			if (pG < 0) pG = 0;
			if (pG > 255) pG = 255;

			double pB = bData[3] / 255.0;
			pB -= 0.5;
			pB *= contrast;
			pB += 0.5;
			pB *= 255;
			if (pB < 0) pB = 0;
			if (pB > 255) pB = 255;

			bData[1] = pR;
			bData[2] = pG;
			bData[3] = pB;
			
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
			
			byte gray = (byte)(.299 * bData[1] + .587 * bData[2] + .114 * bData[3]);

			bData[1] = gray;
			bData[2] = gray;
			bData[3] = gray;
			
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
			
			bData[1] = 255 - bData[1];
			bData[2] = 255 - bData[2];
			bData[3] = 255 - bData[3];

			data++;
		}
	}
}
