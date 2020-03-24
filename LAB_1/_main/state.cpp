#include "state.h"


	

	MyDevice::MyDevice(): //initializer list:
			gpio_c_left(GPIOC,13,GPIO_Mode_Out_PP,GPIO_Speed_10MHz),
			gpio_b_right(GPIOC,14,GPIO_Mode_Out_PP,GPIO_Speed_10MHz),
			gpio_b_forvard(GPIOB,8,GPIO_Mode_Out_PP,GPIO_Speed_10MHz),
			gpio_b_back(GPIOB,9,GPIO_Mode_Out_PP,GPIO_Speed_10MHz),
			gpio_b_stop(GPIOC,15,GPIO_Mode_Out_PP,GPIO_Speed_10MHz)
			
    {
        m_nCurrentState= STOP;

			gpio_c_left.mSelectPin =13;
			gpio_c_left.mPort = GPIOC;
			
			gpio_b_right.mSelectPin =14;
			gpio_b_right.mPort = GPIOC;	
			
			gpio_b_forvard.mSelectPin =8;
			gpio_b_forvard.mPort = GPIOB;	
			
			gpio_b_back.mSelectPin =9;
			gpio_b_back.mPort = GPIOB;
			
			gpio_b_stop.mSelectPin =15;
			gpio_b_stop.mPort = GPIOC;
		
 
			
		}
		
void MyDevice::delay_us( unsigned long Val) 
					{
						Val=Val*10;
						for( ; Val != 0; Val--) 
								{
							__nop();
								}
					}

void MyDevice::delay_ms( unsigned long Val) 
					{
						Val=Val*10000;
						for( ; Val != 0; Val--) 
								{
							__nop();
								}
					}


void MyDevice::HandleState()
{
    /* changing state depends on the current state */
   if(STOP == m_nCurrentState)
   {
       m_nCurrentState = FORVARD;
			 for (int i=0; i<QUONT_DEFINE; i++)
				{
					gpio_b_stop.Toggle();
					MyDevice::delay_ms(300);
				}
				gpio_b_stop.SetLevel(1);
   }
   else if(FORVARD == m_nCurrentState)
   {
       m_nCurrentState = LEFT;
			 for (int i=0; i<QUONT_DEFINE; i++)
					{
						gpio_b_forvard.Toggle();
						MyDevice::delay_ms(300);
					}
					gpio_b_forvard.SetLevel(0);
   }
   else if(RIGHT == m_nCurrentState)
   {
       m_nCurrentState = BACK;
			 for (int i=0; i<QUONT_DEFINE; i++)
					{
						gpio_b_right.Toggle();
						MyDevice::delay_ms(300);
					}
					gpio_b_right.SetLevel(0);
   }
  else if(BACK == m_nCurrentState)
   {
       m_nCurrentState = STOP;
			 for (int i=0; i<QUONT_DEFINE; i++)
					{
						gpio_b_back.Toggle();
						MyDevice::delay_ms(300);
					}
					gpio_b_back.SetLevel(0);
   }
	 else if(LEFT == m_nCurrentState)
   {
       m_nCurrentState = RIGHT;
			 for (int i=0; i<QUONT_DEFINE; i++)
					{
						gpio_b_back.Toggle();
						MyDevice::delay_ms(300);
					}
					gpio_b_back.SetLevel(0);
   }
	 
  // We can add more states here
 }
//-----------------------------------
