#include <stdio.h>

int main()
{
	float inch, centimetre;
	
	printf("인치를 센티미터로 변환하는 프로그램입니다.\n");
	printf("변활할 인치 값을 입력하세요.\n");
	scanf("%f", &inch);
	
	centimetre= inch*2.54;
	
	printf("변환된 센티미터 값은 %f 입니다.\n", centimetre);
	
	return 0;
}
