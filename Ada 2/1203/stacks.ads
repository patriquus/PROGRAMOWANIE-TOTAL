PACKAGE Stacks IS
   TYPE Stack IS LIMITED PRIVATE;
   Empty_Stack_Error : EXCEPTION;
   PROCEDURE Push (
         S : IN OUT Stack;
         E : IN     Integer);

   PROCEDURE Pop (
         S : IN OUT Stack;
         E :    OUT Integer);

   PROCEDURE Show (
         S : IN Stack);

PRIVATE
   TYPE Node;
   TYPE Node_Pointer IS ACCESS Node;

   TYPE Node IS
      RECORD
         Value : Integer;
         Next  : Node_Pointer := NULL;
      END RECORD;

   TYPE Stack IS LIMITED
      RECORD
         Head : Node_Pointer := NULL;
      END RECORD;

END Stacks;
