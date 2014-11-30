// Scribble - okienkowy szkicownik

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>


// nazwa klasy okna
std::string g_strKlasaOkna = "od0dogk_Window";

// dane okna
HDC g_hdcOkno;		// uchwyt kontekstu urz�dzenia okna


// --- procedura zdarzeniowa okna ---

LRESULT CALLBACK WindowEventProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_LBUTTONDOWN:
			// przejmujemy myszk�
			SetCapture (hWnd);

			// przesuwamy pi�ro (s�u��ce do rysowania po oknie) w punkt klikni�cia
			MoveToEx (g_hdcOkno, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), NULL);

			// zwracamy zero
			return 0;

		case WM_MOUSEMOVE:
			// je�eli nasze okno posiada myszk�
			if (GetCapture() == hWnd)
				// rysujemy linie od poprzedniego do aktualnego miejsca kursora myszki
				LineTo (g_hdcOkno, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			
			// zwracamy zero
			return 0;

		case WM_LBUTTONUP:
			// oddajemy w�adz� nad myszk� do systemu
			ReleaseCapture();
			return 0;

		//--------------------------------------------------------------------------------

		case WM_DESTROY:
			// ko�czymy program
			PostQuitMessage (0);
			return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


// --- funkcja WinMain() ---

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	/* rejestrujemy klas� okna */

	WNDCLASSEX KlasaOkna;
	
	// wype�niamy struktur� WNDCLASSEX
	ZeroMemory (&KlasaOkna, sizeof(WNDCLASSEX));
	KlasaOkna.cbSize = sizeof(WNDCLASSEX);
	KlasaOkna.hInstance = hInstance;
	KlasaOkna.lpfnWndProc = WindowEventProc;
	KlasaOkna.lpszClassName = g_strKlasaOkna.c_str();
	KlasaOkna.hCursor = LoadCursor(NULL, IDC_ARROW);
	KlasaOkna.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	KlasaOkna.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);	// bia�e t�o
	KlasaOkna.style = CS_OWNDC;					// w�asny kontekst urz�dzenia okna
	
	// rejestrujemy klas� okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj� CreateWindowEx
	HWND hOkno = NULL;
	hOkno = CreateWindowEx(NULL,					// rozszerzony styl okna
						   g_strKlasaOkna.c_str(),	// klasa okna
						   "Szkicownik",			// tekst na pasku tytu�u
						   WS_OVERLAPPEDWINDOW,		// styl okna
						   CW_USEDEFAULT,			// wsp�rz�dna pozioma
						   CW_USEDEFAULT,			// wsp�rz�dna pionowa
						   CW_USEDEFAULT,			// szeroko��
						   CW_USEDEFAULT,			// wysoko��
						   NULL,					// uchwyt do okna nadrz�dnego
						   NULL,					// uchwyt do menu
						   hInstance,				// uchwyt do instancji aplikacji
						   NULL);					// dodatkowe dane

	// pobieramy uchwyt do kontekstu urz�dzenia obszaru klienta okna
	g_hdcOkno = GetDC(hOkno);
	
	// pokazujemy nasze okno
	ShowWindow (hOkno, nCmdShow);


	/* p�tla komunikat�w */

	MSG msgKomunikat;
	while (GetMessage(&msgKomunikat, NULL, 0, 0))
	{
		TranslateMessage (&msgKomunikat);
		DispatchMessage (&msgKomunikat);
	}

	// zwracamy kod wyj�cia
	return static_cast<int>(msgKomunikat.wParam);
}