
/* Module select */
// #define __LED_TEST__
// #define __BUTTON_TEST__
#define __UART_TEST__



#if (defined __LED_TEST__)
	#include "led.h"
	#define TEST_FUNC()			Led_show()
#elif (defined __BUTTON_TEST__)
	#include "Button.h"
	#define TEST_FUNC()			Button_show()
#elif (defined __UART_TEST__)
	#include "Uart.h"
	#define TEST_FUNC()			Uart_show()
#endif

int main(int argc, char const *argv[])
{
	TEST_FUNC();
	return 0;
}
