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
	wndclass.hIcon = LoadIcon(hInstance,TEXT("ABOUT2"));		//IDC_ICON1   IDI_ICON1
	wndclass.hIconSm = LoadIcon(hInstance,TEXT("ABOUT2"));			//IDC_APPLICATION   IDI_APPLICATION
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
	static int iPaintFlag = 1;
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

				//MessageBox(NULL,TEXT("Window not created KEWDOWN"),TEXT("Error..."),MB_OK);
			/*
			Red 		255,0,0
			Greenen 		0,255,0
			Blue		0,0,255
			Yellow		255,255,0
			Cyan		0,255,255
			Magenta		255,0,255
			White		255,255,255
			Black		0,0,0
			Orange		255,165,0
			Turcoise	64,224,208
			Pink		255,191,203
			Aero		124,185,232		
			Silver		192,192,192
			Lavender Blue 	204 204 255
			Violet		238,130,238
			Navy		0,0,128
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
					case 'G':
					case 'g':
						//MessageBox(hwnd, TEXT("Green KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 2;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'B':
					case 'b':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 3;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'Y':
					case 'y':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 4;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'C':
					case 'c':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 5;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'M':
					case 'm':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 6;
						InvalidateRect(hwnd,NULL, TRUE);
						break;	
					case 'W':
					case 'w':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 7;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'K':
					case 'k':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 8;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'O':
					case 'o':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 9;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'T':
					case 't':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 10;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'P':
					case 'p':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 11;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'A':
					case 'a':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 12;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'S':
					case 's':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 13;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'L':
					case 'l':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 14;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'V':
					case 'v':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 15;
						InvalidateRect(hwnd,NULL, TRUE);
						break;
					case 'N':
					case 'n':
						//MessageBox(hwnd, TEXT("RED KEY"), TEXT("HEY"), MB_OK);
						iPaintFlag = 16;
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
			else if(iPaintFlag == 2)
			{
				hBrush = CreateSolidBrush(RGB(0,255,0));
			}
			else if(iPaintFlag == 3)
			{
				hBrush = CreateSolidBrush(RGB(0,0,255));
			}
			else if(iPaintFlag == 4)
			{
				hBrush = CreateSolidBrush(RGB(255,255,0));
			}
			else if(iPaintFlag == 5)
			{
				hBrush = CreateSolidBrush(RGB(0,255,255));
			}
			else if(iPaintFlag == 6)
			{
				hBrush = CreateSolidBrush(RGB(255,0,255));
			}
			else if(iPaintFlag == 7)
			{
				hBrush = CreateSolidBrush(RGB(255,255,255));
			}
			else if(iPaintFlag == 8)
			{
				hBrush = CreateSolidBrush(RGB(0,0,0));
			}
			else if(iPaintFlag == 9)
			{
				hBrush = CreateSolidBrush(RGB(255,165,0));
			}
			else if(iPaintFlag == 10)
			{
				hBrush = CreateSolidBrush(RGB(64,224,208));
			}
			else if(iPaintFlag == 11)
			{
				hBrush = CreateSolidBrush(RGB(255,191,203));
			}
			else if(iPaintFlag == 12)
			{
				hBrush = CreateSolidBrush(RGB(124,185,232));
			}
			else if(iPaintFlag == 13)
			{
				hBrush = CreateSolidBrush(RGB(192,192,192));
			}
			else if(iPaintFlag == 14)
			{
				hBrush = CreateSolidBrush(RGB(204,204,255));
			}
			else if(iPaintFlag == 15)
			{
				hBrush = CreateSolidBrush(RGB(238,130,238));
			}
			else if(iPaintFlag == 16)
			{
				hBrush = CreateSolidBrush(RGB(0,0,128));
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
