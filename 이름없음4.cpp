#include <stdio.h>
#include <stdlib.h>

int main()
{
	int main_menu, sub_menu;
	float celsius, fahrenheit;
	float centi_meter, inch;
	
	printf("[���� ��ȯ ���α׷�]\n");
	printf(" 1. ��ġ <-> ��Ƽ����\n");
	printf(" 2. ȭ�� <-> ����\n");
	scanf("%d", &main_menu);
	
	if(main_menu==1){
		printf(" 1. ��ġ -> ��Ƽ\n");
		printf(" 2. ��Ƽ -> ��ġ\n");
		scanf("%d", &sub_menu);
		
		if(sub_menu==1){
			printf("��ġ�� �Է��϶�.\n");
			scanf("%f", &inch);
			centi_meter = inch*2.54;
			printf(" %f ��ġ�� %f ��Ƽ ���ʹ�.\n", inch, centi_meter);
		}
		else if(sub_menu==2){
			printf("��Ƽ���� �Է��϶�.\n");
			scanf("%f", &centi_meter);
			inch = centi_meter/2.54;
			printf(" %f ��Ƽ�� %f ��ġ��.\n", centi_meter, inch);
		}
		else{
		printf("�޴��� �߸� ���� �ϼ̽��ϴ�. \n �ٽ� �Է� ���ּ���.\n");
	}
		printf(" 1. ��ġ -> ��Ƽ\n");
		printf(" 2. ��Ƽ -> ��ġ\n");
		scanf("%d", &sub_menu);
	}
	else if(main_menu==2){
		printf(" 1. ȭ��-> ����\n");
		printf(" 2. ����-> ȭ��\n");
		scanf("%d", &sub_menu);
		
		if(sub_menu==1){
			printf("ȭ���� �Է��϶�.\n");
			scanf("%f", &fahrenheit);
			celsius = (5.0/9.0)*(fahrenheit-32.0);
			printf("ȭ�� %f ���� ���� %f �� �Դϴ�.\n", fahrenheit, celsius);
		} 
		else if(sub_menu==2){
			printf("������ �Է��϶�.\n");
			scanf("%f", &celsius);
			fahrenheit = (9.0/5.0)*celsius+32.0;
			printf("���� %f ���� ȭ�� %f �� �Դϴ�.\n", celsius, fahrenheit);
		}
		else{
			printf("�޴��� �߸� ���� �ϼ̽��ϴ�. \n �ٽ� �Է� ���ּ���.\n");
		}
			printf(" 1. ȭ��-> ����\n");
			printf(" 2. ����-> ȭ��\n");
			scanf("%d", &sub_menu);
		
	}
	else{
		printf("�޴��� �߸� ���� �ϼ̽��ϴ�. \n �ٽ� �Է� ���ּ���.\n");
		printf("[���� ��ȯ ���α׷�]\n");
		printf(" 1. ��ġ <-> ��Ƽ����\n");
		printf(" 2. ȭ�� <-> ����\n");
		scanf("%d", &main_menu); }
	return 0;
 } 
