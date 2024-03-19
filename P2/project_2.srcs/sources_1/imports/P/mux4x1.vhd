
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux4x1 is port(
        s: in std_logic_vector(1 downto 0);
        x: in std_logic_vector(15 downto 0);
        digito: out std_logic_vector(3 downto 0)
    ); 
end mux4x1;

architecture Behavioral of mux4x1 is

begin
process(s)
begin

case s is

	when "00" => digito <= x(3 downto 0);
	when "01" => digito <= x(7 downto 4);
	when "10" => digito <= x(11 downto 8);
	when others => digito <= x(15 downto 12);
	
end case;
end process;

end Behavioral;

