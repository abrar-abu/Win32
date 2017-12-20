#include <windows.h>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInsatnce,LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("Windows");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0
	wndclass.cbWndExtra = 0;
	wndclass.lpszClassName = AppName;
	wndclass.lpsxMenuName = NULL;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH) GetSockObject(WHITE_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, TEXT("IDI_ICON1"));
	wndclass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassEx(&wndclass);

	hwnd = (AppName,TEXT("Fourth Window"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

	retun((int)msg.lParam)
}

