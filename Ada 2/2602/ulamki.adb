PACKAGE BODY Ulamki IS
   FUNCTION Tworz_Ulamek (
         L,
         M : IN     Integer)
     RETURN Ulamek IS
      U : Ulamek;
   BEGIN
      IF M = 0 THEN
         RAISE Blad_Ulamka;
      END IF;
      U.Licznik := L;
      U.Mianownik := M;
      RETURN U;
   END Tworz_Ulamek;

   FUNCTION "=" (
         L,
         R : IN     Ulamek)
     RETURN Boolean IS
   BEGIN
      IF L.Licznik * R.Mianownik = L.Mianownik * R.Licznik THEN
         RETURN True;
      ELSE
         RETURN False;
      END IF;
   END "=";
END Ulamki;
