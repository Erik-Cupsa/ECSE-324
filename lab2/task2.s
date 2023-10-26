.global _start
	
_start:
	LDR R0, =array
	LDR R1, =size
	LDR R2, [R1] //size
	MOV R3, #-1 //step
	SUB R4, R2, #1 //comparison value for first loop
	
first_loop: 
	ADD R3, R3, #1
	CMP R3, R4
	BGE end
	MOV R5, #-1 //i
	
second_loop: 
	ADD R5, R5, #1
	SUB R6, R2, R3
	SUB R6, R6, #1 //r2-r3-1
	CMP R5, R6
	BGE first_loop
	LDR R7, [R0, R5, LSL #2]
	ADD R8, R5, #1
	LDR R9, [R0, R8, LSL #2]
	CMP R7, R9
	BLT second_loop
	STR R9, [R0, R5, LSL #2]
	STR R7, [R0, R8, LSL #2]
	B second_loop
end:
    B end