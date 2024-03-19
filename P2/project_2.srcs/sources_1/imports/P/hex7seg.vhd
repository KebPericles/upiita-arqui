
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity hex7seg is port(
        digito: in std_logic_vector(3 downto 0); 
        a_g: out std_logic_vector(7 downto 0)
    );
end hex7seg;

architecture Behavioral of hex7seg is

begin
process(digito)
begin
case digito is
		when x"0" => a_g<= '1'&"0000001";
		when x"1" => a_g<= '1'&"1111001";
		when x"2" => a_g<= '1'&"0100100";
		when x"3" => a_g<= '1'&"0110000";
		when x"4" => a_g<= '1'&"0011001";
		when x"5" => a_g<= '1'&"0010010";
		when x"6" => a_g<= '1'&"0000010";
		when x"7" => a_g<= '1'&"0111000";
		when x"8" => a_g<= '1'&"0000000";
		when x"9" => a_g<= '1'&"0011000";
		
		when others=> a_g<="11111111";
		
		end case;
		end process;


end Behavioral;

