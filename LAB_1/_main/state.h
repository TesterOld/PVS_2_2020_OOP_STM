/*
*********************************************************************************************************
*
*                                      GPIO CALSS HEADER FILE                                
*
* Filename      : GPIO.h
* Version       : V1.1
* Programmer(s) : Jason Xie, Paul K. (KPI), no name programer (KPI), Paul K. 2020 
*              
*********************************************************************************************************
*/
#ifndef _STATE_H
#define _STATE_H

#include "GPIO.h"


#define QUONT_DEFINE 5


typedef enum {
				LEFT = 0,
				RIGHT =1,
				FORVARD = 2,
				BACK = 3,
	      STOP = 3
				} NState;

				
class MyDevice
{
public:
	MyDevice();
	void HandleState();
	static void delay_us( unsigned long Val);
	static void delay_ms( unsigned long Val);

protected:
	int m_nCurrentState;
		GPIO gpio_c_left;
		GPIO gpio_b_right;
		GPIO gpio_b_forvard;
		GPIO gpio_b_back;
		GPIO gpio_b_stop;
};

#endif

