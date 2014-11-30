with ada.Text_IO, ada.Integer_Text_IO, ada.Float_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;

PROCEDURE Funkcja_Kwadratowa IS
   A,B,C : Integer;
   Y,X : Float;

BEGIN
   Put_line("Funkcja kwadratowa");
   Put_Line("y=ax^2+bx+c");

   Put_line("Podaj wspolczynniki a, b i c");
   Put("a: "); Get(A);
   Put("b: "); Get(b);
   Put("c: "); Get(C);

   Put_Line("Podaj argument x: "); Get(X);

   Y := float(a)*x**2 + float(b)*x + float(c);
   Put("Wartosc funkcji wynosi: "); Put(Y, Aft => 2, Exp => 0);

   end funkcja_kwadratowa;


