PROCEDURE Main IS
  x : INTEGER := 5;
  FUNCTION Calc(a: INTEGER; b: INTEGER) RETURN INTEGER IS
    c : INTEGER;
  BEGIN
    IF a > 0 THEN
      c := (a * b) + Calc(a-1, b);
    ELSE
      c := 0;
    END IF;
    RETURN c;
  END Calc;
BEGIN
  x := Calc(x, 3);
  IF x < 10 THEN
    x := 1;
  ELSIF x < 20 THEN
    x := 1;
  ELSE
    x := 1;
  END IF;
END Main;