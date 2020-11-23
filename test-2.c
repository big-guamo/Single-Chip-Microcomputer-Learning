#include <reg52.h>
#include " intrins.h"

void buzz(){
  P2=((P2&0x1f)|0xa0);
			P0 &=0xaf;
			P2 &=0x1f;

}
		void delay()//????1?
		{
			
			unsigned char i, j, k;

			_nop_();
			_nop_();
			i = 43;
			j = 6;
			k = 203;
			do
			{
				do
				{
					while (--k);
				} while (--j);
			} while (--i);

		}
		int i;

		void main(void){
			
		
		 
     
			buzz();
			
			while(1){
			  for(i=7;i>=0;i--){
				P2 = ((P2 & 0x1f)|0x80) ;
					P0=~(0xff<<i);
				
					P2 &=0x1f;
				delay();
					P2 = ((P2 & 0x1f)|0x80) ;
					P0=~(0xff<<(i+1));
				
					P2 &=0x1f;
				delay();
					P2 = ((P2 & 0x1f)|0x80) ;
					P0=~(0xff<<(i));
				
					P2 &=0x1f;
				delay();
					
				
				}
			}
			
		}
