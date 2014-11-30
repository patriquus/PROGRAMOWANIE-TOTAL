WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE dniMiesiac IS

   TYPE Miesiace IS
         (Styczen,
          Luty,
          Marzec,
          Kwiecien,
          Maj,
          Czerwiec,
          Lipiec,
          Sierpien,
          Wrzesien,
          Pazdziernik,
          Listopad,
          Grudzien);

   PACKAGE Mio IS NEW Ada.Text_IO.Enumeration_IO(Miesiace);
   USE Mio;

   M : Miesiace;
   R,
   D : Integer;

BEGIN

   Put("Podaj nazwe miesiaca: ");
   Get(M);
   Put("Podaj rok: ");
   Get(R);

   CASE M IS

      WHEN Luty =>

         IF R mod 4 = 0 AND (R mod 100 /= 0 OR R mod 400 = 0) THEN
            D:=29;
         ELSE
            D:=28;
         END IF;


      WHEN Styczen | Marzec | Maj | Lipiec | Sierpien | Pazdziernik | Grudzien =>
         D:=31;
      WHEN OTHERS =>
         D:=30;
   END CASE;

   Put(M, set=>lower_case); Put(" w "); Put(R, width=>0); Put(" roku mial "); Put(D, width=>0); Put(" dni");

END dniMiesiac;
