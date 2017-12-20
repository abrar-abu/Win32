#include <Windows.h>
#define  WM_USER + 12
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMSg,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdCount)
{
	HWND hwnd;
	WNDCLASSEX wndclass;
	MSG msg;
	TCHAR AppName[] = TEXT("USER MESSAGE");
//	ZeroMemory(&wndclass, sizeof(WNDCLASSEX));

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(AppName, TEXT("THIS IS USER MESSAGE"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (NULL == hwnd)
	{
		MessageBox(NULL, TEXT("Window not created "), TEXT("Error..."), 0);
		exit(0);
	}
	ShowWindow(hwnd, iCmdCount);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return ((int)msg.lParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CREATE:
		MessageBox(hwnd, TEXT("THIS IS BODY"), TEXT("THIS IS HRADING"), MB_OK);
		break;
	case WM_DESTROY:
		//PostMessage(hwnd,WM_QUIT,0,0);
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return (DefWindowProc(hwnd,iMsg,wParam,lParam));
}