#include "state.h" 

int main (void)
{

MyDevice myDevice;	

	while(1)
	{
		myDevice.HandleState();
		MyDevice::delay_ms(300);
	}
}
