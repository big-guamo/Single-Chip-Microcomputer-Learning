/*******************************************************************************  
* �ļ����ƣ�����ܿ���ʵ��
* ʵ��Ŀ�ģ�1.��������ܶ�̬ɨ��Ļ���ԭ��,�����������������Ӱ���ķ���
*           2.����51��Ƭ����ʱ������ģʽ�����÷���
*           3.����keil uvision���ɿ��������£��жϷ�������Ʒ���
* ʵ�����ã�J3��������ΪMM��ʽ��J5����ΪBTN��J2����Ϊ1-3��2-4
* ������������ܶ�̬��ʾ
* Ӳ��������IAP15F2K61S2@11.0592MHz
* ע�������⶯̬��ʾ�;�̬��ʾ
* ���ڰ汾��2019-6-24/V2.0
*******************************************************************************/
#include "STC15F2K60S2.h"  //����51��Ƭ�����⹦�ܼĴ���

#include "intrins.h"

code unsigned char tab[] = { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xFF};
unsigned char dspbuf[8] = {10,10,10,10,10,0,0,0};  //��ʾ������
unsigned char dspcom = 0;  //��ʾλѡ
unsigned char x = 123;
void display();
void Delay100us();
void buzz();//�ط��������̵���
//������
void main()
{ 
			void buzz();
			P2 = ((P2 & 0x1f)|0x80);
			P0 = 0xff;
			P2 &= 0x1f;
	
			dspbuf[5] = x/100;
			dspbuf[6] = x%100/10;
			dspbuf[7] = x%10;
	
			while (1) {
				
				P2 = ((P2 & 0x1f)|0x80);
				P0 = 0xff;
				P2 &= 0x1f;
				
				display();
				Delay100us();
				if (dspcom == 6) { //�ڵ���λ��ʾС����
					P2 = ((P2&0x1f)|0xc0);
					P0 = (1<<dspcom);
					P2 = ((P2&0x1f)|0xe0);
					P0 = 0x7f; 
					P2 &= 0x1f;
				}
				Delay100us();
		
	}

}


		void Delay100us()		//@11.0592MHz
		{
			unsigned char i, j;

			_nop_();
			_nop_();
			i = 2;
			j = 15;
			do
			{
				while (--j);
			} while (--i);
		}
//��ʾ����
			void display() {   
				
				P2 = ((P2&0x1f)|0xe0);//����
				P0 = 0xff;
				P2 = ((P2&0x1f)|0xc0);�//��λ��λ����
				P0 = (1<<dspcom);
				P2 = ((P2&0x1f)|0xe0);
				P0 = tab[dspbuf[dspcom]]; //����
				P2 &= 0x1f;
				
				if (++dspcom == 8) {
					dspcom = 0;
				}
			}

			void buzz() {
						P2 = ((P2&0x1f)|0xa0);
						P0 &= 0xaf;
						P2 &= 0x1f;
			}
