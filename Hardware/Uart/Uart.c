#include "Uart.h"
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"


static USART_InitTypeDef UART;
static GPIO_InitTypeDef UART_Pin;

void Uart_show(void)
{
    Uart_init();
    printf("HelloWorld\r\n");
}
void Uart_init(void)
{
    /**
     *  ����ʱ��ʹ�� 
     **/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    /**
     *  �������Ź����趨 
     **/
    /* Tx:����������� **/
    UART_Pin.GPIO_Mode = GPIO_Mode_AF_OD;
    UART_Pin.GPIO_Pin  = GPIO_Pin_9;
    UART_Pin.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA; &UART_Pin);
    
    /* Rx:�������� */
    UART_Pin.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    UART_Pin.GPIO_Pin  = GPIO_Pin_10;
    UART_Pin.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA; &UART_Pin);

    /**
     *  ��ʼ������ 
     **/
    UART.USART_BaudRate = 115200;
    UART.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    UART.USART_Parity = USART_Parity_No;
    UART.USART_StopBits = USART_StopBits_1;
    UART.USART_WordLength = USART_WordLength_8b;
    UART.USART_HardwareFlowControl  = USART_HardwareFlowControl_None;
    USART_Init(USART1, &UART);

    /**
     *  ʹ�ܴ��� 
     **/
    USART_Cmd(USART1,ENABLE);
}


void printf(uint8_t * bStr)
{
    uint16_t i;
    for ( i = 0; bStr[i] != '\0' ; i++)
    {
        USART_SendData(USART1, bStr[i]);
    }
    
}
