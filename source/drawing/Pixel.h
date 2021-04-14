#ifndef PIXEL
#define PIXEL
#include "Types.h"

class Pixel {
public: 
	Pixel(uchar r, uchar g, uchar b, uchar a);
	Pixel(const Pixel & other);//copy ctor
	Pixel operator=(const Pixel& other);
	vector<uchar> getRgba();
	uchar get(uint index);
	void setRgba(uchar r, uchar g, uchar b, uchar a);
	void setRgba(Pixel & other);

private:
	Pixel();
	uchar r;
	uchar g;
	uchar b;
	uchar a;
};
#endif
