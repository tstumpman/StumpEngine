#include "Pixel.h"

Pixel::Pixel(uchar r, uchar g, uchar b, uchar a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Pixel::Pixel(const Pixel& other)
{
	Pixel(other.r, other.g, other.b, other.a);
}

Pixel Pixel::operator=(const Pixel& other)
{
	return Pixel(other.r, other.g, other.b, other.a);
}

vector<uchar> Pixel::getRgba()
{
	return { r, g, b, a };
}

uchar Pixel::get(uint index)
{
	vector<uchar> rgba = getRgba();
	if (index < rgba.size()) {
		return rgba[index];
	}
	return 0;
}

void Pixel::setRgba(uchar r, uchar g, uchar b, uchar a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void Pixel::setRgba(Pixel& other)
{
	this->r = other.get(0);
	this->g = other.get(1);
	this->b = other.get(2);
	this->a = other.get(3);
}



