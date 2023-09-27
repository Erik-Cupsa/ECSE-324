ADD R1, R1, 0 
ADD R2, R2, 2
ADD R3, R3, 4 
ST R1, R2     
ST R3, R2     
SUB R6, R2, 1 
ADD R7, R7, 3 
ST R1, R6     
ST R7, R6     
ADD R4, R4, 6 
ST R1, R3     
ST R4, R3     
SUB R6, R3, 1 
ST R1, R6     
ST R7, R6     
ADD R5, R5, 7
ADD R5, R5, 1 
ST R1, R4     
ST R5, R4     
SUB R6, R4, 1 
ST R1, R6     
ST R7, R6     
LD R6, R2
ADD R6, R6, 0   
SUB R1, R2, 1 
LD R2, R1  
ADD R2, R2, 0
AND R0, R0, 0
ADD R0, R0, R2
LD R7, R6   
ADD R7, R7, 0  
SUB R1, R6, 1 
LD R2, R1 
ADD R2, R2, 0    
ADD R0, R0, R2
LD R3, R7
ADD R3, R3, 0     
SUB R1, R7, 1 
LD R2, R1
ADD R2, R2, 0     
ADD R0, R0, R2
EQ -1, R0, R0