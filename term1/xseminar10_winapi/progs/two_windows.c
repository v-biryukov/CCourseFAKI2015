#include <windows.h>
#include <stdio.h>

const char window_class_name[] = "myWindowClass";

int wnd_proc_call_count = 0;

LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
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
            return DefWindowProc(hwnd, msg, wp, lp);
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

    RegisterClassEx(&wc);

    HWND hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, window_class_name, "Window One", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 
                               600, 400, NULL, NULL, hinst, NULL);

    ShowWindow(hwnd, nshow);
    UpdateWindow(hwnd);

    HWND hwnd2 = CreateWindowEx(WS_EX_CLIENTEDGE, window_class_name, "Window Two", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 
                               600, 400, NULL, NULL, hinst, NULL);

    ShowWindow(hwnd2, nshow);
    UpdateWindow(hwnd2);

    MSG m;
    while(GetMessage(&m, NULL, 0, 0) > 0)
        DispatchMessage(&m);

    while(GetMessage(&m, NULL, 0, 0) > 0)
        DispatchMessage(&m);

    return m.wParam;
}