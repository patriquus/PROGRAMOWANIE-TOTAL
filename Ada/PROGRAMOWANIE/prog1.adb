WITH Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;

PROCEDURE Prog1 IS
   A,
   B,
   C,
   G,
   Ile,
   Suma    : Integer;
   Srednia : Float;
BEGIN
   Put("podaj G: ");
   Get(G);
   Suma:=0;
   Srednia:=0.0;
   Ile:=0;
   C:=0;
   B:=0;
   LOOP
      Put("Podaj liczbe: ");

      Get(A);
      EXIT WHEN A=0;
      IF C /= 0 AND B /= 0 THEN
         IF (A > C) AND (B > C) THEN
            Suma:=A+B;
            Srednia:=Float(Suma)/2.0;
         ELSIF (B > A) AND (C > A) THEN
            Suma:=B+C;
            Srednia:=Float(Suma)/2.0;
         ELSIF (A > B) AND (C > B) THEN
            Suma:=A+C;
            Srednia:=Float(Suma)/2.0;
         END IF;

      END IF;

      IF Float(Srednia) > Float(G) THEN
         Ile:=Ile+1;
         Put(C, 0);
         Put(", ");
         Put(B, 0);
         Put(", ");
         Put(A, 0);
      END IF;
      C:=B;
      B:=A;
   END LOOP;
   Put("ile: ");
   Put(Ile);
END Prog1;
