#include <stdio.h>
#include <stdlib.h>


float fahrenheit_to_celsius(float fahr);
float inch_to_centi_meter(float inch);

int main()
{
	int choice;
	float celsius, fahrenheit;
	float centi_meter, inch;
	
	printf("[���� ��ȯ ���α׷�]\n");
	printf("   1. ��ġ -> ��Ƽ���� \n");
	printf("   2. ȭ�� -> ���� \n");
	printf("�޴��� �����Ͻÿ�.\n"); 
	scanf("%d",&choice);
	
	if (choice==1){
		printf("��ġ�� �Է��϶�.\n");
		scanf("%f", &inch);
		centi_meter = inch_to_centi_meter(inch);
		printf("%f ��ġ�� %f ��Ƽ�����̴�. \n", inch, centi_meter);
	}
	else if (choice==2){
		printf("ȭ���� �Է��϶�.\n");
		scanf("%f", &fahrenheit);
		celsius = fahrenheit_to_celsius(fahrenheit);
		printf("ȭ�� %f���� ���� &f �� �̴�.\n", fahrenheit, celsius);
	}
	else{
		printf("Ʋ�� �޴��Դϴ�. ���α׷��� ���� �մϴ�.");
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
