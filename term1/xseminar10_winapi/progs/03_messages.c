#include <windows.h>

int WinMain(HINSTANCE h, HINSTANCE hp, LPSTR args, int nshow)
{
    MessageBox(NULL, "One", "Title", MB_YESNOCANCEL);
    MessageBox(NULL, "Two", "Title", MB_YESNO);
    MessageBox(NULL, "Three", "Title", MB_OK);
}
