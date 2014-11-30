WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE Prog1 IS
   Dlugosc : Natural;
   G       : Positive;

BEGIN
   Put("Podaj dlugosc tablicy: ");
   Get(Dlugosc);
   DECLARE
      TYPE Tab IS ARRAY (Integer RANGE 1 .. Dlugosc) OF Integer;
      T : Tab;
   BEGIN

      Put("Wypelnij tablice: ");
      New_Line;
      FOR I IN T'RANGE LOOP
         Get(T(I));
      END LOOP;

      Put("Wyswietla tablice: ");
      New_Line;
      FOR I IN T'RANGE LOOP
         Put(T(I), 0);
         Put(", ");
      END LOOP;

      New_Line;

      Put("Podaj liczbe graniczna G: ");
      Get(G);

      Put("Wyswietla pary");
      New_Line;
      FOR I IN T'RANGE LOOP
         FOR J IN I..T'Last LOOP
            Put(T(I), 0);
            Put(", ");
            Put(T(J), 0);
            New_Line;
         END LOOP;
      END LOOP;

      Put("Wyswietla pary, ktorych suma < G");
      New_Line;
      FOR I IN T'RANGE LOOP
         FOR J IN I..T'Last LOOP
            IF T(I)+T(J) < G THEN
               Put(T(I), 0);
               Put(", ");
               Put(T(J), 0);
               New_Line;
            END IF;
         END LOOP;
      END LOOP;
   END;

END Prog1;
