#include <reg52.h>
#include " intrins.h"

		void delay()//延时函数1秒
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

		void main (void)
		{
			while (1)
			{
				P2 = ((P2 & 0x1f)|0x80) ;//选定锁存器
				P0=0x0f;//P0=00001111，前四个led灯亮
				P2 &=0x1f;//关闭/不选中锁存器
				delay();//延时一秒
				
				P2 = ((P2 & 0x1f)|0x80) ;
				P0=0xf0;
				P2 &=0x1f;
				delay();
			}
		}
	