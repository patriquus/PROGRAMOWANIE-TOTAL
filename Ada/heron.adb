WITH Ada.Text_IO, Ada.Numerics, Ada.Numerics.Elementary_Functions, Ada.Float_Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Numerics, Ada.Numerics.Elementary_Functions, Ada.Float_Text_IO, Ada.Integer_Text_IO;

PROCEDURE Heron IS
   A,
   B,
   C  : Integer;
   P,
   Pt : Float;

BEGIN
   Put_Line("Podaj dlugosci bokow trojkata: ");
   Put("a: ");
   Get(A);
   Put("b: ");
   Get(B);
   Put("c: ");
   Get(C);

   IF A>0 AND B>0 AND C>0 THEN
      IF (A+B)>C AND (A+C)>B AND (B+C)>A THEN
         P:=Float(A+B+C)/2.0;
         Pt:= Sqrt(P*(P-Float(A))*(P-Float(B))*(P-Float(C)));
         Put("Pole trojkata wynosi: ");
         Put(Pt, Exp=>0);
      ELSE
         Put("Podane liczby nie moga byc bokami trojkata");
      END IF;
   ELSE
      Put("Dlugosci musza byc wieksze od zera!");
   END IF;

END Heron;
