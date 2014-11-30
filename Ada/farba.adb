WITH Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
use Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;

PROCEDURE Farba IS
   A,B,C :Float;
   L_Okien, L_drzwi :Integer;
   Okno_A, Okno_B :Float;
   Drzwi_A, Drzwi_B :Float;
   Okna, Drzwi :Float;
   p, farba:float;

BEGIN
   Put_line("Podaj wymiary pomieszczenia (w metrach): ");
   Put("Wysokosc: "); Get(A);
   Put("Dlugosc: "); Get(b);
   Put("Szerokosc: "); Get(C);

   Put("Podaj liczbe okien: "); Get(L_Okien);
   Put_Line("Podaj wymiary okna (w metrach): ");
   Put("Wysokosc okna: "); Get(Okno_A);
   Put("Szerokosc okna: "); Get(Okno_B);

   Put("Podaj liczbe drzwi: "); Get(L_drzwi);
   Put_Line("Podaj wymiary drzwi (w metrach): ");
   Put("Wysokosc drzwi: "); Get(drzwi_A);
   Put("Szerokosc drzwi: "); Get(drzwi_b);

   P:= 2.0*A*C + 2.0*A*B + A*B; -- calkowita powierzchnia
   Okna:= float(L_Okien) * Okno_A * Okno_B; -- powierzchnia okien
   Drzwi:= float(L_Drzwi) * Drzwi_A * Drzwi_B; -- powierzchnia drzwi
   P:= P - (Okna + Drzwi); -- powierzchnia do pomalowania (bez okien i drzwi)
   Farba:= P / 5.0;

put("Potrzebujesz "); put(farba, 0, 0, 0); put(" l farby");

   end farba;




