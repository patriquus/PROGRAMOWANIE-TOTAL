// MsgBox - okno komunikatu

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   LPSTR lpszCmdLine,   int nCmdShow)
{
	MessageBox (NULL, "Oto nasz pierwszy program w Windows!", "Komunikat", NULL);
	return 0;
}