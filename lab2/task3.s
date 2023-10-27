lucas: 
	PUSH {R4, R5, R6, LR}
	MOV R4, R0
	CMP R4, #0 // base case 0
	BNE _elif
	MOV R0, #2
	B _end
	
_elif: 
	CMP R4, #1
	BNE _else
	MOV R0, #1
	B _end

_else: 
	SUB R0, R4, #2
	BL lucas
	MOV R5, R0
	MOV R0, R4 
	SUB R0, R0, #1
	BL lucas
	MOV R6, R0
	
	ADD R0, R5, R6
_end: 
	POP {R4, R5, R6, LR}
	BX LR