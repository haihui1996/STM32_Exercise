/////////////////////////////////////////////////////////////////////////////
//@FileName:  Uart.h
//@Path:      E:\STM32_Exercise-master\Hardware\Uart
//@Description: 
//@Copyright (c) 2020 Haihui Deng
//@Author     haihui.deng@longsys.com 2020/03/17
/////////////////////////////////////////////////////////////////////////////
#ifndef __UART_H__
#define __UART_H__
#include <stdint.h>

void Uart_show(void);
void Uart_init(uint16_t dwBoundRate);
void myprintf(const unsigned char * bStr);

#endif
