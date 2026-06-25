# note

## 寄存器

R0-R12 为通用寄存器
R13 MSP 主堆栈指针 进程堆栈指针PSP ， 都叫R13

栈分为 ： 满递减(向下生长) 满递增

R15 程序计数器 计数器先加，再执行操作
![picture 0](/images/6f1674ac11c98e8f306e217a7252e6487f4edef73c8bb914264b32cca140e0bb.png)  

![picture 1](/images/07cc3281062a18b95c759a6684ff0d4509d9d27d66e1cd7bf7212d403482a313.png)  

![picture 2](/images/d97b48ad52416b2d256f9b30962364667507f3900c4c6d8327786a737dffb659.png)  

![picture 3](/images/ad3aee57d04750b4ffc8e25e5d229bad5a85970f02022eed0ba593873ce4db3a.png)  

只有在特权级下，才允许使用MRS/MSR指令访问PRIMASK、FAULTMASK，以及BASEPRI。
![picture 4](/images/bb97aa9efff6363819ac9c9eb670da3aaac6aeff61eb050ec959bf065e06ee6d.png)  

## 三个模式

![picture 5](/images/5c82abdbcbb57e0118f2a183520ed6901c71853ff5dc88edbce5904020359f2e.png)  

## 大小端

![picture 6](/images/80b4d26b61c8875c0f6b093102a1cb6fd8ccf0b4e19bd5ba2c0ebff90141f474.png)  

## 位带

0X40000000~0X40100000
0X42000000~0X43FFFFFF
0X20000000~X20100000
0X22000000~0X23FFFFFF
![picture 7](/images/6bdae6e0add38d7865ff5ae5f64adba1e1f79d29c03d4589647860f802a8ee67.png)  

## 中断

![picture 8](/images/78d133717440acdb28107ec1ec4588beb4a4bdfe81ae60ce87dee725afb71d54.png)  

三种合法状态

![picture 0](/images/46693b0892c3a2fc6ccb10281cb9b59dbc00218cbadb2683785edd3dc8b696fa.png)  

## 中断设置过程

![picture 1](/images/747999118163fc793e3199987ee6735df2f5f217a53d3fe342f7d6976195e048.png)  

## 汇编

0b11101 0b11110 0b11111 为32位指令
仅有IA DB 两种操作，即之前加，之后减