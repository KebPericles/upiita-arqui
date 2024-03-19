
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity selector_an is port(
		anodos: out std_logic_vector(3 downto 0);
		s: in std_logic_vector(1 downto 0)
	);
end selector_an;

architecture Behavioral of selector_an is

begin

process(s)
begin

case s is
	when "00" => anodos <= "1110";
	when "01" => anodos <= "1101";
	when "10" => anodos <= "1011";
	when "11" => anodos <= "0111";
	
	when others => anodos <= "1111";
end case;
end process;

end Behavioral;

