#pragma once

#include <Windows.h>
#include "d2d1.h"

class Graphics {
  //initalize directx rendertarget and factory
  ID2D1Factory* factory;
  ID2D1HwndRenderTarget* renderTarget;
  public:
    Graphics();
    ~Graphics();

    //initalize graphics through window handle
    bool Init(HWND windowHandle);

    //directx draw functions
    void BeginDraw() {renderTarget->BeginDraw();}
    void EndDraw() {renderTarget->EndDraw();}

    //define clearscreen and drawline functions
    void ClearScreen(float r, float g, float b);
    void DrawLine(float x1, float y1, float x2, float y2);

};
