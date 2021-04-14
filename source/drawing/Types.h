#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <string>
using namespace std;
class Pixel;
class Canvas;
typedef vector<vector<Pixel*>> PixelBuffer;
typedef unsigned char uchar;
typedef unsigned int uint;
typedef basic_string<wchar_t> wstring;//basically a unicode string.  Two bytes per wchar.

#endif