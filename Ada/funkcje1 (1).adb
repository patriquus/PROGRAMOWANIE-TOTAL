WITH Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO, Ada.Numerics.Elementary_Functions;
USE Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO, Ada.Numerics.Elementary_Functions;

PROCEDURE Funkcje1 IS
   PACKAGE Boolio IS NEW
      Ada.Text_IO.Enumeration_IO(Boolean);
   USE Boolio;
   FUNCTION PoleTrojkata (
         A,
         B,
         C : Integer)
     RETURN Float IS
      Pole,
      P    : Float;
   BEGIN
      P:=Float((A+B+C))*0.5;
      Pole:=Sqrt(P*(P-Float(A))*(P-Float(B))*(P-Float(C)));
      RETURN Pole;
   END PoleTrojkata;

   FUNCTION ObwodTrojkata (
         A,
         B,
         C : Integer)
     RETURN Integer IS
      L : Integer;
   BEGIN
      L:=A+B+C;
      RETURN L;
   END ObwodTrojkata;

   FUNCTION CzyTrojkat (
         A,
         B,
         C : Integer)
     RETURN Boolean IS
      X : Boolean;
   BEGIN
      IF A>0 AND B>0 AND C>0 THEN
         IF (A+B)>C AND (A+C)>B AND (B+C)>A THEN
            X:=True;
         ELSE
            X:=False;
         END IF;
      ELSE
         X:=False;
      END IF;
      RETURN X;
   END CzyTrojkat;

   F1 : Float;
   F2 : Integer;
   F3 : Boolean;
   A,
   B,
   C  : Integer;
BEGIN


         Get(A);
   Get(B);
   LOOP
      get(c);
   A:=B;
      B:=C;
      exit when c=0;
      end loop;
      

put(a);put(b);put(c);

--   F3:=CzyTrojkat(A,B,C);
--   IF F3=True THEN

--      F1:=PoleTrojkata(A,B,C);
--      Put("Pole trojkata wynosi: ");
--      Put(F1, 0, 0, 0);

--      F2:=ObwodTrojkata(A,B,C);
--      Put("Obwod trojkata wynosi: ");
--      Put(F2);

--   ELSE
--      Put("Podales zle dlugosci");
--   END IF;

END Funkcje1;
   



