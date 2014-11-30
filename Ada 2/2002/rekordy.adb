WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE Rekordy IS
   TYPE Osoba IS
      RECORD
         Imie,
         Nazwisko : String (1 .. 30) := (OTHERS => ' ');
         Pesel    : String (1 .. 11);
         Wzrost   : Positive;
      END RECORD;
   TYPE Osoby IS ARRAY (Positive RANGE <>) OF Osoba;

   PROCEDURE Pobierz (
         O :    OUT Osoba) IS
      N : Positive;
   BEGIN
      Put("Imie: ");
      O.Imie :=(OTHERS => ' ');
      Get_Line(O.Imie, N);
      O.Nazwisko :=(OTHERS => ' ');
      Put("Nazwisko: ");
      Get_Line(O.Nazwisko, N);
      Put("PESEL: ");
      Get(O.Pesel);
      Skip_Line;
      Put("Wzrost: ");
      Get(O.Wzrost);
      Skip_Line;
   END Pobierz;

   PROCEDURE Pobierz (
         T :    OUT Osoby) IS
   BEGIN
      FOR I IN T'RANGE LOOP
         Pobierz(T(I));
      END LOOP;
   END Pobierz;

   PROCEDURE Wypisz (
         O : IN     Osoba) IS
   BEGIN
      Put("Imie: ");
      Put(O.Imie);
      New_line;
      Put("Nazwisko: ");
      Put(O.Nazwisko);
      New_line;
      Put("PESEL: ");
      Put(O.Pesel);
      New_line;
      Put("Wzrost: ");
      Put(O.Wzrost);
      New_line(2);
   END Wypisz;

   PROCEDURE Wypisz (
         T : IN     Osoby) IS
   BEGIN
      FOR I IN T'RANGE LOOP
         Wypisz(T(I));
      END LOOP;
   END Wypisz;

   N : Positive;

BEGIN
   Put("Podaj liczbe osob: ");
   Get(N);
   Skip_Line;
   DECLARE
      Grupa : Osoby (1 .. N);
   BEGIN
      Pobierz(Grupa);
      Wypisz(Grupa);
   END;
END Rekordy;

-- integer'value(t(i).pesel(10..10));

