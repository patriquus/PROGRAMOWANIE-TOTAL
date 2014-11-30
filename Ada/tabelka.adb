WITH Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
PROCEDURE Tabelka IS
   A,B:Integer;
BEGIN
   Put("Podaj a: "); Get(A);
   Put("Podaj b: "); Get(B);
   set_col(50); Put("rem"); set_col(62); Put("mod"); New_line;
   Put(A); Put(" "); Put(B); Put(A rem B); Put(" ");  Put(A mod B); New_line;
   Put(-A); Put(" "); Put(B); Put(-A rem B); Put(" ");  Put(-A mod B); New_line;
   Put(A); Put(" "); Put(-B); Put(A rem (-B)); Put(" ");  Put(A mod (-B)); New_line;
   Put(-A); Put(" "); Put(-B); Put(-A rem (-B)); Put(" ");  Put(-A mod (-B)); New_line;

END Tabelka;
