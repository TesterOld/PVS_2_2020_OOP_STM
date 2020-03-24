#include "GPIO.h"

//Initialize the static member constants
const  uint16_t  GPIO::mPinL[8]={GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2,GPIO_Pin_3,GPIO_Pin_4,GPIO_Pin_5,GPIO_Pin_6,GPIO_Pin_7};
const  uint16_t  GPIO::mPinH[8]={GPIO_Pin_8,GPIO_Pin_9,GPIO_Pin_10,GPIO_Pin_11,GPIO_Pin_12,GPIO_Pin_13,GPIO_Pin_14,GPIO_Pin_15};
const  uint16_t  GPIO::mPin[16]={GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2,GPIO_Pin_3,GPIO_Pin_4,GPIO_Pin_5,GPIO_Pin_6,GPIO_Pin_7,GPIO_Pin_8,GPIO_Pin_9,GPIO_Pin_10,GPIO_Pin_11,GPIO_Pin_12,GPIO_Pin_13,GPIO_Pin_14,GPIO_Pin_15 };								
//The Constructor of the Class
GPIO::GPIO(GPIO_TypeDef *port,uint16_t pin,GPIOMode_TypeDef mode,GPIOSpeed_TypeDef speed)
					:mMode(mode),mSpeed(speed),mPort(port),mSelectPin(pin)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_Configuration();
		
	GPIO_InitStructure.GPIO_Pin=mPin[pin];
	GPIO_InitStructure.GPIO_Speed=speed;
	GPIO_InitStructure.GPIO_Mode=mode;
	GPIO_Init(mPort,&GPIO_InitStructure);	
}

// This ctor is better 
GPIO::GPIO(GPIO_TypeDef *port,GPIOMode_TypeDef modeIn,GPIOMode_TypeDef modeOut, GPIOSpeed_TypeDef speed)
					:mModeIn(modeIn),mModeOut(modeOut), mSpeed(speed),mPort(port)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_Configuration();
		
	GPIO_InitStructure.GPIO_Pin|=GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed=speed;
	GPIO_InitStructure.GPIO_Mode=modeIn;
	GPIO_Init(mPort,&GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin|=GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed=speed;
	GPIO_InitStructure.GPIO_Mode=modeOut;
	GPIO_Init(mPort,&GPIO_InitStructure);	
}



//The function to configure the RCC of GPIO
void GPIO::RCC_Configuration()
{
	if(mPort==GPIOA)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	}
	else if(mPort==GPIOB)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	}
	else if(mPort==GPIOC)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	}
	//else if for D-G
}

/**
* @brief Set the level of the pin						
* @param level:The level you wan to set,value:0 or 1	
*/
void GPIO::SetLevel(u8 level)
{
	if(level>0)
		GPIO_SetBits(mPort,mPin[mSelectPin]);
	else
		GPIO_ResetBits(mPort,mPin[mSelectPin]);
}

/**
* @brief Get the level of the pin								
* @retval level:Return the pin's level,value:true(1),false(0)	
*/
bool GPIO::GetLevel()
{
	if(!GPIO_ReadInputDataBit(mPort,mPin[mSelectPin]))
		return false;
	else
		return true;
}

/***	Invert the level of the pin	***/
void GPIO::Toggle()
{
	if(GPIO_ReadInputDataBit(mPort,mPin[mSelectPin]))
		GPIO_ResetBits(mPort,mPin[mSelectPin]);
	else
		GPIO_SetBits(mPort,mPin[mSelectPin]);
}

void GPIO::Toggle(uint16_t i)
{
	if(GPIO_ReadInputDataBit(mPort,mPin[i]))
		GPIO_ResetBits(mPort,mPin[i]);
	else
		GPIO_SetBits(mPort,mPin[i]);
}

void GPIO::ChangeMode(GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = mPin[mSelectPin];
	GPIO_InitStructure.GPIO_Speed = mSpeed;
	GPIO_InitStructure.GPIO_Mode = mode;
	GPIO_Init(mPort,&GPIO_InitStructure);
}

void GPIO::delay_us( unsigned long Val) 
					{
						Val=Val*10;
						for( ; Val != 0; Val--) 
								{
							__nop();
								}
					}

void GPIO::delay_ms( unsigned long Val) 
					{
						Val=Val*10000;
						for( ; Val != 0; Val--) 
								{
							__nop();
								}
					}
