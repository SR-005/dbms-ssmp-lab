DATA SEGMENT
N1 DW 1212H     ;First Number Variable
N2 DW 1212H     ;Second Number Variable
N3 DW 0000H     ;Result Variable
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    XOR CX,CX   ;Clear Carry Register
    MOV AX,N1   ;Move first number to AX Register
    MOV BX,N2   ;Move second number to AX Register
    ADD AX,BX   ;Add value's in both AX and BX Registers
    JNC STOP    ;if to STOP(final part of program) if no carry (JNC-Jump No Carry)
    INC CX      ;if carry then Increment CX
STOP:
MOV N3,AX   ;move the result from AX Register to N3
INT 3H  ;End the Program
CODE ENDS
END START