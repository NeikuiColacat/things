ORG 0000H
AJMP MAIN
ORG 0023H
AJMP GIVE 
ORG 0030H
MAIN:
    ;初始化设置串口波特率以及发送模式，打开中断
    MOV TMOD,#20H   
    MOV TH1,#0FDH   
    MOV TL1,#0FDH  
    MOV SCON,#40H      
    MOV PCON,#00H
    MOV P1,#0FFH
    SETB TR1      
    SETB ES
    SETB EA
    
    ;开始发送
    MOV SBUF,P1
    AJMP $

    ;串口中断
GIVE: 
    CLR TI
    MOV SBUF,P1
	RETI
End