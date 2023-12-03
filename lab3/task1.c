void init() {
	__asm__(
		".equ SW_MEMORY, 0xFF200040\n\t"
        ".equ LED_MEMORY, 0xFF200000\n\t"
		".equ HEX_MEMORY, 0XFF200020\n\t"
		".equ HEX4_MEMORY, 0XFF200030\n\t"
		".equ P_MEMORY, 0xFF200050\n\t"
		".equ PEDGE_MEMORY, 0xFF20005C\n\t"
		".equ PMASK_MEMORY, 0xFF200058\n\t"
	);
}

int read_slider_switches_ASM() {
	int readVal = 0;
	__asm__  __volatile__(
		"LDR R1, =SW_MEMORY\n\t"
    	"LDR R0, [R1]\n\t"
		"MOV %0, R0\n\t"
        :"=r"(readVal) // output operand %0
	);
	return readVal;
}

void write_LEDs_ASM(int val) {
	__asm__  __volatile__(
		"MOV R0, %0\n\t"
		"LDR R1, =LED_MEMORY\n\t"
    	"STR R0, [R1]\n\t"
        :    		
        :"r"(val)  // input operand %0
	);
}

// Task 1.1

void HEX_write_ASM(int hexId, int val) {
	__asm__  __volatile__(
		"MOV R1, %0\n\t"
		"MOV R2, %1\n\t"
		
		//defining patterns for values 0-F
		
		"CMP R2, #0\n\t"
		"BEQ pattern_0\n\t"
		
		"CMP R2, #1\n\t"
		"BEQ pattern_1\n\t"
		
		"CMP R2, #2\n\t"
		"BEQ pattern_2\n\t"
		
		"CMP R2, #3\n\t"
		"BEQ pattern_3\n\t"

		"CMP R2, #4\n\t"
		"BEQ pattern_4\n\t"
		
		"CMP R2, #5\n\t"
		"BEQ pattern_5\n\t"
		
		"CMP R2, #6\n\t"
		"BEQ pattern_6\n\t"
		
		"CMP R2, #7\n\t"
		"BEQ pattern_7\n\t"

		"CMP R2, #8\n\t"
		"BEQ pattern_8\n\t"
		
		"CMP R2, #9\n\t"
		"BEQ pattern_9\n\t"
		
		"CMP R2, #10\n\t"
		"BEQ pattern_A\n\t"
		
		"CMP R2, #11\n\t"
		"BEQ pattern_B\n\t"

		"CMP R2, #12\n\t"
		"BEQ pattern_C\n\t"
		
		"CMP R2, #13\n\t"
		"BEQ pattern_D\n\t"
		
		"CMP R2, #14\n\t"
		"BEQ pattern_E\n\t"
		
		"CMP R2, #15\n\t"
		"BEQ pattern_F\n\t"
		
		//branches for respective patterns
		
		"pattern_0:\n\t"
        "MOV R0, #0x3F\n\t"
        "B end_patterns\n\t"
		
		"pattern_1:\n\t"
        "MOV R0, #0x06\n\t"
        "B end_patterns\n\t"

		"pattern_2:\n\t"
        "MOV R0, #0x5B\n\t"
        "B end_patterns\n\t"
		
		"pattern_3:\n\t"
        "MOV R0, #0x4F\n\t"
        "B end_patterns\n\t"
		
		"pattern_4:\n\t"
        "MOV R0, #0x66\n\t"
        "B end_patterns\n\t"
		
		"pattern_5:\n\t"
        "MOV R0, #0x6D\n\t"
        "B end_patterns\n\t"

		"pattern_6:\n\t"
        "MOV R0, #0x7D\n\t"
        "B end_patterns\n\t"
		
		"pattern_7:\n\t"
        "MOV R0, #0x07\n\t"
        "B end_patterns\n\t"

		"pattern_8:\n\t"
        "MOV R0, #0x7F\n\t"
        "B end_patterns\n\t"
		
		"pattern_9:\n\t"
        "MOV R0, #0x6F\n\t"
        "B end_patterns\n\t"

		"pattern_A:\n\t"
        "MOV R0, #0x77\n\t"
        "B end_patterns\n\t"
		
		"pattern_B:\n\t"
        "MOV R0, #0x7C\n\t"
        "B end_patterns\n\t"
		
		"pattern_C:\n\t"
        "MOV R0, #0x39\n\t"
        "B end_patterns\n\t"
		
		"pattern_D:\n\t"
        "MOV R0, #0x5E\n\t"
        "B end_patterns\n\t"

		"pattern_E:\n\t"
        "MOV R0, #0x79\n\t"
        "B end_patterns\n\t"
		
		"pattern_F:\n\t"
        "MOV R0, #0x71\n\t"
        "B end_patterns\n\t"
		
		// End of pattern definitions
        "end_patterns:\n\t"
		"LDR R3, =HEX_MEMORY\n\t"
		
		//looping through
		"MOV R4, #0\n\t"
		"loop: \n\t"
		"CMP R4, #6\n\t"
		"BEQ end_loop\n\t"
		"MOV R5, #1\n\t"
		"LSL R5, R4\n\t"
		"TST R1, R5\n\t"
		"BEQ next\n\t"
		"STRB R0, [R3, R4]\n\t"
		
		"next: \n\t"
		"ADD R4, R4, #1\n\t"
		"B loop\n\t"
		
		"end_loop: \n\t"
		:
    	:"r"(hexId), "r"(val) // input operands %0 and %1
	);
}

void HEX_clear_ASM(int hexId) {
	__asm__  __volatile__(
		"MOV R1,%0\n\t"
		"LDR R0, =HEX_MEMORY\n\t"
		"LDR R2, =HEX4_MEMORY\n\t"
		"MOV R3, #0\n\t" //used for clearing
		
		//checking to see which HEX is selected
		"CMP R1, #0x01\n\t"
		"BNE hex_1\n\t"
		"STRB R3, [R0]\n\t"
		
		"hex_1:\n\t"
		"CMP R1, #0x02\n\t"
		"BNE hex_2\n\t"
		"STRB R3, [R0, #1]\n\t"	

		"hex_2:\n\t"
		"CMP R1, #0x04\n\t"
		"BNE hex_3\n\t"
		"STRB R3, [R0, #2]\n\t"	

		"hex_3:\n\t"
		"CMP R1, #0x08\n\t"
		"BNE hex_4\n\t"
		"STRB R3, [R0, #3]\n\t"	

		"hex_4:\n\t"
		"CMP R1, #0x10\n\t"
		"BNE hex_5\n\t"
		"STRB R3, [R2]\n\t"	
		
		"hex_5:\n\t"
		"CMP R1, #0x20\n\t"
		"BNE end_hex\n\t"
		"STRB R3, [R2, #1]\n\t"	
		
		"end_hex:\n\t"
		:
		:"r"(hexId)
	);
}

void HEX_flood_ASM(int hexId) {
	__asm__  __volatile__(
		"MOV R1,%0\n\t"
		"LDR R0, =HEX_MEMORY\n\t"
		"LDR R2, =HEX4_MEMORY\n\t"
		"MOV R3, #127\n\t" //used for flooding
		
		//checking to see which HEX is selected
		"CMP R1, #0x01\n\t"
		"BNE hex_one\n\t"
		"STRB R3, [R0]\n\t"
		
		"hex_one:\n\t"
		"CMP R1, #0x02\n\t"
		"BNE hex_two\n\t"
		"STRB R3, [R0, #1]\n\t"	

		"hex_two:\n\t"
		"CMP R1, #0x04\n\t"
		"BNE hex_three\n\t"
		"STRB R3, [R0, #2]\n\t"	

		"hex_three:\n\t"
		"CMP R1, #0x08\n\t"
		"BNE hex_four\n\t"
		"STRB R3, [R0, #3]\n\t"	

		"hex_four:\n\t"
		"CMP R1, #0x10\n\t"
		"BNE hex_five\n\t"
		"STRB R3, [R2]\n\t"	
		
		"hex_five:\n\t"
		"CMP R1, #0x20\n\t"
		"BNE end_check\n\t"
		"STRB R3, [R2, #1]\n\t"	
		
		"end_check:\n\t"
		:
		:"r"(hexId)
	);
}

// Pushbuttons
int PB_data_is_pressed_ASM(int idx) {
	int val = 0;
	__asm__  __volatile__(
		"MOV R1, %1\n\t"
		"LDR R0, =P_MEMORY\n\t"
		"LDR R2, [R0]\n\t"
		"CMP %0, R1\n\t"
		"BEQ data_pressed\n\t"
		
		"MOV %0, #0\n\t"
		"B end_press\n\t"
		
		"data_pressed: \n\t"
		"MOV %0, #1\n\t"
		
		"end_press: \n\t"
		:"=r"(val) // output operand %0
		:"r"(idx)  // input operand %1
	);
	return val;
}

int read_PB_data_ASM() {
	int val = 0;
	__asm__  __volatile__(
		"LDR R1, =P_MEMORY\n\t"
		"LDR %0, [R1]\n\t"
		:"=r"(val) // output operand %0
	);
	return val;
}

int PB_edgecp_is_pressed_ASM(int idx) {
	int val = 0;
	__asm__  __volatile__(
		"MOV R1, %1\n\t"
		"LDR R0, =PEDGE_MEMORY\n\t"
		"LDR R2, [R0]\n\t"
		"CMP R2, R1\n\t"
		"BEQ edge_pressed\n\t"
		
		//not pressed
		"MOV %0, #0\n\t"
		"B end_edgepressed\n\t"
		
		//pressed
		"edge_pressed:\n\t"
		"MOV %0, #1\n\t"
		
		"end_edgepressed: \n\t"
		:"=r"(val) // output operand %0
		:"r"(idx)  // input operand %1
	);
	return val;
}

int read_PB_edgecp_ASM() {
	int val = 0;
	__asm__ __volatile__(
		"LDR R1, =PEDGE_MEMORY\n\t"
		"LDR %0, [R1]\n\t"
		:"=r"(val) // output operand %0
	);
	return val;
}

void PB_clear_edgecp_ASM() {
	__asm__  __volatile__(
		"MOV R1, #0xFF\n\t"
		"LDR R0, =PEDGE_MEMORY\n\t"
		"STRB R1, [R0]"
	);
}


void enable_PB_INT_ASM(int idx) {
	__asm__  __volatile__(
		"LDR R1, =PMASK_MEMORY\n\t"
		"LDRB R0, [R1]\n\t"
		"ORR %0, R0, %0\n\t"
		"STRB %0, [R1]\n\t"
		: 
		:"r"(idx) // input operand %0
	);
}

void disable_PB_INT_ASM(int idx) {
	__asm__  __volatile__(
		"MVN R1, %0\n\t"
		"LDR R0, =PMASK_MEMORY\n\t"
		"LDRB R2, [R0]\n\t"
		"AND R3, R2, R1\n\t"
		"STRB R3, [R0]\n\t"
		: 
		:"r"(idx) // input operand %0
	);
}


int main() {
	init();
	HEX_clear_ASM(63);
    HEX_flood_ASM(48);
    PB_clear_edgecp_ASM();
    disable_PB_INT_ASM(15);
	
	while(1) { // infinite loop
		int switchState = read_slider_switches_ASM(); // read slider switch state
		write_LEDs_ASM(switchState); // write state to the LEDs
		
		int sw9 = 512; //2^9
		int allSwitches = 15; //2^0 + 2^1 + 2^2 + 2^3
		int pbRelease = read_PB_edgecp_ASM() & allSwitches;
		
		//checking if switch 9 is pressed
		if(sw9 & switchState) {
			HEX_clear_ASM(15);
		}
		else if(pbRelease !=0){
			int val = switchState & allSwitches;
            HEX_write_ASM(pbRelease, val);
            PB_clear_edgecp_ASM();
		}
	}
	return 0;
}
