WITH Ulamki, Ada.Text_IO;
USE Ulamki, Ada.Text_IO;

PROCEDURE Test IS
   U1,
   U2 : Ulamek;
BEGIN
   --   u1.mianownik := 0;

   --   nie mozna sie odwolac,
   --   bo typ ulamek jest prywatny

   U1 := Tworz_Ulamek(1,2);
   U2 := Tworz_ulamek(2,4);

   --   u1=u2 <=> "="(u1,u2) - operator porownania to funkcja

 IF u1 = u2 THEN
      Put("Sa rowne");
   ELSE
      Put ("Nie sa rowne");
   END IF;

END Test;


