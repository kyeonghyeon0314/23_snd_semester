#include <stdio.h>
#include <stdlib.h>

int main()
{
	int main_menu, sub_menu;
	float celsius, fahrenheit;
	float centi_meter, inch;
	
	printf("[단위 변환 프로그램]\n");
	printf(" 1. 인치 <-> 센티미터\n");
	printf(" 2. 화씨 <-> 섭씨\n");
	scanf("%d", &main_menu);
	
	if(main_menu==1){
		printf(" 1. 인치 -> 센티\n");
		printf(" 2. 센티 -> 인치\n");
		scanf("%d", &sub_menu);
		
		if(sub_menu==1){
			printf("인치를 입력하라.\n");
			scanf("%f", &inch);
			centi_meter = inch*2.54;
			printf(" %f 인치는 %f 센티 미터다.\n", inch, centi_meter);
		}
		else if(sub_menu==2){
			printf("센티를를 입력하라.\n");
			scanf("%f", &centi_meter);
			inch = centi_meter/2.54;
			printf(" %f 센티는 %f 인치다.\n", centi_meter, inch);
		}
		else{
		printf("메뉴를 잘못 선택 하셨습니다. \n 다시 입력 해주세요.\n");
	}
		printf(" 1. 인치 -> 센티\n");
		printf(" 2. 센티 -> 인치\n");
		scanf("%d", &sub_menu);
	}
	else if(main_menu==2){
		printf(" 1. 화씨-> 섭씨\n");
		printf(" 2. 섭씨-> 화씨\n");
		scanf("%d", &sub_menu);
		
		if(sub_menu==1){
			printf("화씨를 입력하라.\n");
			scanf("%f", &fahrenheit);
			celsius = (5.0/9.0)*(fahrenheit-32.0);
			printf("화씨 %f 도는 섭씨 %f 도 입니다.\n", fahrenheit, celsius);
		} 
		else if(sub_menu==2){
			printf("섭씨를 입력하라.\n");
			scanf("%f", &celsius);
			fahrenheit = (9.0/5.0)*celsius+32.0;
			printf("섭씨 %f 도는 화씨 %f 도 입니다.\n", celsius, fahrenheit);
		}
		else{
			printf("메뉴를 잘못 선택 하셨습니다. \n 다시 입력 해주세요.\n");
		}
			printf(" 1. 화씨-> 섭씨\n");
			printf(" 2. 섭씨-> 화씨\n");
			scanf("%d", &sub_menu);
		
	}
	else{
		printf("메뉴를 잘못 선택 하셨습니다. \n 다시 입력 해주세요.\n");
		printf("[단위 변환 프로그램]\n");
		printf(" 1. 인치 <-> 센티미터\n");
		printf(" 2. 화씨 <-> 섭씨\n");
		scanf("%d", &main_menu); }
	return 0;
 } 
