.ORIG x3000

LD R2, STRSTART

LDR R0, R2, #0
AND R1, R1, #0
ADD R1, R1, #3
JSR BITSWAP
ADD R6, R0, #0
LD R2, GRADEMASK_ONE
AND R3, R6, R2
LD R2, GRADEMASK_TWO
AND R4, R6, R2
LD R2, GRADEMASK_THREE
AND R5, R6, R2
HALT
GRADEMASK_ONE 
.FILL x0018
GRADEMASK_TWO
.FILL x0007
GRADEMASK_THREE
.FILL x00E0
