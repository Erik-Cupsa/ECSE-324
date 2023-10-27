sobel:
    PUSH {R4-R11, LR}
	SUB R3, R2, #1 //size - 1 value
	MOV R4, #0 // j value
	
j_loop: 
	ADD R4, R4, #1
	CMP R4, R3
	BGE _end
	MOV R5, #0 //i value

i_loop: 
	ADD R5, R5, #1
	CMP R5, R3
	BGE j_loop
	LSL R6, R4,#2 // j * 4 value
	LSL R7, R5,#2 // i * 4 value
	MLA R8, R6, R2, R7
	ADD R8, R8, R0 //(i,j)
	MOV R9, #0
	
	SUB R10, R8, #4
	LDR R10, [R10]
	LSL R10, R10, #1
	ADD R9, R9, R10
	
	ADD R10, R8, #4
	LDR R10, [R10]
	LSL R10, R10, #1
	SUB R9, R9, R10
	
	LSL R10, R2, #2
	SUB R10, R8, R10
	SUB R10, R10, #4
	LDR R10, [R10]
	ADD R9, R9, R10
	
	LSL R10, R2, #2
	SUB R10, R8, R10
	ADD R10, R10, #4
	LDR R10, [R10]
	SUB R9, R9, R10
	
	LSL R10, R2, #2
	ADD R10, R8, R10
	SUB R10, R10, #4
	LDR R10, [R10]
	ADD R9, R9, R10
	
	LSL R10, R2, #2
	ADD R10, R8, R10
	ADD R10, R10, #4
	LDR R10, [R10]
	SUB R9, R9, R10
	
	STR R9, [R1]
	ADD R1, R1, #4
	B i_loop
	

_end: 
	POP {R4-R11, LR}
	BX LR