// Background.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Background.h"
#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("Windows");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, TEXT("IDI_ICON1"));
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(AppName, TEXT("FIRST WINDOW"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (NULL == hwnd)
	{
		MessageBox(NULL, TEXT("Window not created "), TEXT("Error..."), 0);
		exit(0);
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.lParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int i;
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	HBRUSH hBrush;
	static int iPaintFlag = -1;
	switch (iMsg)
	{
	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case 'R':
		case 'r':
			//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
			iPaintFlag = 1;
			InvalidateRect(hwnd,NULL, TRUE);
			break;
		case 'G':
		case 'g':
			//MessageBox(hwnd, TEXT("GREEN KEY"), TEXT("HEY"), MB_OK);
			iPaintFlag = 2;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'B':
		case 'b':
			//MessageBox(hwnd, TEXT("BLUE KEY"), TEXT("HEY"), MB_OK);
			iPaintFlag = 3;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'C':
		case 'c':
			//MessageBox(hwnd, TEXT("CYAN KEY"), TEXT("HEY"), MB_OK);
			iPaintFlag = 4;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'M':
		case 'm':
			//MessageBox(hwnd, TEXT("MAGANTA KEY"), TEXT("HEY"), MB_OK);
			iPaintFlag = 5;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'Y':
		case 'y':
			//MessageBox(hwnd, TEXT("YELLOW KEY"), TEXT("HEY"), MB_OK);
			iPaintFlag = 6;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'K':
		case 'k':
			//MessageBox(hwnd, TEXT("BLACK KEY"), TEXT("HEY"), MB_OK);
			iPaintFlag = 7;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case 'W':
		case 'w':
			//MessageBox(hwnd, TEXT("WHITE KEY"), TEXT("HEY"), MB_OK);
			iPaintFlag = 8;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		default:
			MessageBox(hwnd,TEXT("WRONG KEY"),TEXT("HEY"),MB_OK);
			break;
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rc);
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		if (iPaintFlag == 1)
		{
			hBrush = CreateSolidBrush(RGB(255,0,0));
		}
		else if (iPaintFlag == 2)
		{
			for (i = 125; i < 256; i++)
			{
				hBrush = CreateSolidBrush(RGB(i, 255, 0));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rc, hBrush);
				//DeleteObject(hdc,hBrush);
				//SetBkColor(hdc, RGB(255, 0, 0));
				MessageBox(hwnd, TEXT("BLACK KEY"), TEXT("HEY"), MB_OK);
				EndPaint(hwnd, &ps);
			}
		}
		else if (iPaintFlag == 3)
		{
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
		}
		else if (iPaintFlag == 4)
		{
			hBrush = CreateSolidBrush(RGB(0, 255, 255));
		}
		if (iPaintFlag == 5)
		{
			hBrush = CreateSolidBrush(RGB(255, 0, 255));
		}
		else if (iPaintFlag == 6)
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
		}
		else if (iPaintFlag == 8)
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
		}
		else if (iPaintFlag == 7)
		{
			hBrush = CreateSolidBrush(RGB(0,0,0));
		}
		SelectObject(hdc, hBrush);
		FillRect(hdc, &rc, hBrush);
		//DeleteObject(hdc,hBrush);
		//SetBkColor(hdc, RGB(255, 0, 0));
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}