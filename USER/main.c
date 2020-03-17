
/* Module select */
<<<<<<< HEAD
#define MODULE_SELECT		(4)
=======
// #define __LED_TEST__
// #define __BUTTON_TEST__
#define __EXTI_TEST__
// #define __UART_TEST__
>>>>>>> b8a1c16609370ee850694d6ae8c3285f32571780

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
<<<<<<< HEAD
#elif (MODULE_SELECT == __EXTI_TEST__)
	#include "Exit.h"
=======
#elif (defined __EXTI_TEST__)
	#include "Uart.h"
>>>>>>> b8a1c16609370ee850694d6ae8c3285f32571780
	#define TEST_FUNC()			EXTI_show()
#endif

int main(int argc, char const *argv[])
{
	TEST_FUNC();
	while (1);	
}
