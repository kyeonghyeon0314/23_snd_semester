#include <stdio.h>

int main()
{
	float average;
	int alpha, delta, gamma;
	
	printf("3���� ������ ����� ���ϴ� ���α׷��Դϴ�.\n");
	printf("3���� ������ �Է��Ͻÿ�.\n");
	scanf("%d%d%d",&alpha ,&delta ,&gamma);
	
	average=(alpha+delta+gamma)/3.0;
	
	printf("�Է��Ͻ� 3���� ������ ����� %f �Դϴ�.\n", average);
	return 0;
}
