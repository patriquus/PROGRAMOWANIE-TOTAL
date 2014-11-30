WITH Ada.Unchecked_Deallocation, Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.
   Text_IO, Ada.
   Integer_Text_IO;

PACKAGE BODY Stacks IS

   PROCEDURE Free IS
   NEW Ada.Unchecked_Deallocation(Node, Node_Pointer);

   PROCEDURE Push (
         S : IN OUT Stack;
         E : IN     Integer) IS
      P : Node_Pointer := NULL;
   BEGIN
      P := NEW Node;
      P.Value := E;
      P.Next := S.Head;
      S.Head := P;
   END Push;

   -- 1. kat
   -- 2. dane
   -- 3. rodzina
   -- 4. wyrok

   PROCEDURE Pop (
         S : IN OUT Stack;
         E :    OUT Integer) IS
      Kat : Node_Pointer := NULL;
   BEGIN
      Kat:= S.Head;
      IF Kat = NULL THEN
         RAISE Empty_Stack_Error;
      END IF;
      E:=Kat.Value;
      S.Head := Kat.Next;
      Free(Kat);
   END Pop;

   PROCEDURE Show (
         S : IN     Stack
) IS
      P : Node_Pointer := S.Head;
   BEGIN
      WHILE P /= NULL LOOP
         Put(P.Value);
         New_Line;
         P:=P.Next;
      END LOOP;
   END Show;

END Stacks;
