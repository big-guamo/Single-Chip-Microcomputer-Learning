#include<reg52.h>
#include <intrins.h>

unsigned int i;

void delay(void){
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 9;
	j = 104;
	k = 139;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main(){
while(1){
	int array[4]={0xe7,0xdb,0xbd,0x7e};
	for(i=0;i<4;i++){
		P2 = ((P2&0x1f)|0x80);
			P0=array[i];
				P2 &= 0x1f;
					delay();
	}
}
}