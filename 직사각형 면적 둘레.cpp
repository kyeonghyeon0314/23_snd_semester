#include <stdio.h>

int main()
{
	float height, wide, circumference, area;
	
	printf("���簢���� �ѷ��� ������ ���ϴ� ���α׷��Դϴ�.\n");
	printf("���簢���� ���̿� �ʺ� �Է��ϼ���.\n");
	scanf("%f%f", &height, &wide);
	
	circumference= 2.0*(height + wide);
	area= height * wide;
	
	printf("���簢���� �ѷ��� %f m�Դϴ�.\n", circumference);
	printf("���簢���� ������ %f m^2 �Դϴ�.", area);
	
	return 0;
	 
 } 
