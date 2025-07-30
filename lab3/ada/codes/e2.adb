FUNCTION EXE2(a: INTEGER; b: INTEGER) RETURN INTEGER IS
aux1 : integer := a;
aux2 : integer := b;
c : integer := 0;
BEGIN
   while c<5 loop
      aux2 := c + aux2;
      c := c + 1;
   end loop; 
   return aux2-aux1;
END EXE2;