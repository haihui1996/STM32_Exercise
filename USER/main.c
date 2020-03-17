
/* Module select */

#define MODULE_SELECT		(4)

#define __LED_TEST__		(1)
#define __BUTTON_TEST__		(2)
#define __EXTI_TEST__		(3)
#define __UART_TEST__		(4)



#if (MODULE_SELECT == __LED_TEST__)
	#include "led.h"
	#define TEST_FUNC()			Led_show()
#elif (MODULE_SELECT == __BUTTON_TEST__)
	#include "Button.h"
	#define TEST_FUNC()			Button_show()
#elif (MODULE_SELECT == __UART_TEST__)
	#include "Uart.h"
	#define TEST_FUNC()			Uart_show()
#endif

int main(int argc, char const *argv[])
{
	TEST_FUNC();
	while (1);	
}
