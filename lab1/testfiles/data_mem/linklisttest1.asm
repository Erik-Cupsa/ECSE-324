ADD R1, R1, 0 # RZ_out: 0; Reg stores value 0
ADD R2, R2, 1 # RZ_out: 1; Reg stores the current address to be written
ADD R3, R3, 3 # RZ_out: 3; Reg stores the next address
ST R1, R2     # RZ_out: 1; Mem[R2] <- R1 clear memory cell
ST R3, R2     # RZ_out: 1; Mem[R2] <- R3
SUB R6, R2, 1 # RZ_out: 0; Get address for value
ADD R7, R7, 1 # RZ_out: 1; Value to be stored
ST R1, R6     # RZ_out: 0; Mem[R2 - 1] <- R1 clear memory
ST R7, R6     # RZ_out: 0; Mem[R2 - 1] <- R7
ADD R4, R4, 5 # RZ_out: 5; Reg stores the next address
ST R1, R3     # RZ_out: 3; Mem[R3] <- R1 clear memory cell
ST R4, R3     # RZ_out: 3; Mem[R3] <- R4
SUB R6, R3, 1 # RZ_out: 2; Get address for value
ST R1, R6     # RZ_out: 2; Mem[R3 - 1] <- R1 clear memory cell 
ST R7, R6     # RZ_out: 2; Mem[R3 - 1] <- R7
ADD R5, R5, 7 # RZ_out: 7; Reg stores the next address
ST R1, R4     # RZ_out: 5; Mem[R4] <- R1 clear memory cell
ST R5, R4     # RZ_out: 5; Mem[R4] <- R5
SUB R6, R4, 1 # RZ_out: 4; Get address for value
ST R1, R6     # RZ_out: 4; Mem[R4 - 1] <- R1 clear memory cell
ST R7, R6     # RZ_out: 4; Mem[R4 - 1] <- R7 

LD R6, R2     # RZ_out: 1; Load the first address from ground truth
ADD R6, R6, 0 # RZ_out: 3; Check landed value
SUB R1, R2, 1 # RZ_out: 0; Get value address
LD R2, R1     # RZ_out: 0; Load value
ADD R2, R2, 0 # RZ_out: 1; Check loaded value
AND R0, R0, 0 # RZ_out: 0; Initialize accumulator register
ADD R0, R0, R2# RZ_out: 1; Accumulate value

LD R7, R6     # RZ_out: 3; Load the second address from the first address of the link list
ADD R7, R7, 0 # RZ_out: 5; Check loaded value
SUB R1, R6, 1 # RZ_out: 2; Get value address
LD R2, R1     # RZ_out: 2; Load value
ADD R2, R2, 0 # RZ_out: 1; Check loaded value
ADD R0, R0, R2# RZ_out: 2; Accumulate value

LD R3, R7     # RZ_out: 5; Load the third address from the second address of the link list
ADD R3, R3, 0 # RZ_out: 7; Check loaded value
SUB R1, R7, 1 # RZ_out: 4; Get value address
LD R2, R1     # RZ_out: 4; Load value
ADD R2, R2, 0 # RZ_out: 1; Check loaded value
ADD R0, R0, R2# RZ_out: 3; Accumulate value

EQ -1, R0, R0 #            Indicator for the end of simulation