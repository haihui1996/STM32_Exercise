/////////////////////////////////////////////////////////////////////////////
//@FileName:  Button.h
//@Path:      D:\STM32\STM32Á·Ï°\1.LED\LED\Hardware\Button
//@Description: 
//@Copyright (c) 2019 Haihui Deng
//@Author     haihui.deng@longsys.com 2019/11/24
/////////////////////////////////////////////////////////////////////////////
#ifndef __BUTTON_H__
#define __BUTTON_H__
#include "stdint.h"
void Button_show(void);
void Button_init(void);
uint8_t Button_Value_Get(void);

#endif
