library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity modulo_top is
	port(
		t_x: in STD_LOGIC_VECTOR(15 downto 0);
		t_clk: in STD_LOGIC;
		t_clr: in STD_LOGIC;
		t_a_g: out STD_LOGIC_VECTOR(7 downto 0);
		t_an: out STD_LOGIC_VECTOR(3 downto 0);
		t_s: out STD_LOGIC_VECTOR(1 downto 0)
	);
end modulo_top;

architecture arq of modulo_top is
signal s_digito: std_logic_vector(3 downto 0);
signal s_s: std_logic_vector(1 downto 0);

begin

U1: entity work.contador PORT MAP(
		clk => t_clk,
		clr => t_clr,
		s => s_s
	);


U2: entity work.hex7seg PORT MAP(
		digito => s_digito, 
		a_g => t_a_g
	);

U3: entity work.mux4x1 PORT MAP(
		s => s_s,
		x => t_x,
		digito => s_digito
	);
	
U4: entity work.selector_an PORT MAP(
		anodos => t_an,
		s => s_s
	);

    t_s <= s_s;

end arq;

