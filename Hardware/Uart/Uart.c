#include "Uart.h"
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "delay.h"

void Uart_show(void)
{
    const uint8_t buffer[] = "hello world\r\n";
    Uart_init((uint16_t)115200);
    delay_init();
    while (1)
    {
        myprintf(buffer);
        delay_ms(100);
    }
}
void Uart_init(uint16_t wBaudRate)
{
    USART_InitTypeDef UART;
    GPIO_InitTypeDef UART_Pin;
    /**
     *  时钟使能，复用功能需要使能GPIO时钟及端口复用时钟
     **/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    /**
     *  串口引脚功能设定 
     **/
    /* Tx:复用推挽输出 **/
    UART_Pin.GPIO_Mode = GPIO_Mode_AF_PP;
    UART_Pin.GPIO_Pin = GPIO_Pin_9;
    UART_Pin.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &UART_Pin);

    /* Rx:浮空输入 */
    UART_Pin.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    UART_Pin.GPIO_Pin = GPIO_Pin_10;
    UART_Pin.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &UART_Pin);

    /* 初始化串口 */
    UART.USART_BaudRate = wBaudRate;
    UART.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    UART.USART_Parity = USART_Parity_No;
    UART.USART_StopBits = USART_StopBits_1;
    UART.USART_WordLength = USART_WordLength_8b;
    UART.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART1, &UART);

    /* 使能串口 */
    USART_Cmd(USART1, ENABLE);
}

void myprintf(const unsigned char *bStr)
{
    uint16_t i;
    for (i = 0; bStr[i] != '\0'; i++)
    {
        USART_SendData(USART1, bStr[i]);
    }
}
