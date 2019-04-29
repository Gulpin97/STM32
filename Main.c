#include "stm32f10x.h"

int main ()
{
	int i;
	GPIO_InitTypeDef dioda;
	//RCC -> APB2ENR = 0x00000008;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	// GPIOB -> CRH = 0x33333333;
	dioda.GPIO_Mode = GPIO_Mode_Out_PP;
	dioda.GPIO_Pin = GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	dioda.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&dioda);
	while(1){
		//GPIOB -> ODR = 0x0100;
		GPIO_Write(GPIOB,0x0100);
		for (i=1000000;i > 0; i--);
		//GPIOB -> ODR = 0x0000;
		GPIO_Write(GPIOB,0x0000);
		for (i=1000000;i > 0; i--);
	}
}