#include "delay.h"


void Delay(unsigned int i)
{
		unsigned int j=0;
		for(;i>0;i--)
		{
				for(j=0;j<10000;j++);
		}
}


