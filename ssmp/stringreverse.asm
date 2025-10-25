DATA SEGMENT
    STRING1 DB "HELLO$"             ;Target String
    MSG1 DB "REVERSED STRING IS: $"     ;Default Printing Message
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX

    XOR SI,SI   ;Clear the SI Pointer
    MOV SI, OFFSET STRING1  ;Make SI Point to the Starting of STRING1

    FINDEND:
        MOV AL,[SI]     ;Move the Value at the Address in SI into AL
        CMP AL, "$"     ;Check if the current value is '$'-termination symbol
        JE GOTEND       ;If yes, then jump to GOTEND
        INC SI          ;If not, then Increment SI i.e, make SI point to next Character in STRING1
        JNZ FINDEND     ;Loop this process

    GOTEND:
        DEC SI          ;Decrement SI, because we do need to count '$' towards total lenght of the string
        REVERSE:
            MOV DL,[SI]     ;Since SI is now at the end of string, move the current word to DL

            ;Print the Word
            MOV AH,02H      
            INT 21H

            DEC SI      ;Decrement SI so it can point to the next word - in reverse
            CMP SI,OFFSET STRING1-1 ;Check if the pointer SI is past the starting address of STRING1
            JNE REVERSE     ;If not, then repeat

            MOV AX,4C00H    ;End the program
            INT 21H
CODE ENDS
END START