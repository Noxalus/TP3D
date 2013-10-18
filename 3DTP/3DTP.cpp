#include "stdafx.h"
#include "d3d9.h"
#include "d3dx9.h"
#include "3DTP.h"

// Global Variables:
HINSTANCE hInst;			// current instance
HWND			hWnd;				// windows handle used in DirectX initialization

// Forward declarations
bool				CreateWindows(HINSTANCE, int);
bool				CreateDevice();
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG oMsg;

	if (!CreateWindows (hInstance, nCmdShow))
	{
		MessageBox(NULL, L"Erreur lors de la création de la fenêtre", L"Error", 0);
		return false;
	}
	if (!CreateDevice())
	{
		MessageBox(NULL, L"Erreur lors de la création du device DirectX 9", L"Error", 0);
		return false;
	}

	//Create and fill other DirectX Stuffs like Vertex/Index buffer, shaders 

	PeekMessage( &oMsg, NULL, 0, 0, PM_NOREMOVE );
	while ( oMsg.message != WM_QUIT )
	{
		if (PeekMessage( &oMsg, NULL, 0, 0, PM_REMOVE )) 
		{
			TranslateMessage( &oMsg );
			DispatchMessage( &oMsg );
		}
		else
		{
			// Do a lot of thing like draw triangles with DirectX
		}
	}
	//Release D3D objectssss
	return (int) oMsg.wParam;
}


bool CreateWindows(HINSTANCE hInstance, int nCmdShow)
{
  hInst = hInstance; // Store instance handle in our global variable

	//
	WNDCLASSEX wcex;
	memset(&wcex, 0, sizeof(WNDCLASSEX));
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style					= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc		= WndProc;
	wcex.hInstance			= hInstance;
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszClassName	= L"3DTPClassName";

	if ( RegisterClassEx(&wcex) == 0 )
			return false;

   hWnd = CreateWindow(L"3DTPClassName", L"This course is awesome", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
      return false;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return true;
}

bool CreateDevice()
{
	return true;
}

//
//  PURPOSE:  Processes messages for the main window.
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		break;
	case WM_KEYUP:
		{
			switch(wParam)
      {
          case VK_ESCAPE:
						{
							PostQuitMessage(0);
							break;
						}
			}
			break;
		}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
