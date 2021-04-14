#ifndef CANVAS
#define CANVAS
#include "Types.h"

class Canvas {
public:
	const static int MAX_WIDTH = 1920;
	const static int MAX_HEIGHT = 1080;
	int getWidth();
	int getHeight();
	const PixelBuffer getPixelBuffer();
	Canvas(int width, int height);
	~Canvas();
	bool writePixel(int x, int y, Pixel& pixel);
	void placeBuffer(int top, int left, PixelBuffer & other);

private:
	void setHeight(int newHeight);
	void setWidth(int newWidth);
	Canvas();
	int width = 0;
	int height = 0;
	PixelBuffer buffer;



};
#endif
