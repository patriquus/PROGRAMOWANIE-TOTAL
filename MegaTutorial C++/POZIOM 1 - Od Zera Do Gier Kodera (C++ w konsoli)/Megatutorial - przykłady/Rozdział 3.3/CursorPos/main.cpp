// CursorPos - pokazywanie pozycji kursora w oknie

#include <string>
#include <sstream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>


// nazwa klasy okna
std::string g_strKlasaOkna = "od0dogk_Window";


// --- procedura zdarzeniowa okna ---

LRESULT CALLBACK WindowEventProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_MOUSEMOVE:
		{
			// pobieramy wspó³rzêdne kursora i zapisujemy je jako napis
			std::stringstream Strumien;
			Strumien << "(" << GET_X_LPARAM(lParam) << "; " << GET_Y_LPARAM(lParam) << ")";

			// ustawiamy tytu³ okna na ów napis
			SetWindowText (hWnd, Strumien.str().c_str());
			return 0;
		}

		case WM_DESTROY:
			// koñczymy program
			PostQuitMessage (0);
			return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


// --- funkcja WinMain() ---

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	/* rejestrujemy klasê okna */

	WNDCLASSEX KlasaOkna;
	
	// wype³niamy strukturê WNDCLASSEX
	ZeroMemory (&KlasaOkna, sizeof(WNDCLASSEX));
	KlasaOkna.cbSize = sizeof(WNDCLASSEX);
	KlasaOkna.hInstance = hInstance;
	KlasaOkna.lpfnWndProc = WindowEventProc;
	KlasaOkna.lpszClassName = g_strKlasaOkna.c_str();
	KlasaOkna.hCursor = LoadCursor(NULL, IDC_ARROW);
	KlasaOkna.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	KlasaOkna.hbrBackground = (HBRUSH) COLOR_WINDOW;
	
	// rejestrujemy klasê okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj¹ CreateWindowEx
	HWND hOkno;
	hOkno = CreateWindowEx(NULL,					// rozszerzony styl okna
						   g_strKlasaOkna.c_str(),	// klasa okna
						   NULL,						// tekst na pasku tytu³u
						   WS_OVERLAPPEDWINDOW,		// styl okna
						   CW_USEDEFAULT,			// wspó³rzêdna pozioma
						   CW_USEDEFAULT,			// wspó³rzêdna pionowa
					       CW_USEDEFAULT,			// szerokoœæ
					       CW_USEDEFAULT,			// wysokoœæ
						   NULL,					// uchwyt do okna nadrzêdnego
						   NULL,					// uchwyt do menu
						   hInstance,				// uchwyt do instancji aplikacji
						   NULL);					// dodatkowe dane
	
	// pokazujemy nasze okno
	ShowWindow (hOkno, nCmdShow);
	

	/* pêtla komunikatów */

	MSG msgKomunikat;
	while (GetMessage(&msgKomunikat, NULL, 0, 0))
	{
		TranslateMessage (&msgKomunikat);
		DispatchMessage (&msgKomunikat);
	}

	// zwracamy kod wyjœcia
	return static_cast<int>(msgKomunikat.wParam);
}