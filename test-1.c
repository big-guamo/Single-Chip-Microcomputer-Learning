#include <reg52.h>
#include " intrins.h"

		void delay()//��ʱ����1��
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
				P2 = ((P2 & 0x1f)|0x80) ;//ѡ��������
				P0=0x0f;//P0=00001111��ǰ�ĸ�led����
				P2 &=0x1f;//�ر�/��ѡ��������
				delay();//��ʱһ��
				
				P2 = ((P2 & 0x1f)|0x80) ;
				P0=0xf0;
				P2 &=0x1f;
				delay();
			}
		}
	