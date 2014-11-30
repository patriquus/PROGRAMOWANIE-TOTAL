WITH Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;

PROCEDURE Rekordy IS
   TYPE Osoba IS
      RECORD
         Imie,
         Nazwisko : String (1 .. 30) := (OTHERS => ' ');
         Pesel    : String (1 .. 11);
         Wzrost   : Positive;
      END RECORD;
   TYPE Osoby IS ARRAY (Positive RANGE <>) OF Osoba;

   --POBIERZ

   PROCEDURE Pobierz (
         O :    OUT Osoba) IS
      N : Positive;
   BEGIN
      Put("Imie: ");
      O.Imie := (OTHERS => ' ');
      Get_Line(O.Imie, N);
      Put("Nazwisko: ");
      O.Nazwisko := (OTHERS => ' ');
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

   -- WYPISZ

   PROCEDURE Wypisz (
         O : IN     Osoba) IS
   BEGIN
      Put("Imie: ");
      Put(O.Imie);
      New_Line;
      Put("Nazwisko: ");
      Put(O.Nazwisko);
      New_Line;
      Put("PESEL: ");
      Put(O.Pesel);
      New_Line;
      Put("Wzrost: ");
      Put(O.Wzrost);
      New_Line(2);
   END Wypisz;

   PROCEDURE Wypisz (
         T : IN     Osoby) IS
   BEGIN
      FOR I IN T'RANGE LOOP
         Wypisz(T(I));
      END LOOP;
   END Wypisz;

   --Czy to jest mezczyzna?

   FUNCTION Czy_Mezczyzna (
         T : IN     Osoby)
     RETURN Boolean IS
      Mezczyzna : Boolean := False;
   BEGIN
      FOR I IN T'RANGE LOOP
         IF Integer'Value(T(I).Pesel(10..10)) mod 2 = 1 THEN
            Mezczyzna:=True;
         END IF;
      END LOOP;
      RETURN Mezczyzna;
   END Czy_Mezczyzna;

   -- Ile osob jest z podanego miesiaca?

   PROCEDURE Miesiac (
         T : IN     Osoby) IS
      Dzien : Integer := 0;
   BEGIN
      FOR I IN T'RANGE LOOP
         IF Integer'Value(T(I).Pesel(3..4)) = Dzien THEN
            Wypisz(T(I));
         END IF;
      END LOOP;
   END Miesiac;

   -- Sredni wiek osob

   FUNCTION Sredni_Wiek_Osob (
         T : IN     Osoby)
     RETURN Float IS
      Sredni_Wiek : Float   := 0.0;
      Suma_Lat    : Integer := 0;
      Wiek_Osoby  : Integer;
   BEGIN
      FOR I IN T'RANGE LOOP
         Wiek_Osoby := 2014 - (1900 + Integer'Value(T(I).Pesel(1..2)));
         Suma_Lat := Suma_Lat + Wiek_Osoby;
      END LOOP;
      Sredni_Wiek := Float(Suma_Lat)/Float(T'Last);
      RETURN Sredni_Wiek;
   END Sredni_Wiek_Osob;

   -- Najstarsza osoba

   FUNCTION Najstarsza_Osoba (
         T : IN     Osoby)
     RETURN Osoba IS
      Najstarsza : Osoba;
   BEGIN
      FOR I IN T'First..T'Last-1 LOOP
         IF Integer'Value(T(I).Pesel(1..2)) < Integer'Value(T(I+1).Pesel(1..2)) THEN
            Najstarsza := T(I);
         ELSE
            Najstarsza := T(I+1);
         END IF;
      END LOOP;
      RETURN Najstarsza;
   END Najstarsza_Osoba;

   -- Wszystkie nazwiska

   PROCEDURE Nazwiska (
         T : IN     Osoby) IS
   BEGIN
      FOR I IN T'RANGE LOOP
         Put(T(I).Nazwisko);
      END LOOP;
   END Nazwiska;

   -- Urodzeni w latach R1-R2

   FUNCTION Urodzeni (
         T  : IN     Osoby;
         R1 : IN     Integer;
         R2 : IN     Integer)
     RETURN Osoby IS
      Rok_Urodzenia : Integer := 0;

   BEGIN
      FOR I IN T'RANGE LOOP
         Rok_Urodzenia:=Integer'Value(T(I).Pesel(1..2));
         IF (R1 < Rok_Urodzenia) AND (Rok_Urodzenia < R2) THEN

         END IF;
         RETURN T;
      END Urodzeni;

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
            --      Czy_Mezczyzna(Grupa);
            --      Sredni_Wiek_Osob(Grupa);
         END;
      END Rekordy;