/////////////////////////////////////////////////////////////////////////////
//@FileName:  led.c
//@Path:      D:\STM32\STM32��ϰ\1.LED\LED\Hardware\LED
//@Description: 
//@Copyright (c) 2019 Haihui Deng
//@Author     haihui.deng@longsys.com 2019/11/24
/////////////////////////////////////////////////////////////////////////////
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "delay.h"
#include "led.h"


static GPIO_InitTypeDef LED_Pin;
/**
***************************************************************************
*@brief:  
*@param:  
*@return: 
*@warning:
*@Author      haihui.deng@longsys.com 2019/11/24
***************************************************************************
*/
void Led_show(void)
{
    delay_init();
    led_init();
    while (1)
    {
        led_on();
        delay_ms(500);
        led_off();   
        delay_ms(500);
    }
}

/**
***************************************************************************
*@brief:  led��ʼ��������GPIO���ģʽ
*@param:  
*@return: 
*@warning:
*@Author      haihui.deng@longsys.com 2019/11/24
***************************************************************************
*/
void led_init(void)
{
    /* ʹ��GPIOAʱ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /* ����LED���� */
    LED_Pin.GPIO_Pin    = GPIO_Pin_8;
    LED_Pin.GPIO_Mode   = GPIO_Mode_Out_PP;
    LED_Pin.GPIO_Speed  = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &LED_Pin);
}

/**
***************************************************************************
*@brief:  
*@param:  
*@return: 
*@warning:
*@Author      haihui.deng@longsys.com 2019/11/24
***************************************************************************
*/
void led_on(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
}

/**
***************************************************************************
*@brief:  
*@param:  
*@return: 
*@warning:
*@Author      haihui.deng@longsys.com 2019/11/24
***************************************************************************
*/
void led_off(void)
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_8);
}
