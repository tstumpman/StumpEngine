#ifndef DX_DRAWING
#define DX_DRAWING

#include "Types.h"
#include "d3d11_2.h"
#include <wrl.h>

class DxPainter {
public:
	DxPainter(HWND hWnd, uint screenW, uint screenH);
	void draw2d(PixelBuffer pixels, uint top, uint left);

	/*
		Get a CoreWindow for your app.
		Get an interface for the Direct3D device and context.
		Create the swap chain to display your rendered image in the CoreWindow.
		Create a render target for drawing and populate it with pixels.
		Present the swap chain!
	*/

	void getD3dDeviceAndContext();
	void createSwapChain(HWND hWnd);
	void createRenderTarget();
	void populateRenderTarget();
	void presentSwapChain();


private:
	DxPainter();

	Canvas* canvas;
	//A device is usually used at the beginning for setup, not often referenced
	//It is a virtual representation of your GPU
	Microsoft::WRL::ComPtr<ID3D11Device>			m_pd3dDevice;
	//A device context is a DeviceAgnostic GPU, it's used every frame.
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_pd3dDeviceContext;
	Microsoft::WRL::ComPtr<IDXGISwapChain>			m_pDXGISwapChain;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>			m_pBackBuffer;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>	m_pRenderTarget;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>			m_pDepthStencil;
	//The view tells the shader pipeline how to interpret the underlying ID3D11Texture2D resource
	//so if you don't supply this view no per-pixel depth testing is performed
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView>	m_pDepthStencilView;
	D3D11_VIEWPORT	m_viewport;
	D3D11_TEXTURE2D_DESC							m_bbDesc;
	D3D_FEATURE_LEVEL m_featureLevel;

protected:
};

#endif
