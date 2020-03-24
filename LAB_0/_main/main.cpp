#include "GPIO.h" 

int main (void)
{
GPIO *gpio_c_off1= new GPIO(GPIOC,13,GPIO_Mode_Out_PP,GPIO_Speed_10MHz);
GPIO *gpio_b_on= new GPIO(GPIOC,14,GPIO_Mode_Out_PP,GPIO_Speed_10MHz);
GPIO *gpio_b_ask= new GPIO(GPIOC,15,GPIO_Mode_Out_PP,GPIO_Speed_10MHz);
GPIO *gpio_b_save= new GPIO(GPIOB,0,GPIO_Mode_Out_PP,GPIO_Speed_10MHz);	

	while(1)
	{
		gpio_c_off1->Toggle();
		gpio_b_on->Toggle();
		gpio_b_ask->Toggle();
		gpio_b_save->Toggle();
		gpio_b_save->delay_ms(250);
	}
}
