#pragma once

class ConvMatrix
{
public:
	int TopLeft, TopMid, TopRight;
	int MidLeft, Pixel, MidRight;
	int BottomLeft, BottomMid, BottomRight;
	int Factor;
	int Offset;

	ConvMatrix(void);
	~ConvMatrix(void);
	void SetAll(int nVal);

};
