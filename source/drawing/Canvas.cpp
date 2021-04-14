#include "Canvas.h"
#include "Pixel.h"
int Canvas::getWidth()
{
	return width;
}

int Canvas::getHeight()
{
	return height;
}

void Canvas::setWidth(int newWidth)
{
	width = min(newWidth, MAX_WIDTH);
}

void Canvas::setHeight(int newHeight)
{
	height = min(newHeight, MAX_HEIGHT);
}

const PixelBuffer Canvas::getPixelBuffer()
{
	return buffer;
}

Canvas::Canvas(int width, int height)
{
	height = height;
	width = width;
	PixelBuffer v = PixelBuffer();

	v.resize(width);
	for (int i = 0; i < width; i++) {
		v[i].resize(height);
		for (int j = 0; j < height; j++) {
			v[i][j] = new Pixel(0, 0, 0, 0);
		}
	}
}

Canvas::~Canvas()
{
	for (int i = 0; i < buffer.size(); i++) {
		for (int j = 0; j < buffer[i].size(); j++) {
			delete buffer[i][j];
		}
	}
}

bool Canvas::writePixel(int x, int y, Pixel& pixel)
{
	if (x >= buffer.size() || y >= buffer[0].size()) {
		return false;
	}

	buffer[x][y]->setRgba(pixel);

	return true;
}

void Canvas::placeBuffer(int top, int left, PixelBuffer& other)
{
	int width = other.size();
	int height = other[0].size();

	if (top >= getHeight() || left >= getWidth()) {
		return;
	}

	int copyHeight = min(height, getHeight() - top);
	int copyWidth = min(width, getWidth() - left);

	for (int x = 0; x < copyWidth; x++) {
		memcpy(buffer[x].data() + left, other[x].data(), copyWidth);
	}
}
