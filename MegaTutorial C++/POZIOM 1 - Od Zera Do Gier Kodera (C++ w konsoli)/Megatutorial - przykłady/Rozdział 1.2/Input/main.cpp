// Input - u¿ycie zmiennych i strumienia wejœcia

#include <string>
#include <iostream>
#include <conio.h>

void main()
{
	std::string strImie;

	std::cout << "Podaj swoje imie: ";
	std::cin >> strImie;
	std::cout << "Twoje imie to " << strImie << "." << std::endl;

	getch();
}