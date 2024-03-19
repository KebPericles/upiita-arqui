library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity contador is
	port(
		clk, clr: in std_logic;
		s: out std_logic_vector(1 downto 0)
	);
end contador;

architecture arq of contador is
signal regcon: std_logic_vector(19 downto 0);
begin
-- Contador
process(clk, clr)
begin
	if clr = '1' then regcon <= (others => '0');
	elsif clk= '1' and clk'event then regcon <= regcon + 1;
	end if;
end process;
s <= regcon(19 downto 18);
end arq;



