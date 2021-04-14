#include "DxPainter.h";
#include <stdio.h>
#include <string.h>
#include <Windows.h>

#include "Canvas.h"
DxPainter::DxPainter(HINSTANCE hInstance, uint screenW, uint screenH) {
	m_hInstance = hInstance;
	canvas = new Canvas(screenW, screenH);
	m_windowClassName = L"Stump Engine Window Class Name";
}

LRESULT CALLBACK MainWndProc(
	HWND hwnd,        // handle to window
	UINT uMsg,        // message identifier
	WPARAM wParam,    // first message parameter
	LPARAM lParam)    // second message parameter
{

	switch (uMsg)
	{
	case WM_CREATE:
		// Initialize the window. 
		return 0;

	case WM_PAINT:
		// Paint the window's client area. 
		return 0;

	case WM_SIZE:
		// Set the size and position of the window. 
		return 0;

	case WM_DESTROY:
		// Clean up window-specific data objects. 
		return 0;

		// 
		// Process other messages. 
		// 

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}

void DxPainter::draw2d(
	PixelBuffer pixels,
	uint top,
	uint left) {
	canvas->placeBuffer(top, left, pixels);

}

LRESULT CALLBACK DxPainter::StaticWindowProc(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_CLOSE:
	{
		HMENU hMenu;
		hMenu = GetMenu(hWnd);
		if (hMenu != NULL)
		{
			DestroyMenu(hMenu);
		}
		DestroyWindow(hWnd);
		//UnregisterClass(
		//	m_windowClassName.c_str(),
		//	m_hInstance
		//);
		return 0;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

HRESULT DxPainter::getCoreWindow()
{
	if (DxPainter::m_hInstance == NULL)
		DxPainter::m_hInstance = (HINSTANCE)GetModuleHandle(NULL);

	HICON hIcon = NULL;
	WCHAR szExePath[MAX_PATH];
	GetModuleFileName(NULL, szExePath, MAX_PATH);

	// If the icon is NULL, then use the first one found in the exe
	if (hIcon == NULL)
		hIcon = ExtractIcon(DxPainter::m_hInstance, szExePath, 0);

	// Register the windows class
	WNDCLASS wndClass;
	wndClass.style = CS_DBLCLKS;
	wndClass.lpfnWndProc = DxPainter::StaticWindowProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = DxPainter::m_hInstance;
	wndClass.hIcon = hIcon;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = m_windowClassName.c_str();

	if (!RegisterClass(&wndClass))
	{
		DWORD dwError = GetLastError();
		if (dwError != ERROR_CLASS_ALREADY_EXISTS) {
			return HRESULT_FROM_WIN32(dwError);
		}
	}
	return HRESULT(HRESULT_FROM_WIN32(0));
}

void DxPainter::getD3dDeviceAndContext()
{
}

void DxPainter::createRenderTarget()
{
}

void DxPainter::populateRenderTarget()
{
}

void DxPainter::presentSwapChain()
{
}
