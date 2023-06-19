#include <stdio.h>

int main()
{
	float height, wide, circumference, area;
	
	printf("직사각형의 둘레와 면적을 구하는 프로그램입니다.\n");
	printf("직사각형의 높이와 너비를 입력하세요.\n");
	scanf("%f%f", &height, &wide);
	
	circumference= 2.0*(height + wide);
	area= height * wide;
	
	printf("직사각형의 둘레는 %f m입니다.\n", circumference);
	printf("직사각형의 면적은 %f m^2 입니다.", area);
	
	return 0;
	 
 } 
