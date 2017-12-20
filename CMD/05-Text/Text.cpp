#include <windows.h>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine , int nCmdShow)
{
	WNDCLASSEX wndclass;
	MSG msg;
	HWND hwnd;
	TCHAR AppName[] = TEXT("Fifth Window");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance,TEXT("IDI_ICON1"));
	wndclass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor = LoadIcon(NULL,IDC_ARROW);
	
	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(AppName,TEXT("Fifth Window"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

	if(hwnd==NULL)
	{
		MessageBox(NULL,TEXT("Window not created"),TEXT("Error..."),0);
	}

	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.lParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	switch(iMsg)
	{
		case WM_LBUTTONDOWN:
			hdc = GetDC(hwnd);
			TextOut(hdc,10,10,TEXT("LBUTTONDOWN"),11);
			ReleaseDC(hwnd,hdc);
			break;
		case WM_DESTROY:
			//PostMessage(hwnd,WM_DESTROY,0,0L);
			PostQuitMessage(0);
			break;
	}
	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}