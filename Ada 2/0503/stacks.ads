PACKAGE Stacks IS
   TYPE Stack
         (Height : Positive) IS PRIVATE;
   Full_Stack_Error  : EXCEPTION;
   Empty_Stack_Error : EXCEPTION;

   PROCEDURE Push (
         S : IN OUT Stack;
         E : IN     Integer);
   PROCEDURE Show (
         S : IN     Stack);
   PROCEDURE Pop (
         S : IN OUT Stack;
         E :    OUT Integer);
   PROCEDURE Clear (
         S : IN OUT Stack); PRIVATE TYPE Table IS
      ARRAY (Positive RANGE <>) OF Integer;
      TYPE Stack
            (Height : Positive) IS
         RECORD
            Elements : Table (1 .. Height);
            Top      : Natural             := 0;
         END RECORD;
   END Stacks;
