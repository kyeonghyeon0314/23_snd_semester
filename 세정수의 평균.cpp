#include <stdio.h>

int main()
{
	float average;
	int alpha, delta, gamma;
	
	printf("3개의 정수의 평균을 구하는 프로그램입니다.\n");
	printf("3개의 정수를 입력하시오.\n");
	scanf("%d%d%d",&alpha ,&delta ,&gamma);
	
	average=(alpha+delta+gamma)/3.0;
	
	printf("입력하신 3개의 정수의 평균은 %f 입니다.\n", average);
	return 0;
}
