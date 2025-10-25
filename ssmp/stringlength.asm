DATA SEGMENT
    MSG1 DB "STRING LENGTH IS: $"   ;Default Printing Statement
    STRING1 DB "HELLOWORLD$"        ;String to be computed
    LEN DB 0                        ;Length Variable
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX

    XOR CL,CL           ;Clear the CL Register to Calculate the Length
    XOR SI,SI           ;Clear the SI Pointer
    MOV SI, OFFSET STRING1  ;Move the SI Pointer so that it points to the starting of STRING1
    CLD                 ;Reset the Direction

    ITERATE:
        LODSB           ;Loads the Value at the address found in SI into AX, and auto increments SI
        INC CL          ;Increment CL for each value being read
        CMP AX,"$"      ;Checks if the value being read is '$'-Termination Character
        JNZ ITERATE     ;If not, then repeat the Loop until it occurs

        DEC CL          ;If the value in '$', Decrement the CL (Length Count), because we do not need the count of '$' to be included
        MOV LEN,CL      ;Move the total count to LEN Variable

        ;Default Printing Section - Prints MSG1
        MOV AH,09H      ;09H for Printing Strings
        LEA DX,MSG1     ;LEA makes DX Point to the Starting of MSG1 and goes until '$' occurs
        INT 21H

        MOV AL,LEN      ;Move the Final Count to AL for ASCII Convertion
        MOV AL,09H      ;ASCII Convertion Occurs

        ;Default Printing Section - Prints the Final Length
        MOV AH,02H      ;02H for Printing Numbers
        MOV DL,AL       ;Moves the Printable value to DL
        INT 21H

        MOV AX,4C00H    ;Ending the Program
        INT 21H
CODE ENDS
END START