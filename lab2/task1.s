.global _start

_start:
	MOV R0, #0 //result
	MOV R1, #0 //sign
	LDR R2, =multiplier
	LDR R3, [R2] //multiplier
	LDR R4, =multiplicand
	LDR R5, [R4] //multiplicand
	
	CMP R3, #0
	BGE check_multiplicand
	
	EOR R1, R1, #1
	NEG R3, R3

check_multiplicand: 
	CMP R5, #0
	BGE operation
	
	EOR R1, R1, #1
	NEG R5, R5

operation: 
	CMP R5, #0
	BEQ sign_check
	
	AND R6, R5, #1
	CMP R6, #1
	BNE shift
	ADD R0, R0, R3

shift: 
	LSL R3, #1
	LSR R5, #1
	B operation
	

sign_check: 
	CMP R1, #0
	BEQ end
	NEG R0, R0

end:
    B end
	
// Load multiplier from a label named multiplier
// Load multiplicand from a label named multiplicand
// Put the result of the multiplication inside R0