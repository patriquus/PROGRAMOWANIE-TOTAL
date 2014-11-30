WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE ParaG IS
   G,
   A,
   B : Integer;
BEGIN
   Put("Podaj liczbe G: ");
   Get(G);
   Put("Podaj liczbe: ");
   Get(B);
   LOOP
      A:=B;
      Put("Podaj liczbe: ");
      Get(B);
      EXIT WHEN B=0;
      IF A/=0 THEN
         IF (A+B) >= G THEN
            Put(A, Width=>0);
            Put(", ");
            Put(B, Width=>0);
            New_Line;
         END IF;
      END IF;
      EXIT WHEN B=0;
   END LOOP;
END ParaG;
