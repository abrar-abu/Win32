#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("Background");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;					//Mistake is lpClsExtra cbClsExtra
	wndclass.cbWndExtra = 0;
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground =(HBRUSH) GetStockObject(WHITE_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance,TEXT("IDI_ICON1"));		//IDC_ICON1   IDI_ICON1
	wndclass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);			//IDC_APPLICATION   IDI_APPLICATION
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);				

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(AppName,TEXT("Sixth Window"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

	if(hwnd==NULL)
	{
		MessageBox(NULL,TEXT("Window not created"),TEXT("Error..."),0);
		exit(0);
	}

	ShowWindow(hwnd,nCmdShow);					//ShowWindow(hwnd,nCmdShow)
	UpdateWindow(hwnd);

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return ((int)msg.lParam);
}
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam, LPARAM lParam)
{
	int iPaintFlag = 1;
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	HBRUSH hBrush = CreateSolidBrush(RGB(100,100,100));
	switch(iMsg)
	{
		case WM_CREATE:
				MessageBox(NULL,TEXT("Window not created wm created"),TEXT("Error..."),MB_OK);
			break;
		case WM_KEYDOWN:
				MessageBox(NULL,TEXT("Window not created KEWDOWN"),TEXT("Error..."),MB_OK);
			/*
			switch (LOWORD(wParam))
			{
								MessageBox(NULL,TEXT("Window inseide the loword"),TEXT("Error..."),MB_OK);
				case 'R':
				case 'r':
					iPaintFlag = 1;
					InvalidateRect(hwnd,NULL,TRUE);
					break;
			}
			InvalidateRect(hwnd,NULL,TRUE);
			*/
				switch (LOWORD(wParam))
				{
					case 'R':
					case 'r':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 1;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
				}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hwnd,&ps);
			GetClientRect(hwnd,&rc);
			hBrush = CreateSolidBrush(RGB(255,100,125));
			if(iPaintFlag == 1)
			{
				hBrush = CreateSolidBrush(RGB(255,0,0));
			}
			SelectObject(hdc,hBrush);
			FillRect(hdc,&rc,hBrush);
			//DeleteObject(hdc);
			EndPaint(hwnd,&ps);
			break;
		case WM_DESTROY:
			//PostMessage(hwnd,WM_QUIT,0,0L);
			PostQuitMessage(0);
			break;
	}
	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}
