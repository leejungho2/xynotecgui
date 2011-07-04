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

void OffsetFilterAbs(BMP_ARGB *data, int width, int height, IntPoint** offset)
{		
	int nPixel;
	int stride = width * 4;//4 bytes per pixel
	int scanline = stride;
	
	BMP_ARGB* cloneData = new BMP_ARGB[width*height];
	memcpy(cloneData, data, width*height*sizeof(BMP_ARGB));

	byte * p = (byte *)data;
	byte* pSrc = (byte*)cloneData; 	

	int nWidth = width;
	int nHeight = height;

	int xOffset, yOffset;

	for(int y=0;y < nHeight;++y)
	{
		for(int x=0; x < nWidth; ++x )
		{	
			xOffset = offset[x][y].X;
			yOffset = offset[x][y].Y;

			if (yOffset >= 0 && yOffset < nHeight && xOffset >= 0 && xOffset < nWidth)
			{
				p[0] = pSrc[(yOffset * scanline) + (xOffset * 4)];
				p[1] = pSrc[(yOffset * scanline) + (xOffset * 4) + 1];
				p[2] = pSrc[(yOffset * scanline) + (xOffset * 4) + 2];
			}

			p += 4;
		}
	}

	if (cloneData)
	{
		delete[] cloneData;
		cloneData = NULL;
	}
}

void OffsetFilter(BMP_ARGB *data, int width, int height, IntPoint** offset)
{
	int nPixel;
	int stride = width * 4;//4 bytes per pixel
	int scanline = stride;

	BMP_ARGB* cloneData = new BMP_ARGB[width*height];
	memcpy(cloneData, data, width*height*sizeof(BMP_ARGB));

	byte * p = (byte *)data;
	byte* pSrc = (byte*)cloneData; 	

	int nWidth = width;
	int nHeight = height;

	int xOffset, yOffset;

	for(int y=0;y < nHeight;++y)
	{
		for(int x=0; x < nWidth; ++x )
		{	
			xOffset = offset[x][y].X;
			yOffset = offset[x][y].Y;

			if (y+yOffset >= 0 && y+yOffset < nHeight && x+xOffset >= 0 && x+xOffset < nWidth)
			{
				p[0] = pSrc[((y+yOffset) * scanline) + ((x+xOffset) * 4)];
				p[1] = pSrc[((y+yOffset) * scanline) + ((x+xOffset) * 4) + 1];
				p[2] = pSrc[((y+yOffset) * scanline) + ((x+xOffset) * 4) + 2];
			}

			p += 4;
		}
	}

	if (cloneData)
	{
		delete[] cloneData;
		cloneData = NULL;
	}
}

void OffsetFilterAntiAlias(BMP_ARGB *data, int width, int height, FloatPoint** fp)
{
	int nPixel;
	int stride = width * 4;//4 bytes per pixel
	int scanline = stride;

	BMP_ARGB* cloneData = new BMP_ARGB[width*height];
	memcpy(cloneData, data, width*height*sizeof(BMP_ARGB));

	byte * p = (byte *)data;
	byte* pSrc = (byte*)cloneData; 	

	int nWidth = width;
	int nHeight = height;

	double xOffset, yOffset;

	double fraction_x, fraction_y, one_minus_x, one_minus_y;
	int ceil_x, ceil_y, floor_x, floor_y;
	byte p1, p2;

	for(int y=0;y < nHeight;++y)
	{
		for(int x=0; x < nWidth; ++x )
		{	
			xOffset = fp[x][y].X;
			yOffset = fp[x][y].Y;

			// Setup

			floor_x = (int)floor(xOffset);
			floor_y = (int)floor(yOffset);
			ceil_x = floor_x + 1;
			ceil_y = floor_y + 1;
			fraction_x = xOffset - floor_x;
			fraction_y = yOffset - floor_y;
			one_minus_x = 1.0 - fraction_x;
			one_minus_y = 1.0 - fraction_y;

			if (floor_y >= 0 && ceil_y < nHeight && floor_x >= 0 && ceil_x < nWidth)
			{
				// Blue

				p1 = (byte)(one_minus_x * (double)(pSrc[floor_y * scanline + floor_x * 4]) +
					fraction_x * (double)(pSrc[floor_y * scanline + ceil_x * 4]));

				p2 = (byte)(one_minus_x * (double)(pSrc[ceil_y * scanline + floor_x * 4]) +
					fraction_x * (double)(pSrc[ceil_y * scanline + 4 * ceil_x]));

				p[x * 4 + y*scanline] = (byte)(one_minus_y * (double)(p1) + fraction_y * (double)(p2));

				// Green

				p1 = (byte)(one_minus_x * (double)(pSrc[floor_y * scanline + floor_x * 4 + 1]) +
					fraction_x * (double)(pSrc[floor_y * scanline + ceil_x * 4 + 1]));

				p2 = (byte)(one_minus_x * (double)(pSrc[ceil_y * scanline + floor_x * 4 + 1]) +
					fraction_x * (double)(pSrc[ceil_y * scanline + 4 * ceil_x + 1]));

				p[x * 4 + y*scanline + 1] = (byte)(one_minus_y * (double)(p1) + fraction_y * (double)(p2));

				// Red

				p1 = (byte)(one_minus_x * (double)(pSrc[floor_y * scanline + floor_x * 4 + 2]) +
					fraction_x * (double)(pSrc[floor_y * scanline + ceil_x * 4 + 2]));

				p2 = (byte)(one_minus_x * (double)(pSrc[ceil_y * scanline + floor_x * 4 + 2]) +
					fraction_x * (double)(pSrc[ceil_y * scanline + 4 * ceil_x + 2]));

				p[x * 4 + y*scanline + 2] = (byte)(one_minus_y * (double)(p1) + fraction_y * (double)(p2));
			}
		}
	}
	
	if (cloneData)
	{
		delete[] cloneData;
		cloneData = NULL;
	}

}

void Flip(BMP_ARGB *data, int width, int height, bool bHorz, bool bVert)
{
	IntPoint** ptFlip = new IntPoint*[width]; 

	for(int i = 0; i < width; i++)
		ptFlip[i] = new IntPoint[height];

	int nWidth = width;
	int nHeight = height;

	for (int x = 0; x < nWidth; ++x)
		for (int y = 0; y < nHeight; ++y)
		{
			ptFlip[x][y].X = (bHorz) ? nWidth - (x+1) : x;
			ptFlip[x][y].Y = (bVert) ? nHeight - (y + 1) : y;
		}

	OffsetFilterAbs(data, width, height, ptFlip);		

	for(int i = 0; i < width; i++)
		delete[] ptFlip[i];
	delete[] ptFlip;
}

void RandomJitter(BMP_ARGB *data, int width, int height, short nDegree)
{
	IntPoint** ptRandJitter = new IntPoint*[width]; 

	for(int i = 0; i < width; i++)
		ptRandJitter[i] = new IntPoint[height];

	int nWidth = width;
	int nHeight = height;

	int newX, newY;

	short nHalf = (short)floor((double)nDegree/2);

	srand(time(NULL));  

	for (int x = 0; x < nWidth; ++x)
		for (int y = 0; y < nHeight; ++y)
		{
			newX = rand()%nDegree - nHalf;

			if (x + newX > 0 && x + newX < nWidth)
				ptRandJitter[x][y].X = newX;
			else
				ptRandJitter[x][y].X = 0;

			newY = rand()%nDegree - nHalf;

			if (y + newY > 0 && y + newY < nWidth)
				ptRandJitter[x][y].Y = newY;
			else
				ptRandJitter[x][y].Y = 0;
		}

	OffsetFilter(data, width, height, ptRandJitter);	

	for(int i = 0; i < width; i++)
		delete[] ptRandJitter[i];
	delete[] ptRandJitter;
}

void Swirl(BMP_ARGB *data, int width, int height, double fDegree, bool bSmoothing /* default fDegree to .05 */)
{
	int nWidth = width;
	int nHeight = height;

	FloatPoint** fp = new FloatPoint*[nWidth];
	IntPoint** pt = new IntPoint*[nWidth];

	for(int i = 0; i < nWidth; i++)
	{
		fp[i] = new FloatPoint[height];
		pt[i] = new IntPoint[height];
	}

	IntPoint mid;
	mid.X = nWidth/2;
	mid.Y = nHeight/2;

	double theta, radius;
	double newX, newY;

	for (int x = 0; x < nWidth; ++x)
		for (int y = 0; y < nHeight; ++y)
		{
			int trueX = x - mid.X;
			int trueY = y - mid.Y;
			theta = atan2((double)trueY,(double)trueX);

			radius = sqrt((double)(trueX*trueX + trueY*trueY));

			newX = mid.X + (radius * cos(theta + fDegree * radius));
			if (newX > 0 && newX < nWidth)
			{
				fp[x][y].X = newX;
				pt[x][y].X = (int)newX;
			}
			else
				fp[x][y].X = pt[x][y].X = x;

			newY = mid.Y + (radius * sin(theta + fDegree * radius));
			if (newY > 0 && newY < nHeight)
			{
				fp[x][y].Y = newY;
				pt[x][y].Y = (int)newY;
			}
			else
				fp[x][y].Y = pt[x][y].Y = y;
		}

	if(bSmoothing)
		OffsetFilterAntiAlias(data, width, height, fp);
	else
		OffsetFilterAbs(data, width, height, pt);		

	for(int i = 0; i < nWidth; i++)
	{
		delete[] fp[i];
		delete[] pt[i];
	}
	delete[] fp;
	delete[] pt;

}

void Sphere(BMP_ARGB *data, int width, int height, bool bSmoothing)
{
	int nWidth = width;
	int nHeight = height;

	FloatPoint** fp = new FloatPoint*[nWidth];
	IntPoint** pt = new IntPoint*[nWidth];

	for(int i = 0; i < nWidth; i++)
	{
		fp[i] = new FloatPoint[height];
		pt[i] = new IntPoint[height];
	}

	IntPoint mid;
	mid.X = nWidth/2;
	mid.Y = nHeight/2;

	double theta, radius;
	double newX, newY;

	for (int x = 0; x < nWidth; ++x)
		for (int y = 0; y < nHeight; ++y)
		{
			int trueX = x - mid.X;
			int trueY = y - mid.Y;
			theta = atan2((double)trueY, (double)trueX);

			radius = sqrt((double)(trueX*trueX + trueY*trueY));

			double newRadius = radius * radius/(max(mid.X, mid.Y));

			newX = mid.X + (newRadius * cos(theta));

			if (newX > 0 && newX < nWidth)
			{
				fp[x][y].X = newX;
				pt[x][y].X = (int) newX;
			}
			else
			{
				fp[x][y].X = fp[x][y].Y = 0.0;
				pt[x][y].X = pt[x][y].Y = 0;
			}

			newY = mid.Y + (newRadius * sin(theta));

			if (newY > 0 && newY < nHeight && newX > 0 && newX < nWidth)
			{
				fp[x][y].Y = newY;
				pt[x][y].Y = (int) newY;
			}
			else
			{
				fp[x][y].X = fp[x][y].Y = 0.0;
				pt[x][y].X = pt[x][y].Y = 0;
			}
		}

	if(bSmoothing)
		OffsetFilterAbs(data, width, height, pt);
	else
		OffsetFilterAntiAlias(data, width, height, fp);

	for(int i = 0; i < nWidth; i++)
	{
		delete[] fp[i];
		delete[] pt[i];
	}
	delete[] fp;
	delete[] pt;

}

void TimeWarp(BMP_ARGB *data, int width, int height, byte factor, bool bSmoothing)
{
	int nWidth = width;
	int nHeight = height;

	FloatPoint** fp = new FloatPoint*[nWidth];
	IntPoint** pt = new IntPoint*[nWidth];

	for(int i = 0; i < nWidth; i++)
	{
		fp[i] = new FloatPoint[height];
		pt[i] = new IntPoint[height];
	}

	IntPoint mid;
	mid.X = nWidth/2;
	mid.Y = nHeight/2;

	double theta, radius;
	double newX, newY;

	for (int x = 0; x < nWidth; ++x)
		for (int y = 0; y < nHeight; ++y)
		{
			int trueX = x - mid.X;
			int trueY = y - mid.Y;
			theta = atan2((double)trueY, (double)trueX);

			radius = sqrt((double)(trueX*trueX + trueY*trueY));

			double newRadius = sqrt(radius) * factor;

			newX = mid.X + (newRadius * cos(theta));
			if (newX > 0 && newX < nWidth)
			{
				fp[x][y].X = newX;
				pt[x][y].X = (int) newX;
			}
			else
			{
				fp[x][y].X = 0.0;
				pt[x][y].X = 0;
			}

			newY = mid.Y + (newRadius * sin(theta));
			if (newY > 0 && newY < nHeight)
			{
				fp[x][y].Y = newY;
				pt[x][y].Y = (int) newY;
			}
			else
			{
				fp[x][y].Y = 0.0;
				pt[x][y].Y = 0;
			}
		}

	if(bSmoothing)
		OffsetFilterAbs(data, width, height, pt);
	else
		OffsetFilterAntiAlias(data, width, height, fp);	

	for(int i = 0; i < nWidth; i++)
	{
		delete[] fp[i];
		delete[] pt[i];
	}
	delete[] fp;
	delete[] pt;
}

void Moire(BMP_ARGB *data, int width, int height, double fDegree)
{
	int nWidth = width;
	int nHeight = height;

	FloatPoint** fp = new FloatPoint*[nWidth];
	IntPoint** pt = new IntPoint*[nWidth];

	for(int i = 0; i < nWidth; i++)
	{
		fp[i] = new FloatPoint[height];
		pt[i] = new IntPoint[height];
	}

	IntPoint mid;
	mid.X = nWidth/2;
	mid.Y = nHeight/2;

	double theta, radius;
	int newX, newY;

	for (int x = 0; x < nWidth; ++x)
		for (int y = 0; y < nHeight; ++y)
		{
			int trueX = x - mid.X;
			int trueY = y - mid.Y;
			theta = atan2((double)trueX, (double)trueY);

			radius = sqrt((double)(trueX*trueX + trueY*trueY));

			newX = (int)(radius * sin(theta + fDegree * radius));
			if (newX > 0 && newX < nWidth)
			{
				pt[x][y].X = (int) newX;
			}
			else
			{
				pt[x][y].X = 0;
			}

			newY = (int)(radius * sin(theta + fDegree * radius));
			if (newY > 0 && newY < nHeight)
			{
				pt[x][y].Y = (int) newY;
			}
			else
			{
				pt[x][y].Y = 0;
			}
		}

	OffsetFilterAbs(data, width, height, pt);
	
	for(int i = 0; i < nWidth; i++)
	{
		delete[] fp[i];
		delete[] pt[i];
	}
	delete[] fp;
	delete[] pt;
}

void Water(BMP_ARGB *data, int width, int height, short nWave, bool bSmoothing)
{
	int nWidth = width;
	int nHeight = height;

	FloatPoint** fp = new FloatPoint*[nWidth];
	IntPoint** pt = new IntPoint*[nWidth];

	for(int i = 0; i < nWidth; i++)
	{
		fp[i] = new FloatPoint[height];
		pt[i] = new IntPoint[height];
	}

	IntPoint mid;
	mid.X = nWidth/2;
	mid.Y = nHeight/2;

	double newX, newY;
	double xo, yo;

	for (int x = 0; x < nWidth; ++x)
		for (int y = 0; y < nHeight; ++y)
		{
			xo = ((double)nWave * sin(2.0 * 3.1415 * (float)y / 128.0));
			yo = ((double)nWave * cos(2.0 * 3.1415 * (float)x / 128.0));

			newX = (x + xo);
			newY = (y + yo);

			if (newX > 0 && newX < nWidth)
			{
				fp[x][y].X = newX;
				pt[x][y].X = (int) newX;
			}
			else
			{
				fp[x][y].X = 0.0;
				pt[x][y].X = 0;
			}


			if (newY > 0 && newY < nHeight)
			{
				fp[x][y].Y = newY;
				pt[x][y].Y = (int) newY;
			}
			else
			{
				fp[x][y].Y = 0.0;
				pt[x][y].Y = 0;
			}
		}

	if(bSmoothing)
		OffsetFilterAbs(data, width, height, pt);
	else
		OffsetFilterAntiAlias(data, width, height, fp);

	for(int i = 0; i < nWidth; i++)
	{
		delete[] fp[i];
		delete[] pt[i];
	}
	delete[] fp;
	delete[] pt;
}

void Pixelate(BMP_ARGB *data, int width, int height, short pixel, bool bGrid)
{
	int nWidth = width;
	int nHeight = height;

	IntPoint** pt = new IntPoint*[nWidth];

	for(int i = 0; i < nWidth; i++)
		pt[i] = new IntPoint[height];

	int newX, newY;

	for (int x = 0; x < nWidth; ++x)
		for (int y = 0; y < nHeight; ++y)
		{
			newX = pixel - x%pixel;

			if (bGrid && newX == pixel)
				pt[x][y].X = -x;
			else if (x + newX > 0 && x +newX < nWidth)
				pt[x][y].X = newX;
			else
				pt[x][y].X = 0;

			newY = pixel - y%pixel;

			if (bGrid && newY == pixel)
				pt[x][y].Y = -y;
			else if (y + newY > 0 && y + newY < nHeight)
				pt[x][y].Y = newY;
			else
				pt[x][y].Y = 0;
		}

	OffsetFilter(data, width, height, pt);

	for(int i = 0; i < nWidth; i++)
		delete[] pt[i];
	delete[] pt;
}