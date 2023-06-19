#include <stdio.h>

int main()
{
	float celsius, fahrenheit;
	
	printf("화씨를 섭씨로 변환하는 프로그램입니다.\n");
	
	printf("화씨를 입력하시오.\n");
	scanf("%f", &fahrenheit);
	
	celsius=(5.0/9.0)*(fahrenheit-32.0);
		
	printf("화씨를 %f 도는 섭씨 %f 도 입니다.\n", fahrenheit, celsius);
	return 0;
}
