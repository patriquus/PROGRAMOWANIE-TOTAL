WITH Stacks, Ada.Text_IO, Ada.Integer_Text_IO;
USE Stacks, Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE Test IS
   A        : Integer;
   My_Stack : Stack (10);
BEGIN
   FOR I IN 1..10 LOOP
      Get(A);
      Push(My_Stack, A);
      Show(My_Stack);
   END LOOP;
   Pop(My_Stack, a);
   Put("zdjeto ");
   Put(A,0);
   New_Line;
   Show(My_Stack);


END Test;
