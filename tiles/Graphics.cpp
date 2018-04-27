#include "Graphics.h"

//define constructor/destructor
Graphics::Graphics() {
  factory = NULL;
  renderTarget = NULL;
}

Graphics::~Graphics(){
  if(factory) factory->Release();
  if(renderTarget) renderTarget->Release();
}

//init graphics through window handle
bool Graphics::Init(HWND windowHandle) {
  HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
  if(res != S_OK) return false;

  RECT rect;
  GetClientRect(windowHandle, &rect);

  res = factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(windowHandle, D2D1::SizeU(rect.right, rect.bottom)), &renderTarget);

  if(res != S_OK) return false;
  return true;
}

//clearscreen to specified color
void Graphics::ClearScreen(float r, float g, float b) {
  renderTarget->Clear(D2D1::ColorF(r, g, b));
}

//drawline function
void Graphics::DrawLine(float x1, float y1, float x2, float y2) {
  ID2D1SolidColorBrush* brush;
  renderTarget->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 1.0f), &brush);
  renderTarget->DrawLine(D2D1::Point2F(x1, y1), D2D1::Point2F(x2, y2), brush, 2.0f);

  brush->Release();
}
