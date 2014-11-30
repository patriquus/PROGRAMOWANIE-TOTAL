// TaskbarHider - program ukrywaj�cy pasek zada�

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>


// dane okna
std::string g_strKlasaOkna = "od0dogk_TaskbarHider_Window";
HWND g_hwndOkno = NULL;

// dane o pasku zada�
HWND g_hwndPasekZadan = NULL;
bool g_bWidocznyPasekZadan;


// --- procedura zdarzeniowa okna ---

LRESULT CALLBACK WindowEventProc(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			// odkrywamy pasek zada�
			ShowWindow (g_hwndPasekZadan, SW_SHOW);

			// ko�czymy program
			PostQuitMessage (0);
			return 0;

		case WM_LBUTTONDOWN:
			// zmieniamy stan widoczno�ci na przeciwny
			g_bWidocznyPasekZadan = !g_bWidocznyPasekZadan;

			// pokazujemy/ukrywamy pasek zada�
			ShowWindow (g_hwndPasekZadan, g_bWidocznyPasekZadan ? SW_SHOW : SW_HIDE);

			// uaktywniamy w�asne okno i ka�emy je odrysowa�, by pokaza�a si� informacja
			SetFocus (hWindow);
			InvalidateRect (hWindow, NULL, true);

			return 0;

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdcOkno;
			RECT rectObszarKlienta;

			// pobieramy obszar klienta naszego okna
			GetClientRect (hWindow, &rectObszarKlienta);

			// formatujemy napis
			std::string strNapis = "Pasek zada� jest ";
			strNapis += (g_bWidocznyPasekZadan ? "WIDOCZNY" : "NIEWIDOCZNY");

			// rysujemy napis informuj�cy
			hdcOkno = BeginPaint(hWindow, &ps);
			DrawText (hdcOkno, strNapis.c_str(), (int) strNapis.length(),
					  &rectObszarKlienta, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			EndPaint (hWindow, &ps);

			return 0;
		}
	}

	return DefWindowProc(hWindow, uMsg, wParam, lParam);
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
	KlasaOkna.hbrBackground = (HBRUSH) COLOR_WINDOW;
    //KlasaOkna.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	
	// rejestrujemy klas� okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj� CreateWindowEx
	g_hwndOkno = CreateWindowEx(WS_EX_TOOLWINDOW,
								g_strKlasaOkna.c_str(),
								"Ukrywacz paska zada�",
								WS_OVERLAPPED | WS_BORDER | WS_CAPTION | WS_SYSMENU,
								CW_USEDEFAULT,
								CW_USEDEFAULT,
								250,
								50,
								NULL,
								NULL,
								hInstance,
								NULL);
	
	// pokazujemy nasze okno
	ShowWindow (g_hwndOkno, nCmdShow);


	/* uzyskujemy okno paska zada� */

	// wywo�ujemy FindWindow(), by znale�� uchwyt
	g_hwndPasekZadan = FindWindow("Shell_TrayWnd", NULL);

	// pobieramy stan widoczno�ci paska (zapewne jest widoczny,
	// ale ostro�no�� nie zaszkodzi :D)
	g_bWidocznyPasekZadan = (IsWindowVisible(g_hwndPasekZadan) != FALSE);


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
