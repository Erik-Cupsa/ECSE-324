// Define Mazes
int mazes[9][9][12] = {
	{	// First Obstacle Course
		{2,1,0,1,1,1,0,0,0,1,0,1},
		{0,1,0,1,1,1,0,0,0,1,0,1},
		{0,1,0,0,0,0,0,0,0,1,0,1},
		{0,1,0,1,1,1,0,0,0,1,1,1},
		{0,1,0,1,1,1,0,0,0,1,1,1},
		{0,0,0,1,1,1,0,0,0,1,1,1},
		{1,1,1,1,1,1,0,0,1,0,0,0},
		{1,1,1,1,1,1,0,1,0,0,0,0},
		{1,1,1,1,1,1,0,0,0,0,0,3}
	},
	{	// Second Obstacle Course
		{2,1,0,1,1,1,0,0,0,0,0,1},
		{0,1,0,1,1,1,0,0,0,1,0,1},
		{0,1,0,0,0,0,0,0,0,1,0,1},
		{0,1,0,1,1,1,0,0,0,1,0,1},
		{0,1,0,1,1,1,0,0,0,1,0,1},
		{0,0,0,1,1,1,0,0,0,1,0,1},
		{1,1,1,1,1,1,0,0,1,0,0,0},
		{1,1,1,1,1,1,0,1,0,0,0,0},
		{1,1,1,1,1,1,1,0,0,0,0,3}
	},
	{	// Third Obstacle Course
		{2,0,0,0,0,1,0,0,0,1,0,1},
		{0,1,1,1,0,1,1,1,0,1,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,1},
		{0,1,1,1,1,1,0,1,1,1,0,1},
		{0,1,0,0,0,0,0,0,0,1,0,1},
		{1,1,0,1,1,1,1,1,1,1,1,1},
		{0,1,0,0,0,0,0,0,0,0,0,1},
		{0,1,1,1,0,1,1,1,1,1,0,1},
		{0,0,0,0,0,0,0,1,0,0,0,3}
	},
	{	// Fourth Obstacle Course
		{2,1,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,1,1,1,0,1,1,1,0,1},
		{0,1,0,0,0,1,0,1,0,1,0,1},
		{0,1,0,1,0,1,1,1,0,1,0,1},
		{0,0,0,1,0,0,0,0,0,1,0,1},
		{0,1,0,1,1,1,1,1,1,1,0,1},
		{0,1,0,1,0,0,0,1,0,0,0,1},
		{0,1,0,1,1,1,0,1,0,1,1,1},
		{0,1,0,1,0,0,0,0,0,0,0,3}
	},
	{	// Fifth Obstacle Course
		{2,0,0,0,0,1,0,1,0,1,0,1},
		{1,1,0,1,1,1,0,1,0,1,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,1,1,0,1,1,1,1,1,0,1},
		{0,0,0,1,0,1,0,1,0,0,0,1},
		{1,1,0,1,1,1,0,1,1,1,0,1},
		{0,0,0,1,0,1,0,0,0,0,0,1},
		{0,1,0,1,0,1,0,1,0,1,1,1},
		{0,1,0,0,0,1,0,1,0,0,0,3}
	},
	{	// Sixth Obstacle Course
		{2,0,0,0,0,0,0,1,0,0,0,1},
		{1,1,0,1,0,1,0,1,0,1,0,1},
		{0,0,0,1,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,1,1,1,1,1,1},
		{0,0,0,1,0,0,0,1,0,0,0,1},
		{0,1,1,1,0,1,1,1,0,1,0,1},
		{0,1,0,0,0,0,0,0,0,1,0,1},
		{0,1,0,1,1,1,1,1,1,1,0,1},
		{0,0,0,0,0,0,0,0,0,1,0,3}
	},
	{	// Seventh Obstacle Course
		{2,0,0,0,0,0,0,0,1,0,1,0},
		{1,1,1,0,1,1,1,1,1,0,1,0},
		{1,0,0,0,0,0,1,0,0,0,0,0},
		{1,1,1,1,1,0,1,1,1,0,1,1},
		{1,0,0,0,1,0,0,0,0,0,0,0},
		{1,0,1,0,1,0,1,0,1,0,1,0},
		{1,0,1,0,0,0,1,0,1,0,1,0},
		{1,1,1,1,1,1,1,1,1,0,1,0},
		{1,0,0,0,0,0,0,0,0,0,1,3}
	},
	{	// Eighth Obstacle Course
		{2,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,1,1,1,1,1,0,1,1,1,0},
		{1,0,0,0,1,0,0,0,1,0,0,0},
		{1,1,1,1,1,0,1,1,1,1,1,1},
		{1,0,0,0,1,0,1,0,0,0,0,0},
		{1,0,1,1,1,0,1,1,1,0,1,0},
		{1,0,0,0,0,0,0,0,1,0,1,0},
		{1,1,1,0,1,0,1,1,1,1,1,0},
		{1,0,0,0,1,0,0,0,0,0,0,3}
	},
	{
		// Ninth Obstacle Course
		{2,0,0,0,0,0,1,0,1,0,1,0},
		{1,0,1,1,1,1,1,0,1,0,1,0},
		{1,0,0,0,1,0,0,0,0,0,0,0},
		{1,0,1,0,1,1,1,0,1,1,1,1},
		{1,0,1,0,1,0,1,0,0,0,1,0},
		{1,0,1,1,1,0,1,0,1,1,1,0},
		{1,0,0,0,1,0,0,0,0,0,1,0},
		{1,0,1,1,1,0,1,1,1,0,1,0},
		{1,0,0,0,0,0,1,0,0,0,0,3}
	},
};

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

void VGA_fill_ASM() {
	int bg = 0x00FF;
    for (int y_coord = 0; y_coord < 240; ++y_coord) {
        for (int x_coord = 0; x_coord < 320; ++x_coord) {
            VGA_draw_point_ASM(x_coord, y_coord, bg);
        }
    }
}

void draw_grid_ASM() {
    int gridColor = 0xFFFF; // White grid color
    int xSpacing = 26; // 320/12
    int ySpacing = 26; // 240/9
    int yMax = 234; // 26 * 9
    int xMax = 312; // 26 * 12

    for (int y = 0; y <= yMax; y += ySpacing) {
        for (int x = 0; x < xMax; ++x) {
            VGA_draw_point_ASM(x, y, gridColor);
        }
    }

    for (int x = 0; x <= xMax; x += xSpacing) {
        for (int y = 0; y < yMax; ++y) {
            VGA_draw_point_ASM(x, y, gridColor);
        }
    }
}

void draw_ampersand_ASM(int x, int y) {
    double adjustedX = x * 80 / 12; // adjusting x to fit dimensions
	adjustedX += 3 + 1/3;
    double adjustedY = y * 60 / 9; // adjusting y to fit dimensions
	adjustedY += 3 + 1/3;
    
	//drawing
    VGA_write_char_ASM(adjustedX, adjustedY, '&');
}

int main() {
	VGA_fill_ASM();
	draw_grid_ASM();
	draw_ampersand_ASM(1,4);
	return 0;
}
