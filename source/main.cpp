#include <iostream>
#include <fstream>
#include "drawing/DxPainter.h"
#include "drawing/Pixel.h"
#include <Windows.h>
using namespace std;

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxPainter* painter = new DxPainter(hInstance, 100, 100);
	auto result = painter->getCoreWindow();
	//painter->instantiate();
	//painter->draw2d();
	clog << result;
	system("pause");
	return 0;
}
