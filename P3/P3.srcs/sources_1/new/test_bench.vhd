----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/15/2024 12:37:49 PM
-- Design Name: 
-- Module Name: test_bench - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------
library IEEE;
USE IEEE.STD_LOGIC_1164.all;
USE IEEE.std_logic_arith.all;
USE IEEE.std_logic_unsigned.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity test_bench is
end test_bench;

architecture Behavioral of test_bench is
  signal preset_test, clear_test, clk_test, D_test, Q_test, Qn_test : std_logic;
begin
  a1 : entity work.ffd port map
    (
    preset => preset_test,
    clear  => clear_test,
    clk    => clk_test,
    D      => D_test,
    Q      => Q_test,
    Qn     => Qn_test
    );

  process
  begin
    wait for 10 ns;
    CLOCK_LOOP : loop
      clk_test <= '0';
      wait for 20 ns;
      clk_test <= '1';
      wait for 20 ns;
    end loop CLOCK_LOOP;
  end process;

  preset_test <= '1';
  clear_test  <= '1';
  
  D_test <= '0', '1' after 100 ns;
end Behavioral;