WITH Ada.Text_IO;
USE Ada.Text_IO;

PROCEDURE Pnq IS

   PACKAGE Boolio IS NEW Ada.Text_IO.Enumeration_IO(Boolean);
   P,
      Q : Boolean;

use boolio;
BEGIN

put("p"); set_col(8); put("q"); set_col(20); put("p and q");  set_col(32);put("p or q"); set_col(42); put("p xor q");

new_line(2);

P:=True;
Q:=True;
   Put(P); Set_Col(8); Put(Q); Set_Col(20); Put(P AND Q);  Set_Col(32);Put(P OR Q); Set_Col(42); Put(P XOR Q);
   New_Line;

P:=True;
Q:=false;
   Put(P); Set_Col(8); Put(Q); Set_Col(20); Put(P AND Q);  Set_Col(32);Put(P OR Q); Set_Col(42); Put(P XOR Q);
   New_Line;

P:=false;
Q:=True;
   Put(P); Set_Col(8); Put(Q); Set_Col(20); Put(P AND Q);  Set_Col(32);Put(P OR Q); Set_Col(42); Put(P XOR Q);
   New_Line;

P:=false;
Q:=false;
put(p); set_col(8); put(q); set_col(20); put(p and q);  set_col(32);put(p or q); set_col(42); put(p xor q);

END Pnq;

