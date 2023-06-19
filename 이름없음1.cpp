#include <stdio.h>
#include <stdlib.h>


float fahrenheit_to_celsius(float fahr);
float inch_to_centi_meter(float inch);

int main()
{
	int choice;
	float celsius, fahrenheit;
	float centi_meter, inch;
	
	printf("[단위 변환 프로그램]\n");
	printf("   1. 인치 -> 센티미터 \n");
	printf("   2. 화씨 -> 섭씨 \n");
	printf("메뉴를 선택하시오.\n"); 
	scanf("%d",&choice);
	
	if (choice==1){
		printf("인치를 입력하라.\n");
		scanf("%f", &inch);
		centi_meter = inch_to_centi_meter(inch);
		printf("%f 인치는 %f 센티미터이다. \n", inch, centi_meter);
	}
	else if (choice==2){
		printf("화씨를 입력하라.\n");
		scanf("%f", &fahrenheit);
		celsius = fahrenheit_to_celsius(fahrenheit);
		printf("화씨 %f도는 섭씨 &f 도 이다.\n", fahrenheit, celsius);
	}
	else{
		printf("틀린 메뉴입니다. 프로그램을 종료 합니다.");
		exit (0);		
	}
	return 0;
}

float fahrenheit_to_celsius(float fahr) {
	float cel;
	
	cel=(5.0/9.0)*(fahr-32.0);
	return cel;
}

float inch_to_centi_meter(float inch){
	float cm;
	
	cm = inch*2.54;
	return cm;
}
