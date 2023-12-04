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

int currX = 0;
int currY = 0;
char *keyPressed = 0;
int prevKey = -1;

void draw_win() {
	__asm__  __volatile__(
    "push    {r4, r5, r6, r7, r8, r9, r10, lr}\n\t"
    "bl      VGA_clear_pixelbuff_ASM\n\t"
    "bl      VGA_clear_charbuff_ASM\n\t"
    "mov     r6, #0\n\t"
    "ldr     r10, .draw_test_screenz_L8\n\t"
    "ldr     r9, .draw_test_screenz_L8+4\n\t"
    "ldr     r8, .draw_test_screenz_L8+8\n\t"
    "b       .draw_test_screenz_L2\n\t"
    ".draw_test_screenz_L7:\n\t"
    "        add     r6, r6, #1\n\t"
    "        cmp     r6, #320\n\t"
    "        beq     .draw_test_screenz_L4\n\t"
	".draw_test_screenz_L2:\n\t"
	"        smull   r3, r7, r10, r6\n\t"
	"        asr     r3, r6, #31\n\t"
	"        rsb     r7, r3, r7, asr #2\n\t"
	"        lsl     r7, r7, #5\n\t"
	"        lsl     r5, r6, #5\n\t"
	"        mov     r4, #0\n\t"
	".draw_test_screenz_L3:\n\t"
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
	"        bne     .draw_test_screenz_L3\n\t"
	"        b       .draw_test_screenz_L7\n\t"
	".draw_test_screenz_L4:\n\t"
	// Writing "You Win"
	"mov r2, #67\n\t" // 'C'
	"mov r1, #5\n\t"
	"mov r0, #20\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #79\n\t" // 'O'
	"mov r1, #5\n\t"
	"mov r0, #21\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #78\n\t" // 'N'
	"mov r1, #5\n\t"
	"mov r0, #22\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #71\n\t" // 'G'
	"mov r1, #5\n\t"
	"mov r0, #23\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #82\n\t" // 'R'
	"mov r1, #5\n\t"
	"mov r0, #24\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #65\n\t" // 'A'
	"mov r1, #5\n\t"
	"mov r0, #25\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #84\n\t" // 'T'
	"mov r1, #5\n\t"
	"mov r0, #26\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #85\n\t" // 'U'
	"mov r1, #5\n\t"
	"mov r0, #27\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #76\n\t" // 'L'
	"mov r1, #5\n\t"
	"mov r0, #28\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #65\n\t" // 'A'
	"mov r1, #5\n\t"
	"mov r0, #29\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #84\n\t" // 'T'
	"mov r1, #5\n\t"
	"mov r0, #30\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #73\n\t" // 'I'
	"mov r1, #5\n\t"
	"mov r0, #31\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #79\n\t" // 'O'
	"mov r1, #5\n\t"
	"mov r0, #32\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #78\n\t" // 'N'
	"mov r1, #5\n\t"
	"mov r0, #33\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #83\n\t" // 'S'
	"mov r1, #5\n\t"
	"mov r0, #34\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #33\n\t" // '!' (exclamation mark)
	"mov r1, #5\n\t"
	"mov r0, #35\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #32\n\t" // ' ' (space)
	"mov r1, #5\n\t"
	"mov r0, #36\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #89\n\t" // 'Y'
	"mov r1, #5\n\t"
	"mov r0, #37\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #111\n\t" // 'o'
	"mov r1, #5\n\t"
	"mov r0, #38\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #117\n\t" // 'u'
	"mov r1, #5\n\t"
	"mov r0, #39\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #32\n\t" // ' ' (space)
	"mov r1, #5\n\t"
	"mov r0, #40\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #87\n\t" // 'W'
	"mov r1, #5\n\t"
	"mov r0, #41\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #111\n\t" // 'o'
	"mov r1, #5\n\t"
	"mov r0, #42\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #110\n\t" // 'n'
	"mov r1, #5\n\t"
	"mov r0, #43\n\t"
	"bl VGA_write_char_ASM\n\t"

	"mov r2, #33\n\t" // '!' (exclamation mark)
	"mov r1, #5\n\t"
	"mov r0, #44\n\t"
	"bl VGA_write_char_ASM\n\t"
    "pop     {r4, r5, r6, r7, r8, r9, r10, pc}\n\t"
    ".draw_test_screenz_L8:\n\t"
    "        .word   1717986919\n\t"
    "        .word   -368140053\n\t"
    "        .word   -2004318071\n\t"
    );
}

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
	currX = x;
	currY = y;
}

void clear_ampersand_ASM(int x, int y) {
    double adjustedX = x * 80 / 12; // adjusting x to fit dimensions
	adjustedX += 3 + 1/3;
    double adjustedY = y * 60 / 9; // adjusting y to fit dimensions
	adjustedY += 3 + 1/3;
    
	//drawing
    VGA_write_char_ASM(adjustedX, adjustedY, ' ');
}

void draw_exit_ASM(int x, int y) {
    double adjStartX = x * 80 / 12; // adjusting x to fit dimensions
    double adjStartY = y * 60 / 9; // adjusting y to fit dimensions
	adjStartY += 2;
    
	const char* word = "EXIT"; // Define the word "EXIT"
	for (int i = 0; i < 4; ++i) {
		char letter = word[i];
		VGA_write_char_ASM(adjStartX + i, adjStartY, letter);
	}
}

void draw_obstacles_ASM(int x, int y) {
	int obstacleColour = 0xF800;
	int obstacleSize = 26; //note: same width/height
	int startY = y*obstacleSize;
	int startX = x*obstacleSize;
	
	for (int i = startY; i < startY + obstacleSize; ++i){
		for (int j = startX; j < startX + obstacleSize; ++j){
			VGA_draw_point_ASM(j, i, obstacleColour);
		}
	}
}

void fill_grid_ASM(int numCourse){
	//int maze = mazes[numCourse];
	for (int y = 0; y < 9; ++y) {
		for (int x = 0; x < 12; ++x) {
			int element = mazes[numCourse][y][x];
			if(element == 0){
				continue;
			}
			else if(element == 1){
				draw_obstacles_ASM(x, y);
			}
			else if(element == 2){
				draw_ampersand_ASM(x, y);
			}
			else if(element == 3){
				draw_exit_ASM(x, y);
			}
		}
	}
}

void move_ASM(int courseNumber){
	if(read_PS2_data_ASM(keyPressed)){
		if(*keyPressed == 0xe0){
			int valid = read_PS2_data_ASM(keyPressed);
			while (valid == 0) {
				valid =  read_PS2_data_ASM(keyPressed);
			}
			if (*keyPressed == 0x75){ //up arrow
				int movedY = currY - 1;
				if(movedY >= 0 && mazes[courseNumber][movedY][currX] != 1){
					clear_ampersand_ASM(currX, currY);
					currY = movedY;
				}
			}
			else if(*keyPressed == 0x72){ // down arrow
				int movedY = currY + 1;
				if(movedY <= 8 && mazes[courseNumber][movedY][currX] != 1){
					clear_ampersand_ASM(currX, currY);
					currY = movedY;
				}
			}
			else if(*keyPressed == 0x6B){ // left arrow
				int movedX = currX - 1;
				if(movedX >= 0 && mazes[courseNumber][currY][movedX] != 1){
					clear_ampersand_ASM(currX, currY);
					currX = movedX;
				}
			}
			else if(*keyPressed == 0x74){ // down arrow
				int movedX = currX + 1;
				if(movedX <= 11 && mazes[courseNumber][currY][movedX] != 1){
					clear_ampersand_ASM(currX, currY);
					currX = movedX;
				}
			}
			draw_ampersand_ASM(currX, currY);
		}
	}
}

void result_ASM(int result){
	if(result == 1){
		draw_win();
	}
}

int get_PS2_key() {
    if (read_PS2_data_ASM(keyPressed)) {
		if (*keyPressed == 0x16){
			prevKey = 0;
		}
		else if(*keyPressed == 0x1E){
			prevKey = 1;
		}
		else if (*keyPressed == 0x26){
			prevKey = 2;
		}
		else if(*keyPressed == 0x25){
			prevKey = 3;
		}
		else if(*keyPressed == 0x2E){
			prevKey = 4;
		}
		else if (*keyPressed == 0x36){
			prevKey = 5;
		}
		else if(*keyPressed == 0x3D){
			prevKey = 6;
		}
		else if (*keyPressed == 0x3E){
			prevKey = 7;
		}
		else if(*keyPressed == 0x46){
			prevKey = 8;
		}
    }
    return prevKey;
}

int main() {
	VGA_fill_ASM();
	draw_grid_ASM();
	VGA_clear_charbuff_ASM();
	
    int mazeNum = get_PS2_key();
    while(mazeNum < 0 || mazeNum > 8) {
        mazeNum = get_PS2_key();
    }

    fill_grid_ASM(mazeNum);
	prevKey = -1;
	
	while(1){
		if(currX == 11 && currY == 8){
			result_ASM(1);
			break;
		}
		else{
			move_ASM(mazeNum);
		}
	}
	//draw_ampersand_ASM(6,2);
	//draw_exit_ASM(10,8);
	//draw_obstacles_ASM(0,5);
	int time = 0;
	int clockVal = 17045455; //experimental value for 10 seconds
	while (time < clockVal){
		time += 1;
	}
	main();
	return 0;
}
