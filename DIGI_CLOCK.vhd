library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity DIGI_CLOCK is
	port (
			KEY0_Y: in std_logic;

			MAX10_CLK1_50_Y: in std_logic;
			
			DIGITAL_CLK: buffer std_logic_vector (31 downto 0);
			CLK_PAUSE:	 in	std_logic;
			CLK_RESET:   in   std_logic
			
			
			);	
	end DIGI_CLOCK;
	
architecture BEHAVIORAL of DIGI_CLOCK is

signal BIN_CNT: std_logic_vector (31 downto 0);
signal TEMP: std_logic_vector (31 downto 0);


begin

P01:process (KEY0_Y, MAX10_CLK1_50_Y, DIGITAL_CLK)
begin
	
	if(KEY0_Y = '0') then
		BIN_CNT <= "00000000000000000000000000000000";
		TEMP <= "00000000000000000000000000000000";
		elsif(rising_edge(MAX10_CLK1_50_Y)) then
			BIN_CNT <= BIN_CNT + '1';
				if(BIN_CNT = "00000010111110101111000010000000") then
				
					if(CLK_PAUSE = '1') then
					TEMP <= TEMP+'1';
					else
					
					end if;
					
					BIN_CNT <= "00000000000000000000000000000000";
				end if;
		elsif(rising_edge(MAX10_CLK1_50_Y)) then
				if(TEMP = "11111111111111111111111111111111") then	
					TEMP <= "00000000000000000000000000000000";
				end if;
				
	end if;
	
end process; 

P02:process (KEY0_Y, MAX10_CLK1_50_Y, DIGITAL_CLK)
begin

		if(KEY0_Y = '0') then
		
		elsif(rising_edge(MAX10_CLK1_50_Y)) then
				if(TEMP > "00000000000000000000000000000000") then
					DIGITAL_CLK <= TEMP;
				end if;
				
				if(CLK_RESET = '1') then
					DIGITAL_CLK <= "00000000000000000000000000000000";
				end if;
				
		end if;
		

		
		
end process;

end BEHAVIORAL;
	
			