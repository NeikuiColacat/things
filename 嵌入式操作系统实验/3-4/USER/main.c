#include "includes.h"       // UC/OS-II 头文件
#include "stm32f10x.h"      // STM32F1 头文件
#include "delay.h"
#include "usart.h"


OS_EVENT *sem_full;    // 当前可消费的食物数量信号量
OS_EVENT *sem_empty;   // 当前可生产的食物空间信号量
OS_EVENT *sem_mutex;   // 互斥信号量，保护共享资源
INT8U food = 0;

#define TASK_STK_SIZE 128
OS_STK ProducerTask_STACK[TASK_STK_SIZE];
OS_STK ConsumerTask_STACK[TASK_STK_SIZE];

#define PRODUCER_PRIO 11    // 生产者优先级高于消费者
#define CONSUMER_PRIO 12    // 消费者优先级


void App_Producer(void *pdata)
{
		INT8U err;
    while(1)
    {
				printf("Producer ready to produce food");
        OSSemPend(sem_empty, 0, &err);
				OSSemPend(sem_mutex, 0, &err);

        food++;
        printf("Producer: food produced, current count: %d\r\n", food);
        
        OSSemPost(sem_mutex);
        OSSemPost(sem_full);
        
				printf("Producer ");
        delay_ms(1);
				

    }
}


void App_Consumer(void *pdata)
{
    INT8U err;
    
    while(1)
    {
			  
				
				printf("Consumer ready to consume food");
        OSSemPend(sem_full, 0, &err);
				
        OSSemPend(sem_mutex, 0, &err);
        food--;
        printf("Consumer: food consumed, current count: %d\r\n", food);
        OSSemPost(sem_mutex);
     
        OSSemPost(sem_empty);
				printf("Consumer resting...");
        delay_ms(3);

    }
}


int main(void)
{

    uart_init(115200);  
    delay_init();
    
    printf("System initialized \r\n");

    OSInit();
    
    sem_full = OSSemCreate(0);    
    sem_empty = OSSemCreate(20);  
    sem_mutex = OSSemCreate(1);
    

    OSTaskCreate(App_Producer, (void *)0, &ProducerTask_STACK[TASK_STK_SIZE-1], PRODUCER_PRIO);
    OSTaskCreate(App_Consumer, (void *)0, &ConsumerTask_STACK[TASK_STK_SIZE-1], CONSUMER_PRIO);
    
    printf("All tasks created\r\n");
    
    OSStart();
    
    return 0;
}

