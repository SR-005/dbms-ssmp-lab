DATA SEGMENT
    N1 DW 07H
    MSG1 DB "PRIME NUMBER$"
    MSG2 DB "NOT A PRIME NUMBER$"
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX

    MOV CX,N1   ;Move the Number to CX
    DEC CX      ;Decrement CX, it will be used as a checking limit
    MOV BX,02H  ;start checking divisibility with 2

    PRIMEORNOT:
        CMP BX,CX   ;Compare the Divisor the and Number(N-1). 
        JGE PRIME   ;If it s Greater than or equal to, then the number is a prime number

        MOV DX,0        ;Clear the remainder
        MOV AX,N1       ;Move the original value to AX
        DIV BX          ;Divide AX and BX, result will be strored in DX
        CMP DX,0        ;Check if the remainder is 0 i.e, the number is divisible
        JE NOTPRIME     ;if it is, then it is Not a Prime Number

        INC BX          ;Increment BX and check Divisibility with the next number
        JMP PRIMEORNOT
    
    PRIME:
        ;Print 'PRIME' message
        MOV AH,09H
        LEA DX,MSG1
        INT 21H
        JMP STOP    ;Jump to stop
    NOTPRIME:
        ;Print 'NOT PRIME' message
        MOV AH,09H
        LEA DX,MSG2
        INT 21H
    STOP:
        MOV AX,4C00H
        INT 21H
CODE ENDS
END START
        