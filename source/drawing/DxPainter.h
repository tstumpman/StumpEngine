#ifndef DX_DRAWING
#define DX_DRAWING

#include "Types.h"
#include <Windows.h>

class DxPainter {
public:
	DxPainter(HINSTANCE hInstance, uint screenW, uint screenH);
	void draw2d(PixelBuffer pixels, uint top, uint left);

	/*
		Get a CoreWindow for your app.
		Get an interface for the Direct3D device and context.
		Create the swap chain to display your rendered image in the CoreWindow.
		Create a render target for drawing and populate it with pixels.
		Present the swap chain!
	*/

	HRESULT getCoreWindow();
	void getD3dDeviceAndContext();
	void createRenderTarget();
	void populateRenderTarget();
	void presentSwapChain();

	HINSTANCE m_hInstance;
	wstring m_windowClassName;

	static LRESULT CALLBACK StaticWindowProc(
		HWND hWnd,
		UINT uMsg,
		WPARAM wParam,
		LPARAM lParam);
private:

	Canvas* canvas;


protected:
};

#endif
