DATA SEGMENT
L1 DD 21212121H, 21212121H  ;Initialize two numbers
N3 DW 0000H ;Result Variable 1
N4 DW 0000H ;Result Variable 2
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    XOR CX,CX ;Clear the Carry Register
    XOR SI,SI  ;Clear the Pointer
    MOV SI, OFFSET L1 ;Make the SI Point to the Start of L1(Numbers to be added) S1->starting address of L1

    MOV AX,[SI] ;take the values to which SI is pointing towards(Second Part of First Number) and move it to AX
    SUB AX,[SI+4] ;subtract contents of AX with the values to which SI+4 is pointing towards (Second Part of Second Number)
    MOV N3,AX ; Store the result in N3

    MOV AX,[SI+2] ;take the values to which SI+2 is pointing towards(First Part of First Number) and move it to AX
    SBB AX,[SI+6] ;subtract contents of AX with the values to which SI+4 is pointing towards (First Part of Second Number) -SBB Subtract with Borrow
    MOV N4,AX ; Store the result in N4

    JNC STOP    ;if to STOP(final part of program) if no carry/borrow (JNC-Jump No Carry)
    INC CX

STOP:
    INT 3H
CODE ENDS
END START

