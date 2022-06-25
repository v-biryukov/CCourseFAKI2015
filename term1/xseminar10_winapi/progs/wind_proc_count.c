#include <windows.h>
#include <stdio.h>

const char window_class_name[] = "myWindowClass";

int wnd_proc_call_count = 0;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    wnd_proc_call_count += 1;
    printf("WndProc: %i\n", wnd_proc_call_count);
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WinMain(HINSTANCE hinst, HINSTANCE hinstp, LPSTR args, int nshow)
{
    WNDCLASSEX wc;
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hinst;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = window_class_name;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    HWND hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, window_class_name, "The title of my window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 
                               240, 120, NULL, NULL, hinst, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nshow);
    UpdateWindow(hwnd);

    MSG m;
    while(GetMessage(&m, NULL, 0, 0) > 0)
    {
        DispatchMessage(&m);
    }
    return m.wParam;
}