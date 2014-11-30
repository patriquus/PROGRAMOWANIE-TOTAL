WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE Prog3 IS

   TYPE Tab IS ARRAY (Integer RANGE <>) OF Integer;

   PROCEDURE Pobierz (
         T :    OUT Tab) IS
   BEGIN
      FOR I IN T'RANGE LOOP
         Get(T(I));
      END LOOP;
   END Pobierz;

   PROCEDURE Wypisz (
         T : IN     Tab) IS
   BEGIN
      FOR I IN T'RANGE LOOP
         Put(T(I), 0);
         PUT(", ");
      END LOOP;
   END Wypisz;

   PROCEDURE Odwrocpoczatek (
         T : IN OUT Tab;
         K : IN     Positive) IS
      Pom,
      X   : Integer;

   BEGIN
      X:=T'Last;
      IF K>T'Length  THEN
         FOR I IN T'First..(K/2)-1 LOOP
            Pom:=T(I);
            T(I):=T(X);
            T(X):=Pom;
            X:=X-1;
         END LOOP;
      END IF;
      X:=K;
      IF K<T'Length  THEN
         FOR I IN T'First..K/2 LOOP

            Pom:=T(I);
            T(I):=T(X);
            T(X):=Pom;
            X:=X-1;
         END LOOP;
      END IF;
   END Odwrocpoczatek;

   -------FUNKCJA--------------------
   ----------------------------------
   FUNCTION Usun (
         T : Tab;
         N : Positive)
     RETURN Tab IS
      Ile,
      Bool : Integer;
      X    : Tab (1 .. T'Length);

   BEGIN
      Ile:=0;
      FOR I IN T'First..T'Last-N LOOP
         FOR J IN T'First..(I+N) LOOP
            IF J mod 2 = 0 THEN
               X(I):=T(I);
               Ile:=Ile+1;
            END IF;
         END LOOP;
      END LOOP;

      RETURN X;
   END Usun;

   ----------------------------------
   --1 2 3 5 7 8
   --0 1 2 3 4 5
   ----------------------------------
   K,
   N,
   Dlugosc : Positive;

BEGIN
   Put("Dlugosc tablicy: ");
   Get(Dlugosc);
   Put("Podaj k: ");
   Get(K);
   Put("Podaj n: ");
   Get(N);
   DECLARE
      T : Tab (1 .. Dlugosc);
   BEGIN
      Put("Pobieranie tablicy: ");
      Pobierz(T);
      Put("Wypisywanie tablicy: ");
      Wypisz(T);
      Put("Odwroc Poczatek: ");
      OdwrocPoczatek(T,K);
      Wypisz(T);
      --      Put("Wypisz Usun: ");
      --      Wypisz(Usun(T,N));



   END;
END Prog3;

