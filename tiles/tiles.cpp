#include <Windows.h>
#include <math.h>
#include "Graphics.h"
#define PI 3.14159265

//Define global variables for the initalization of the program
Graphics* graphics;
int t[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int size = 0;
int n = 0;
double angle = 0;
bool keydown = false;
bool test = false;

//Callback function for messages on windows
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  //keyboard input
  if (uMsg == WM_KEYDOWN && !keydown) {
    if (wParam == '1' && 1 + size <= 14) {
      t[size] = 1;
      size++;
    } else if (wParam == '2' && 2 + size <= 14) {
      t[size] = 2;
      size+=2;
    } else if (wParam == '3' && 3 + size <= 14) {
      t[size] = 3;
      size+=3;
    } else if (wParam == '4' && 4 + size <= 14) {
      t[size] = 4;
      size+=4;
    } else if (wParam == '5' && 5 + size <= 14) {
      t[size] = 5;
      size+=5;
    } else if (wParam == '6' && 6 + size <= 14) {
      t[size] = 6;
      size+=6;
    } else if (wParam == ' ') {
      for (int i = 0; i < 14; i++) {
        t[i] = 0;
      }
      size = 0;
    }
    keydown = true;
  } else {
    //infinite key pressed lock protection
    keydown = false;
  }
  //end program if closed by user
  if (uMsg == WM_DESTROY) {PostQuitMessage(0);return 0;}
  //update screen to match user specifications
  if (uMsg == WM_PAINT) {
    graphics->BeginDraw();

    graphics->ClearScreen(0.0f, 0.0f, 0.0f);
    angle = 0;
    n = 0;
    //for all tile values stored in the global array t, draw the tile
    for (int i = 0; i < 14; i++) {
      n+=t[i];
      if (t[i] != 0 && angle < 360 && n <= 14) {
        graphics->DrawLine(300, 300, 300+150*sin(angle * PI / 180.0), 300-150*cos(angle * PI / 180.0));
        graphics->DrawLine(300+150*sin(angle * PI / 180.0), 300-150*cos(angle * PI / 180.0), 300+150*sin(angle * PI / 180.0) + 150*sin((angle + t[i] * (360.0/14.0)) * PI / 180.0), 300-150*cos(angle * PI / 180.0) - 150*cos((angle + t[i] * (360.0/14.0)) * PI / 180.0));
        angle += t[i] * (360.0/14.0);
        graphics->DrawLine(300, 300, 300+150*sin(angle * PI / 180.0), 300-150*cos(angle * PI / 180.0));
        graphics->DrawLine(300+150*sin(angle * PI / 180.0), 300-150*cos(angle * PI / 180.0), 300+150*sin(angle * PI / 180.0) + 150*sin((angle - t[i] * (360.0/14.0)) * PI / 180.0), 300-150*cos(angle * PI / 180.0) - 150*cos((angle - t[i] * (360.0/14.0)) * PI / 180.0));
      }
    }
    graphics->EndDraw();
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

//entry point function for windows
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, int nCmdShow) {
  //definition of windows class
  WNDCLASSEX windowclass;
  ZeroMemory(&windowclass, sizeof(WNDCLASSEX));
  windowclass.cbSize = sizeof(WNDCLASSEX);
  windowclass.hbrBackground = (HBRUSH) COLOR_WINDOW;
  windowclass.hInstance = hInstance;
  windowclass.lpfnWndProc = WindowProc;
  windowclass.lpszClassName = "MainWindow";
  windowclass.style = CS_HREDRAW | CS_VREDRAW;

  RegisterClassEx(&windowclass);

  //define window size
  RECT rect = {0,0,600,600};
  AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

  //initalize window handle and check if it was created properly
  HWND windowhandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MainWindow", "Tiles", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, 0, 0, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);
  if(!windowhandle) {return -1;}

  //initalize graphics
  graphics = new Graphics();

  if(!graphics->Init(windowhandle))  {
    delete graphics;
    return -1;
  }

  //show window to user
  ShowWindow(windowhandle, nCmdShow);

  //begin message loop
  MSG message;
  while (GetMessage(&message, NULL, 0, 0)) {
    DispatchMessage(&message);
    WindowProc(windowhandle, WM_PAINT, 0, 0);
  }

  //clear graphics function and end program
  delete graphics;
  return 0;
}
