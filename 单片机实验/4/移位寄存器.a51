ORG 0000H
    AJMP MAIN
ORG 0023H
    AJMP OPERATION 
ORG 0030H
MAIN: ; 串口初始化
    SETB ES        
    SETB EA       
    MOV A, #0FEH
    MOV SCON,#00H 
    MOV SBUF,A     
    AJMP $

OPERATION: ; 左移数值，并发送给串口 
    LCALL DELAY
    CLR TI      
    RL A      
    MOV SBUF,A 
    RETI
	 
DELAY: ; 延迟函数
    MOV R0 , #100
    L1:
    MOV R1 , #50
    L2:
    MOV R2 , #50
    DJNZ R2 , $
    DJNZ R1 , L2
    DJNZ R0 , L1
    RET
END