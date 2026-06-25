ORG 0000H
AJMP MAIN
ORG 0030H
GIVE:
    CLR P3.1
    SETB P3.1
    CLR P3.1
    RET
CLEAR:
    SETB P3.0
    MOV R4,#8
    J1:
    ACALL GIVE
    DJNZ R4,J1
    RET

SETLED:
    ACALL CLEAR
    CLR P3.0
    ACALL GIVE
    SETB P3.0
    MOV A , R7
    MOV R5 , A
    CJNE R5 , #0 , J2
    RET 
    J2:
    ACALL GIVE
    DJNZ R5,J2 
    RET

MAIN:
    MOV R7, #7
    J3:
    ACALL SETLED
    ACALL DELAY
    DJNZ R7 , J3 
    ACALL SETLED
    ACALL DELAY
    AJMP MAIN
DELAY:
	MOV R0 , #0FFH
	LP:
	MOV R1 , #0FFH
	DJNZ R1 , $
	DJNZ R0 , LP
	RET
END	