-- Ejemplo de una descripcion funcional
library ieee;
use ieee.std_logic_1164.all;

entity compuerta1 is
port (b: in std_logic_vector(3 downto 0);
      an: out std_logic_vector(3 downto 0);
      sel_an: in std_logic_vector(3 downto 0);
      ag: out std_logic_vector(6 downto 0));
end compuerta1;

architecture compuerta1 of compuerta1 is
begin
    an<= not sel_an;
	with b select
        ag <= "0000001" when "0000",
              "1001111" when "0001",
              "0010010" when "0010",
              "0000110" when "0011",
              "1001100" when "0100",
              "0100100" when "0101",
              "0100000" when "0110",
              "0001110" when "0111",
              "0000000" when "1000",
              "0001100" when "1001",
              "1111111" when others;         
              
end compuerta1;
