with Ada.Text_IO; use Ada.Text_IO;
procedure Temp is
   FUNCTION EXE3(n : Integer) RETURN INTEGER IS
      aux : integer := n;
   BEGIN
      if aux<=0 then
         return 0;
      end if;
      return aux + EXE3(aux-1);
   END EXE3;

   res : integer;
BEGIN
   res := EXE3(5);
   Put_Line(Integer'Image(res));
end Temp;