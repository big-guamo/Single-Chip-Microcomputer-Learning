/*******************************************************************************  
* 文件名称：数码管控制实验
* 实验目的：1.掌握数码管动态扫描的基本原理,掌握数码管消除“鬼影”的方法
*           2.掌握51单片机定时器工作模式和配置方法
*           3.掌握keil uvision集成开发环境下，中断服务函数设计方法
* 实验配置：J3跳线配置为MM方式，J5配置为BTN、J2配置为1-3和2-4
* 程序现象：数码管动态显示
* 硬件环境：IAP15F2K61S2@11.0592MHz
* 注意事项：理解动态显示和静态显示
* 日期版本：2019-6-24/V2.0
*******************************************************************************/
#include "STC15F2K60S2.h"  //定义51单片机特殊功能寄存器

#include "intrins.h"

code unsigned char tab[] = { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xFF};
unsigned char dspbuf[8] = {10,10,10,10,10,0,0,0};  //显示缓冲区
unsigned char dspcom = 0;  //显示位选
unsigned char x = 123;
void display();
void Delay100us();
void buzz();//关蜂鸣器，继电器
//主函数
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
				if (dspcom == 6) { //在第七位显示小数点
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
//显示函数
			void display() {   
				
				P2 = ((P2&0x1f)|0xe0);//消隐
				P0 = 0xff;
				P2 = ((P2&0x1f)|0xc0);�//移位，位控制
				P0 = (1<<dspcom);
				P2 = ((P2&0x1f)|0xe0);
				P0 = tab[dspbuf[dspcom]]; //段码
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
