
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

// testbench
void draw_test_screen() {
	__asm__  __volatile__(
	"push    {r4, r5, r6, r7, r8, r9, r10, lr}\n\t"
    "bl      VGA_clear_pixelbuff_ASM\n\t"
    "bl      VGA_clear_charbuff_ASM\n\t"
    "mov     r6, #0\n\t"
    "ldr     r10, .draw_test_screen_L8\n\t"
    "ldr     r9, .draw_test_screen_L8+4\n\t"
    "ldr     r8, .draw_test_screen_L8+8\n\t"
    "b       .draw_test_screen_L2\n\t"
	".draw_test_screen_L7:\n\t"
	"        add     r6, r6, #1\n\t"
	"        cmp     r6, #320\n\t"
	"        beq     .draw_test_screen_L4\n\t"
	".draw_test_screen_L2:\n\t"
	"        smull   r3, r7, r10, r6\n\t"
	"        asr     r3, r6, #31\n\t"
	"        rsb     r7, r3, r7, asr #2\n\t"
	"        lsl     r7, r7, #5\n\t"
	"        lsl     r5, r6, #5\n\t"
	"        mov     r4, #0\n\t"
	".draw_test_screen_L3:\n\t"
	"        smull   r3, r2, r9, r5\n\t"
	"        add     r3, r2, r5\n\t"
	"        asr     r2, r5, #31\n\t"
	"        rsb     r2, r2, r3, asr #9\n\t"
	"        orr     r2, r7, r2, lsl #11\n\t"
	"        lsl     r3, r4, #5\n\t"
	"        smull   r0, r1, r8, r3\n\t"
	"        add     r1, r1, r3\n\t"
	"        asr     r3, r3, #31\n\t"
	"        rsb     r3, r3, r1, asr #7\n\t"
	"        orr     r2, r2, r3\n\t"
	"        mov     r1, r4\n\t"
	"        mov     r0, r6\n\t"
	"        bl      VGA_draw_point_ASM\n\t"
	"        add     r4, r4, #1\n\t"
	"        add     r5, r5, #32\n\t"
	"        cmp     r4, #240\n\t"
	"        bne     .draw_test_screen_L3\n\t"
	"        b       .draw_test_screen_L7\n\t"
	".draw_test_screen_L4:\n\t"
	"        mov     r2, #72\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #20\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #101\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #21\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #108\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #22\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #108\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #23\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #111\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #24\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #32\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #25\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #87\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #26\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #111\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #27\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #114\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #28\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #108\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #29\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #100\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #30\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"        mov     r2, #33\n\t"
	"        mov     r1, #5\n\t"
	"        mov     r0, #31\n\t"
	"        bl      VGA_write_char_ASM\n\t"
	"		pop     {r4, r5, r6, r7, r8, r9, r10, pc}\n\t"
	".draw_test_screen_L8:\n\t"
	"        .word   1717986919\n\t"
	"        .word   -368140053\n\t"
	"        .word   -2004318071\n\t"
	);
}

int main() {
	draw_test_screen();
	return 0;
}