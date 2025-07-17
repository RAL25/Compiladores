FUNCTION EXE1(a: INTEGER; b: INTEGER) RETURN INTEGER IS
   aux1 : integer := a;
   aux2 : integer := b;
   c : integer;
BEGIN
   IF aux1 > 2 THEN
      c := ((aux1 + aux2) * aux1 - 1 ) /aux2;
   ELSE
      c := 5+9-(10+6-1)+1;
   END IF;
   RETURN c;
END EXE1;