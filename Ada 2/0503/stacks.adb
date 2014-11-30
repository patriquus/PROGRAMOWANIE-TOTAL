WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PACKAGE BODY Stacks IS
   PROCEDURE Push (
         S : IN OUT Stack;
         E : IN     Integer) IS
   BEGIN
      IF S.Top = S.Height THEN
         RAISE Full_Stack_Error;
      END IF;
      S.Top:=S.Top+1;
      S.Elements(S.Top):=E;

   END Push;

   PROCEDURE Show (
         S : IN     Stack) IS
   BEGIN
      FOR I IN REVERSE 1..S.Top LOOP
         Put(S.Elements(I));
         New_Line;
      END LOOP;
   END Show;

   PROCEDURE Pop (
         S : IN OUT Stack;
         E :    OUT Integer) IS
   BEGIN
      IF S.Top = 0 THEN
         RAISE Empty_Stack_Error;
      END IF;
      E:=S.Elements(S.Top);
      S.Top:=S.Top-1;
   END Pop;

         PROCEDURE Clear (
               S : IN OUT Stack   ) IS
         BEGIN
            S.Top:=0;
         END Clear;

--   PROCEDURE Clear (
--         S : IN OUT Stack) IS
--   BEGIN
--      FOR I IN 1..S.Top LOOP
--         S.Elements(I):=0;
--      END LOOP;

   END Clear;


END Stacks;
