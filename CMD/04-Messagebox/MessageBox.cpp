#include <windows.h>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInsatnce,LPSTR lpCmdLine, int nCmdShow)
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
	wndclass.hbrBackground = (HBRUSH) GetStockObject(DKGRAY_BRUSH);
	//wndclass.hIcon = LoadIcon(hInstance, TEXT("IDI_ICON1"));
	wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(AppName,TEXT("Fourth Window"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

	if(hwnd == NULL)
	{
		MessageBox(NULL,TEXT("Window is not fumctioning properly"),TEXT("Window"),0);
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
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch(iMsg)
	{
		case WM_CREATE:
			//sprintf();
			MessageBox(hwnd,TEXT("We are in create window case"),TEXT("WM_CREATE"),MB_OK);
			break;
		case WM_MOVE:
			MessageBox(NULL,TEXT("Resource not available\nDo you want to try again?"),TEXT("Account Details"),MB_ICONINFORMATION | MB_ABORTRETRYIGNORE | MB_DEFBUTTON4);
			break;
		case WM_SIZE:
			break;
		case WM_LBUTTONDOWN:
			break;
		case WM_KEYDOWN:
		 	break;
		 case WM_DESTROY:
		 	//PostMessage(hwnd,WM_QUIT,0,0L);
		 	PostQuitMessage(0);
		 	break;
	}
	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}
