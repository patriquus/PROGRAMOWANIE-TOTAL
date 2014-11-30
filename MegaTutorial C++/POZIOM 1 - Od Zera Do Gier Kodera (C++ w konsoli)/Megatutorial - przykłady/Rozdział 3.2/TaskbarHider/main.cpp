// TaskbarHider - program ukrywaj¹cy pasek zadañ

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>


// dane okna
std::string g_strKlasaOkna = "od0dogk_TaskbarHider_Window";
HWND g_hwndOkno = NULL;

// dane o pasku zadañ
HWND g_hwndPasekZadan = NULL;
bool g_bWidocznyPasekZadan;


// --- procedura zdarzeniowa okna ---

LRESULT CALLBACK WindowEventProc(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			// odkrywamy pasek zadañ
			ShowWindow (g_hwndPasekZadan, SW_SHOW);

			// koñczymy program
			PostQuitMessage (0);
			return 0;

		case WM_LBUTTONDOWN:
			// zmieniamy stan widocznoœci na przeciwny
			g_bWidocznyPasekZadan = !g_bWidocznyPasekZadan;

			// pokazujemy/ukrywamy pasek zadañ
			ShowWindow (g_hwndPasekZadan, g_bWidocznyPasekZadan ? SW_SHOW : SW_HIDE);

			// uaktywniamy w³asne okno i ka¿emy je odrysowaæ, by pokaza³a siê informacja
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
			std::string strNapis = "Pasek zadañ jest ";
			strNapis += (g_bWidocznyPasekZadan ? "WIDOCZNY" : "NIEWIDOCZNY");

			// rysujemy napis informuj¹cy
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
    //KlasaOkna.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	
	// rejestrujemy klasê okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj¹ CreateWindowEx
	g_hwndOkno = CreateWindowEx(WS_EX_TOOLWINDOW,
								g_strKlasaOkna.c_str(),
								"Ukrywacz paska zadañ",
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


	/* uzyskujemy okno paska zadañ */

	// wywo³ujemy FindWindow(), by znaleŸæ uchwyt
	g_hwndPasekZadan = FindWindow("Shell_TrayWnd", NULL);

	// pobieramy stan widocznoœci paska (zapewne jest widoczny,
	// ale ostro¿noœæ nie zaszkodzi :D)
	g_bWidocznyPasekZadan = (IsWindowVisible(g_hwndPasekZadan) != FALSE);


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
