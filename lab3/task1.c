void init() {
	__asm__(
		".equ SW_MEMORY, 0xFF200040\n\t"
		".equ LED_MEMORY, 0xFF200000\n\t"
		".equ HEX_MEMORY, 0xFF200020\n\t"
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
		"MOV A1, %0\n\t"
		"MOV A2, %1\n\t"
		
		//defining patterns for values 0-F
		
		"CMP A2, #0\n\t"
		"BEQ pattern_0\n\t"
		
		"CMP A2, #1\n\t"
		"BEQ pattern_1\n\t"
		
		"CMP A2, #2\n\t"
		"BEQ pattern_2\n\t"
		
		"CMP A2, #3\n\t"
		"BEQ pattern_3\n\t"

		"CMP A2, #4\n\t"
		"BEQ pattern_4\n\t"
		
		"CMP A2, #5\n\t"
		"BEQ pattern_5\n\t"
		
		"CMP A2, #6\n\t"
		"BEQ pattern_6\n\t"
		
		"CMP A2, #7\n\t"
		"BEQ pattern_7\n\t"

		"CMP A2, #8\n\t"
		"BEQ pattern_8\n\t"
		
		"CMP A2, #9\n\t"
		"BEQ pattern_9\n\t"
		
		"CMP A2, #10\n\t"
		"BEQ pattern_A\n\t"
		
		"CMP A2, #11\n\t"
		"BEQ pattern_B\n\t"

		"CMP A2, #12\n\t"
		"BEQ pattern_C\n\t"
		
		"CMP A2, #13\n\t"
		"BEQ pattern_D\n\t"
		
		"CMP A2, #14\n\t"
		"BEQ pattern_#\n\t"
		
		"CMP A2, #15\n\t"
		"BEQ pattern_F\n\t"
		
		//branches for respective patterns
		
		"pattern_0:\n\t"
        "MOV A3, #0x3F\n\t"
        "B end_patterns\n\t"
		
		"pattern_1:\n\t"
        "MOV A3, #0x06\n\t"
        "B end_patterns\n\t"

		"pattern_2:\n\t"
        "MOV A3, #0x5B\n\t"
        "B end_patterns\n\t"
		
		"pattern_3:\n\t"
        "MOV A3, #0x4F\n\t"
        "B end_patterns\n\t"
		
		"pattern_4:\n\t"
        "MOV A3, #0x66\n\t"
        "B end_patterns\n\t"
		
		"pattern_5:\n\t"
        "MOV A3, #0x6D\n\t"
        "B end_patterns\n\t"

		"pattern_6:\n\t"
        "MOV A3, #0x7D\n\t"
        "B end_patterns\n\t"
		
		"pattern_7:\n\t"
        "MOV A3, #0x07\n\t"
        "B end_patterns\n\t"

		"pattern_8:\n\t"
        "MOV A3, #0x7F\n\t"
        "B end_patterns\n\t"
		
		"pattern_9:\n\t"
        "MOV A3, #0x6F\n\t"
        "B end_patterns\n\t"

		"pattern_A:\n\t"
        "MOV A3, #0x77\n\t"
        "B end_patterns\n\t"
		
		"pattern_B:\n\t"
        "MOV A3, #0x7C\n\t"
        "B end_patterns\n\t"
		
		"pattern_C:\n\t"
        "MOV A3, #0x39\n\t"
        "B end_patterns\n\t"
		
		"pattern_D:\n\t"
        "MOV A3, #0x5E\n\t"
        "B end_patterns\n\t"

		"pattern_E:\n\t"
        "MOV A3, #0x79\n\t"
        "B end_patterns\n\t"
		
		"pattern_F:\n\t"
        "MOV A3, #0x71\n\t"
        "B end_patterns\n\t"
		
		// End of pattern definitions
        "end_patterns:\n\t"
		"LDR A4, =HEX_MEMORY\n\t"
		
		//looping through
		"MOV A5, #0\n\t"
		"loop: \n\t"
		"CMP A5, #6\n\t"
		"BEQ end_loop\n\t"
		"MOV A6, #1\n\t"
		"LSL A6, A5\n\t"
		"TST A1, A6\n\t"
		"BEQ next\n\t"
		"STRB A3, [A4, A5]\n\t
		
		"next: \n\t"
		"ADD A5, A5, #1\n\t"
		"B loop\n\t"
		
		"end_loop: \n\t"
		:
    	:"r"(hexId), "r"(val) // input operands %0 and %1
	);
}

void HEX_clear_ASM(int hexId) {
	__asm__  __volatile__(
		// TODO
	);
}

void HEX_flood_ASM(int hexId) {
	__asm__  __volatile__(
		// TODO
		:

	);
}


int main() {
	init();
	while(1) { // infinite loop
		int switchState = read_slider_switches_ASM(); // read slider switch state
		write_LEDs_ASM(switchState); // write state to the LEDs
	}
	return 0;
}
