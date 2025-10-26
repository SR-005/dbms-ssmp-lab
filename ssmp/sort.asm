
CODE SEGMENT
ASSUME CS:CODE
START:
    XOR SI,SI
    MOV SI,2000H

    MOV CL,[SI]
    DEC CL

    OUTERLOOP:
        MOV SI,3000H
        MOV CH,CL

    INNERLOOP:
        MOV AL,[SI]
        CMP AL,[SI+1]
        JLE SKIPSWAP
        XCHG AL,[SI+1]
        MOV [SI],AL

    SKIPSWAP:
        INC SI
        DEC CH
        JNZ INNERLOOP

        DEC CL
        JNZ OUTERLOOP

        INT 3H
CODE ENDS
END START
