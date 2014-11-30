// ColorPicker - pobieracz kolorów

#include <string>
#include <sstream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>


// dane okna
std::string g_strKlasaOkna = "od0dogk_ColorPicker_Window";
HWND g_hwndOkno = NULL;

// uchwyt do kontekstu ekranu
HDC g_hdcEkran = NULL;

// pobrany kolor
COLORREF g_clKolor = RGB(255, 255, 255);	// pocz¹tkowo bia³y


// --- procedura zdarzeniowa okna ---

LRESULT CALLBACK WindowEventProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_LBUTTONDOWN:
			// ³apiemy myszkê
			SetCapture (hWnd);

			// ustawiamy kursor w kszta³cie celownika
			SetCursor (LoadCursor(NULL, IDC_CROSS));
			return 0;

		case WM_MOUSEMOVE:
			// sprawdzamy, czy myszka jest z³apana
			if (GetCapture() == hWnd)
			{
				// odczytujemy wspó³rzêdne kursora
				POINT ptKursor;
				ptKursor.x = GET_X_LPARAM(lParam);
				ptKursor.y = GET_Y_LPARAM(lParam);

				// przeliczamy je na koordynaty ekranowe
				ClientToScreen (hWnd, &ptKursor);

				// pobieramy kolor z miejsca, gdzie jest kursor myszy
				g_clKolor = GetPixel(g_hdcEkran, ptKursor.x, ptKursor.y);

				// wymuszamy odœwie¿enie okna programu, aby pokazaæ pobrany kolor
				InvalidateRect (hWnd, NULL, TRUE);
			}
			return 0;

		case WM_LBUTTONUP:
			// uwalniamy mysz
			ReleaseCapture();

			// ustawiamy kursor strza³ki
			SetCursor (LoadCursor(NULL, IDC_ARROW));
			return 0;

		case WM_PAINT:
		{
			// odrysowanie zawartoœci okna
			{
				PAINTSTRUCT ps;
				HDC hdcOkno;

				// zaczynamy
				hdcOkno = BeginPaint(hWnd, &ps);

				// pobieramy obszar klienta okna
				RECT rcObszarKlienta;
				GetClientRect (hWnd, &rcObszarKlienta);

				// wype³niamy go pobranym kolorem
				// w tym celu najpierw tworzymy odpowiedni pêdzel,
				// a potem wype³niamy prostok¹t obszaru klienta
				// potem usuwamy pêdzel
				HBRUSH hbrPedzel = CreateSolidBrush(g_clKolor);
				FillRect (hdcOkno, &rcObszarKlienta, hbrPedzel);
				DeleteObject (hbrPedzel);

				// koñczymy rysowanie
				EndPaint (hWnd, &ps);
			}

			// pokazanie sk³adowych RGB koloru
			{
				// pobieramy te sk³adowe i konwertujemy na napis
				std::stringstream Strumien;
				Strumien << "RGB: " << (int) GetRValue(g_clKolor) << ", "
									<< (int) GetGValue(g_clKolor) << ", "
									<< (int) GetBValue(g_clKolor);

				// ustawiamy ten napis jako tytu³ okna programu
				SetWindowText (hWnd, Strumien.str().c_str());
			}

			return 0;
		}

		case WM_DESTROY:
			// zwalniamy kontekst ekranu
			ReleaseDC (NULL, g_hdcEkran);

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
	
	// rejestrujemy klasê okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj¹ CreateWindowEx
	g_hwndOkno = CreateWindowEx(WS_EX_TOOLWINDOW,
								g_strKlasaOkna.c_str(),
								NULL,
								WS_OVERLAPPED | WS_BORDER | WS_CAPTION | WS_SYSMENU,
								0, 0,
								125,
								80,
								NULL,
								NULL,
								hInstance,
								NULL);
	
	// pokazujemy nasze okno i je od razu odœwie¿amy
	ShowWindow (g_hwndOkno, nCmdShow);
	UpdateWindow (g_hwndOkno);


	/* pobieramy kontekst urz¹dzenia ekranu */
	g_hdcEkran = GetDC(NULL);


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