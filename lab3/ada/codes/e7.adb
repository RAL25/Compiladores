FUNCTION EXE3(n : Integer) RETURN INTEGER IS
   aux : integer := n;
BEGIN
   if aux<=0 then
      return 0;
   end if;
   return aux + aux-1;
END EXE3;
