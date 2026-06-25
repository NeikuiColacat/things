#include "includes.h"       // UC/OS-II 头文件
#include "stm32f10x.h"      // STM32F1 头文件
#include "delay.h"

#define TASK_STK_SIZE 128   // 任务栈大小
OS_STK LEDTaskStk[TASK_STK_SIZE];
OS_STK BeepTaskStk[TASK_STK_SIZE];
OS_STK KeyTaskStk[TASK_STK_SIZE];

void led_task(void *pdata) {
    while (1) {
        GPIO_SetBits(GPIOB, GPIO_Pin_5);  // LED0 亮
        GPIO_ResetBits(GPIOE, GPIO_Pin_5); // LED1 灭
				
				delay_ms(500);
        GPIO_SetBits(GPIOE, GPIO_Pin_5); // LED0 灭
        GPIO_ResetBits(GPIOB, GPIO_Pin_5);  // LED1 亮
			
				delay_ms(500);

    }
}

void beep_task(void *pdata) {
    while (1) {
        GPIO_SetBits(GPIOB, GPIO_Pin_8);  // 蜂鸣器响
        delay_ms(60);  // 响 60ms
        GPIO_ResetBits(GPIOB, GPIO_Pin_8); // 蜂鸣器停
        delay_ms(940);  // 停 940ms
    }
}

void key_task(void *pdata) {
    while (1) {
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == 0) {  // KEY0_PRES E4
            OSTaskSuspend(10);  // 挂起 LED 任务
        }
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == 0) {  // KEY1_PRES E3
            OSTaskResume(10);   // 恢复 LED 任务
        }
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1) {  // WKUP_PRES
            OSTaskDel(11);      // 删除 BEEP 任务
        }
        delay_ms(100); // 防止按键抖动
    }
}

void GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);  // LED
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  // BEEP
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  // KEY
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);  // LED

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_Init(GPIOE, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
    GPIO_Init(GPIOE,&GPIO_InitStructure);        //Key
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOA,&GPIO_InitStructure);        //Key
}


int main(void) {
		GPIO_Config();
		delay_init();
	
    OSInit();  // 初始化 UC/OS-II
		
    // 创建 LED 任务
    OSTaskCreate(led_task, NULL, &LEDTaskStk[TASK_STK_SIZE - 1], 10);
    // 创建 蜂鸣器 任务
    OSTaskCreate(beep_task, NULL, &BeepTaskStk[TASK_STK_SIZE - 1], 11);
    // 创建 按键检测 任务
    OSTaskCreate(key_task, NULL, &KeyTaskStk[TASK_STK_SIZE - 1], 12);

    OSStart();  // 启动 UC/OS-II

    return 0;
}

