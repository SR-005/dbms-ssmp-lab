DATA SEGMENT
N1 DW 0000H     ;First Number Variable
N2 DW 0000H     ;Second Number Variable
N3 DW 0000H     ;Result Variable
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    XOR CX,CX   ;Clear the Borrow Register
    MOV AX,N1   ;Move First Number to AX
    MOV BX,N2   ;Move Second Number to BX
    SUB AX,BX   ;Subtract and store value in AX
    JNC STOP    ;if to STOP(final part of program) if no carry/borrow (JNC-Jump No Carry)
    INC CX      ;if carry/borrow, increment CX  
STOP:
    MOV N3,AX   ;Move Result to N3
    INT 3
CODE ENDS
END START