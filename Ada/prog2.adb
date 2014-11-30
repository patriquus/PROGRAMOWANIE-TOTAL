WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE Prog2 IS
   Dlugosc : Natural;
   Byla,
   Ile     : Integer;

BEGIN

   Put("Podaj dlugosc tablicy: ");
   Get(Dlugosc);

   DECLARE
      TYPE Tab IS ARRAY (Integer RANGE 1 .. Dlugosc) OF Integer;
      T : Tab;

   BEGIN

      FOR I IN T'RANGE LOOP
         Get(T(I));
      END LOOP;

      FOR I IN T'RANGE LOOP
         Put(T(I), 0);
         Put(", ");
      END LOOP;

      FOR I IN T'RANGE LOOP
         Byla:=0;
         FOR J IN T'First .. I-1 LOOP
            IF T(I)=T(J) THEN
               Byla:=1;
            END IF;
         END LOOP;
         IF Byla=0 THEN
            Ile:=0;

            FOR J IN I..T'Last LOOP
               IF T(I)=T(J) THEN
                  Ile:=Ile+1;
               END IF;
            END LOOP;
            Put(T(I));
            Put(" wystapilo ");
            Put(Ile);
            Put_Line(" razy");
         END IF;
      END LOOP;
   END;
END Prog2;
      
