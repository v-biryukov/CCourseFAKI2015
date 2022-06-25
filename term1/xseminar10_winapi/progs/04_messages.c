#include <windows.h>

int WinMain(HINSTANCE h, HINSTANCE hp, LPSTR args, int nshow)
{
    MessageBox(NULL, "One", "Title", MB_YESNOCANCEL | MB_ICONQUESTION);
    MessageBox(NULL, "Two", "Title", MB_YESNO | MB_ICONASTERISK);
    MessageBox(NULL, "Three", "Title", MB_OK | MB_ICONERROR);
}
