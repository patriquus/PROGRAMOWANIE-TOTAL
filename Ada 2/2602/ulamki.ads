PACKAGE Ulamki IS

   TYPE Ulamek IS PRIVATE;

   Blad_Ulamka : EXCEPTION;

   FUNCTION Tworz_Ulamek (
         L,
         M : IN     Integer)
     RETURN Ulamek;

   FUNCTION "=" (
         L,
         R : IN     Ulamek)
     RETURN Boolean;

PRIVATE
   TYPE Ulamek IS
      RECORD
         Licznik   : Integer  := 0;
         Mianownik : Positive := 1;
      END RECORD;
END Ulamki;


