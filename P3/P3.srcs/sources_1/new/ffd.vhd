----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/15/2024 12:24:52 PM
-- Design Name: 
-- Module Name: ffd - Behavioral
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
use IEEE.STD_LOGIC_1164.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ffd is
  port
  (
    preset, clear, clk, D : in std_logic;
    Q, Qn                 : out std_logic
  );
end ffd;

architecture Behavioral of ffd is
begin
  process (clk, preset, clear) begin
    if (clear = '0') then
      Qn <= '1';
      Q  <= '0';
    elsif (rising_edge(clk)) then
      if (preset = '0') then
        Q  <= '1';
        Qn <= '0';
      else
        Q  <= D;
        Qn <= not D;
      end if;
    end if;
  end process;

end Behavioral;