#include "includes.h"       // UC/OS-II 头文件
#include "stm32f10x.h"      // STM32F1 头文件
#include "delay.h"
#include "usart.h"

#define TASK_STK_SIZE 128

OS_STK Task1Read_Stk[TASK_STK_SIZE];
OS_STK Task2Read_Stk[TASK_STK_SIZE];
OS_STK Task3Read_Stk[TASK_STK_SIZE];
OS_STK Task4Write_Stk[TASK_STK_SIZE];

#define READER1_PRIO 11
#define READER2_PRIO 12
#define READER3_PRIO 13
#define WRITER_PRIO  14

OS_EVENT *r_sem;   // 读者信号量
OS_EVENT *w_sem;   // 写者信号量
INT8U read_count = 0;

void Task1_read(void *pdata)
{
    INT8U err;
    while(1)
    {
        printf("Reader 1 ready to read data\r\n");
        OSSemPend(r_sem, 0, &err);
        read_count++;
        printf("Reader 1 acquired reader semaphore, current reader count: %d\r\n", read_count);
        if(read_count == 1)
        {
            printf("Reader 1 is the first reader, requesting writer semaphore\r\n");
            OSSemPend(w_sem, 0, &err);
        }
        OSSemPost(r_sem);

        printf("Reader 1 is reading data...\r\n");
        OSTimeDlyHMSM(0, 0, 1, 0);

        OSSemPend(r_sem, 0, &err);
        read_count--;
        printf("Reader 1 finished reading, current reader count: %d\r\n", read_count);
        if(read_count == 0)
        {
            printf("Reader 1 is the last reader, releasing writer semaphore\r\n");
            OSSemPost(w_sem);
        }
        OSSemPost(r_sem);

        OSTimeDlyHMSM(0, 0, 2, 0); // 读后间隔
    }
}

void Task2_read(void *pdata)
{
    INT8U err;
    while(1)
    {
        printf("Reader 2 ready to read data\r\n");
        OSSemPend(r_sem, 0, &err);
        read_count++;
        printf("Reader 2 acquired reader semaphore, current reader count: %d\r\n", read_count);
        if(read_count == 1)
        {
            printf("Reader 2 is the first reader, requesting writer semaphore\r\n");
            OSSemPend(w_sem, 0, &err);
        }
        OSSemPost(r_sem);

        printf("Reader 2 is reading data...\r\n");
        OSTimeDlyHMSM(0, 0, 1, 0);

        OSSemPend(r_sem, 0, &err);
        read_count--;
        printf("Reader 2 finished reading, current reader count: %d\r\n", read_count);
        if(read_count == 0)
        {
            printf("Reader 2 is the last reader, releasing writer semaphore\r\n");
            OSSemPost(w_sem);
        }
        OSSemPost(r_sem);

        OSTimeDlyHMSM(0, 0, 2, 0); // 读后间隔
    }
}

void Task3_read(void *pdata)
{
    INT8U err;
    while(1)
    {
        printf("Reader 3 ready to read data\r\n");
        OSSemPend(r_sem, 0, &err);
        read_count++;
        printf("Reader 3 acquired reader semaphore, current reader count: %d\r\n", read_count);
        if(read_count == 1)
        {
            printf("Reader 3 is the first reader, requesting writer semaphore\r\n");
            OSSemPend(w_sem, 0, &err);
        }
        OSSemPost(r_sem);

        printf("Reader 3 is reading data...\r\n");
        OSTimeDlyHMSM(0, 0, 1, 0);

        OSSemPend(r_sem, 0, &err);
        read_count--;
        printf("Reader 3 finished reading, current reader count: %d\r\n", read_count);
        if(read_count == 0)
        {
            printf("Reader 3 is the last reader, releasing writer semaphore\r\n");
            OSSemPost(w_sem);
        }
        OSSemPost(r_sem);

        OSTimeDlyHMSM(0, 0, 2, 0); // 读后间隔
    }
}

void Task4_write(void *pdata)
{
    INT8U err;
    while(1)
    {
        printf("Writer ready to write data\r\n");
        OSSemPend(w_sem, 0, &err);
        OSSemPend(r_sem, 0, &err);
        printf("Writer is writing data...\r\n");
        OSTimeDlyHMSM(0, 0, 2, 0);
        printf("Writer finished writing data\r\n");
        OSSemPost(r_sem);
        OSSemPost(w_sem);
        OSTimeDlyHMSM(0, 0, 1, 0);
    }
}

int main(void)
{
    uart_init(115200);  
    delay_init();
    printf("System initialized\r\n");

    OSInit();

    // 初始时，r信号量为1，w信号量为1
    r_sem = OSSemCreate(1);
    w_sem = OSSemCreate(1);

    // 读者优先级依次为11, 12, 13，写者为14
    OSTaskCreate(Task1_read, (void *)0, &Task1Read_Stk[TASK_STK_SIZE-1], READER1_PRIO);
    OSTaskCreate(Task2_read, (void *)0, &Task2Read_Stk[TASK_STK_SIZE-1], READER2_PRIO);
    OSTaskCreate(Task3_read, (void *)0, &Task3Read_Stk[TASK_STK_SIZE-1], READER3_PRIO);
    OSTaskCreate(Task4_write, (void *)0, &Task4Write_Stk[TASK_STK_SIZE-1], WRITER_PRIO);

    printf("All tasks created\r\n");

    OSStart();
    return 0;
}