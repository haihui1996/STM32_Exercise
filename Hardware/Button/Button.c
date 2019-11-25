/////////////////////////////////////////////////////////////////////////////
//@FileName:  Button.c
//@Path:      D:\STM32\STM32Á·Ï°\1.LED\LED\Hardware\Button
//@Description: 
//@Copyright (c) 2019 Haihui Deng
//@Author     haihui.deng@longsys.com 2019/11/24
/////////////////////////////////////////////////////////////////////////////

#include "Button.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "delay.h"
#include "led.h"
#define TURE    1
#define FALSE   0
static GPIO_InitTypeDef Button;
/**
***************************************************************************
*@brief:  
*@param:  
*@return: 
*@warning:
*@Author      haihui.deng@longsys.com 2019/11/24
***************************************************************************
*/
void Button_show(void)
{
    uint8_t Val;
    Button_init();
    delay_init();
    led_init();
    while (1)
    {
        Val = Button_Value_Get();
        if (!Val)
        {
            Val = FALSE;
            led_on();
            delay_ms(1000);
            led_off();
        }
    }

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
void Button_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    Button.GPIO_Mode    = GPIO_Mode_IPU;
    Button.GPIO_Pin     = GPIO_Pin_5;
    Button.GPIO_Speed   = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &Button);
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
uint8_t Button_Value_Get(void)
{
    return GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);
}
