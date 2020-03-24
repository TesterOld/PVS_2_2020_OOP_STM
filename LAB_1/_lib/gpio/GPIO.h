/*
*********************************************************************************************************
*
*                                      GPIO CALSS HEADER FILE                                
*
* Filename      : GPIO.h
* Version       : V1.0
* Programmer(s) : Jason Xie, Paul K. (KPI) 
*              
*********************************************************************************************************
*/
#ifndef _GPIO_H
#define _GPIO_H

#include <stm32f10x.h>
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"



/**
  *	@brief  The class of GPIO.									 				 
  *	@param  mPin[16]: The array of GPIO_Pin_x.			 						 
  *	@param  mPort:The port of GPIO,such as GPIOA,etc.							 
  * @param  mSelectPin:The pin you want to use.									 
  * @param  mMode:The GPIO's mode,such as "GPIO_Mode_Out_PP",etc				 
  * @param  mSpeed:The output's speed of GPIO,such as "GPIO_Speed_10MHz",etc		 
  */
class GPIO
{
	private:
		static const  uint16_t     	mPinL[8];
		static const  uint16_t     	mPinH[8];
		static const  uint16_t     	mPin[16];
		GPIOMode_TypeDef			  mModeIn;
		GPIOMode_TypeDef			  mModeOut;
		GPIOMode_TypeDef			  mMode;
		GPIOSpeed_TypeDef 			mSpeed;
	
		/*	The function to configure the RCC of GPIO	*/
	void RCC_Configuration();
	
	public:
		GPIO_TypeDef				*mPort;
		uint16_t					mSelectPin;
		
		/*	The Constructor of the Class	*/
		GPIO(GPIO_TypeDef *port=GPIOA,uint16_t pin=1,GPIOMode_TypeDef mode=GPIO_Mode_Out_PP,GPIOSpeed_TypeDef speed=GPIO_Speed_50MHz);
	  GPIO(GPIO_TypeDef *port=GPIOA,GPIOMode_TypeDef modeIn=GPIO_Mode_IPU,GPIOMode_TypeDef modeOut= GPIO_Mode_Out_PP, GPIOSpeed_TypeDef speed=GPIO_Speed_50MHz);
		/**
      * @brief disable jtag or sw if you want to use the io below:
      * PB3:JTDO, PB4:JNTRST, PA15:JTDI,  PA14:JTCK/SWCLK, PA13:JTMS/SWDIO
      */
		
		void SetLevel(u8 level);
		bool GetLevel();
		void Toggle();
		void Toggle(uint16_t i);
		void ChangeMode(GPIOMode_TypeDef mode);
};


#endif
								
