void init() {
	__asm__(
		".equ SW_MEMORY, 0xFF200040\n\t"
		".equ LED_MEMORY, 0xFF200000\n\t"
		".equ HEX_MEMORY, 0xFF200020\n\t"
		".equ P_MEMORY, 0xFF200050\n\t"
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
		// TODO
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
