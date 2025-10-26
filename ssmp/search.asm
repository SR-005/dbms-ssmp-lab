DATA SEGMENT
    ARRAY DW 1050H,2050H,3050H,5050H    ;declare the array
    LEN EQU (($-ARRAY)/2)           ;find the array length
    KEY DW 2050H        ;declare the key to be found
    STR1 DB 'KEY FOUND $'       ;string to print if found
    STR2 DB 'KEY NOT FOUND $'   ;string to print if not found
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
    START:
    MOV AX,DATA
    MOV DS,AX

    MOV SI, OFFSET ARRAY    ;Make SI Point towards the start of ARRAY, SI now has starting address of ARRAY
    MOV CX,LEN          ;move LEN of ARRAY to CX
    MOV BX,KEY          ;move KEY to BX
    FIND:   
        MOV AX,[SI]     ;move the value of array that SI is currently pointing towards to AX - initially to the start
        CMP AX,BX       ;compare the value with the KEY(BX)
        JE FOUND        ;If they are equal, value is found- Jump to FOUND
        ADD SI,2        ;If not, increment SI so it points to next value of ARRAY
        LOOP FIND       ;Loop FIND- LOOP automatically checks with LEN of ARRAY (CX) and see if the limit is exceeded or not

        ;print the not found string
        LEA DX,STR1     
        MOV AH,09H
        INT 21H
        JMP STOP    ;jump to STOP

    FOUND:
        ;print the found string
        LEA DX,STR1     
        MOV AH,09H
        INT 21H

    STOP:
        MOV AH,4CH  ;end the program
        INT 21H
CODE ENDS
END START




