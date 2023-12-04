void VGA_draw_point_ASM(int x, int y, short c) {
    __asm__  __volatile__(
        "MOV R3, #0xC8000000\n\t"
		"MOV R0, %0\n\t"
		"MOV R1, %1\n\t"
		"MOV R2, %2\n\t"
		"LSL R1, R1, #10\n\t"
		"LSL R0, R0, #1\n\t"
		"ADD R1, R1, R0\n\t"
		"ADD R1, R3, R1\n\t"
		"STRH R2, [R1]\n\t"
		:    
        : "r"(x), "r"(y), "r"(c) 
    );
}

void VGA_clear_pixelbuff_ASM() {
    for (int y_coord = 0; y_coord < 240; ++y_coord) {
        for (int x_coord = 0; x_coord < 320; ++x_coord) {
            VGA_draw_point_ASM(x_coord, y_coord, 0);
        }
    }
}

void VGA_write_char_ASM(int x, int y, char c) {
	__asm__  __volatile__(
		"mov		r0, %0\n\t"
		"mov		r1, %1\n\t"
		"mov		r2, %2\n\t"
		
		"MOV R3, #0xC9000000\n\t"
		"MOV R0, %0\n\t"
		"MOV R1, %1\n\t"
		"MOV R2, %2\n\t"
		
		"LSL R1, R1, #7\n\t"
		"ADD R1, R0, R1\n\t"
		"ADD R1, R3, R1\n\t"
		
		"STRB R2, [R1]\n\t"
        :    
        :"r"(x), "r"(y), "r"(c) // input operands %0, %1, and %2
	);
}

void VGA_clear_charbuff_ASM() {
    for (int y_coord = 0; y_coord < 60; ++y_coord) {
        for (int x_coord = 0; x_coord < 80; ++x_coord) {
            VGA_write_char_ASM(x_coord, y_coord, 0);
        }
    }
}


// TODO: PS/2 driver.
int read_PS2_data_ASM(char *data) {
	int val = 0;
	__asm__  __volatile__(
		"mov        r0, %1\n\t"
		"LDR R1, =0xFF200100\n\t"
		
		"LDR R2, [R1]\n\t"
		"LSR R3, R2, #15\n\t"
		"MOV R4, #1\n\t"
		
		"TST R4, R3\n\t"
		"BNE valid\n\t"
		
		//invalid
		"MOV R0, #0\n\t"
		"B end\n\t"
		
		"valid: \n\t"
		"AND R2, R2, #0xFF\n\t"
		"STRB R2, [R0]\n\t"
		"MOV R0, #1\n\t"
		
		"end: \n\t"
		"mov        %0, r0\n\t"
		:"=r"(val) // output operands %0
		:"r"(data) // input operands %1
	);
	return val;
}


void input_loop_fun() {
	__asm__  __volatile__(
		"b 	input_loop\n\t"
		"write_hex_digit:\n\t"
		"        push    {r4, lr}\n\t"
		"        cmp     r2, #9\n\t"
		"        addhi   r2, r2, #55\n\t"
		"        addls   r2, r2, #48\n\t"
		"        and     r2, r2, #255\n\t"
		"        bl      VGA_write_char_ASM\n\t"
		"        pop     {r4, pc}\n\t"
		"write_byte:\n\t"
		"        push    {r4, r5, r6, lr}\n\t"
		"        mov     r5, r0\n\t"
		"        mov     r6, r1\n\t"
		"        mov     r4, r2\n\t"
		"        lsr     r2, r2, #4\n\t"
		"        bl      write_hex_digit\n\t"
		"        and     r2, r4, #15\n\t"
		"        mov     r1, r6\n\t"
		"        add     r0, r5, #1\n\t"
		"        bl      write_hex_digit\n\t"
		"        pop     {r4, r5, r6, pc}\n\t"
		"input_loop:\n\t"
    	"	push    {r4, r5, lr}\n\t"
    	"	sub     sp, sp, #12\n\t"
    	"	bl      VGA_clear_pixelbuff_ASM\n\t"
    	"	bl      VGA_clear_charbuff_ASM\n\t"
    	"	mov     r4, #0\n\t"
    	"	mov     r5, r4\n\t"
    	"	b       .input_loop_L9\n\t"
		".input_loop_L13:\n\t"
		"        ldrb    r2, [sp, #7]\n\t"
		"        mov     r1, r4\n\t"
		"        mov     r0, r5\n\t"
		"        bl      write_byte\n\t"
		"        add     r5, r5, #3\n\t"
		"        cmp     r5, #79\n\t"
		"        addgt   r4, r4, #1\n\t"
		"        movgt   r5, #0\n\t"
		".input_loop_L8:\n\t"
		"        cmp     r4, #59\n\t"
		"        bgt     .input_loop_L12\n\t"
		".input_loop_L9:\n\t"
		"        add     r0, sp, #7\n\t"
		"        bl      read_PS2_data_ASM\n\t"
		"        cmp     r0, #0\n\t"
		"        beq     .input_loop_L8\n\t"
		"        b       .input_loop_L13\n\t"
		".input_loop_L12:\n\t"
		"        add     sp, sp, #12\n\t"
		"        pop     {r4, r5, pc}\n\t"

	);
}

int main() {
	input_loop_fun();
	return 0;
}
