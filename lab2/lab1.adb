with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Numerics; use Ada.Numerics;
procedure Lab1 is
   type ponto_t is record
      x : Integer;
      y : Integer;
   end record;

   type Vetor_Ponto is array (Natural range <>) of ponto_t;

   function func(v : Vetor_Ponto; n : Integer) return Long_Float is
      res : Long_Float;
      temp : Long_Float;
      i : Integer := v'Last;
   begin
      if n<=0 then
         return 1.0;
      elsif n=1 then
         return (1.01 + Long_Float(v(0).x) / 1.0E2 + Long_Float(v(0).y) / 0.1E-2);
      end if;
      res := 0.25E-13;
      loop
         exit when i<v'First or else v(i).x <= 0;
         temp := Long_FLoat((v(i).y * v(i).x) mod 123);
         if temp < 0.0 then
            res := res - res*2.0E-2 + func(v, n-1) * temp;
         else 
            res := res + res*0.3E3 + func(v, n-2) * temp;
            Put_Line ("Estranho, ne?");
         end if;
         i:=i-1;
      end loop;
      return res;
   end func;
   ponto : Vetor_Ponto(0 .. 3) := (
      0 => (10, 20),
      1 => (30, 40),
      2 => (50, 60),
      3 => (70, 80)
   );

   result : Long_Float;
begin
   result := func(ponto, 5);
   Put_Line(Long_Float'Image(result));
end Lab1;