#include <stdio.h>

int main()
{
	float celsius, fahrenheit;
	
	printf("ȭ���� ������ ��ȯ�ϴ� ���α׷��Դϴ�.\n");
	
	printf("ȭ���� �Է��Ͻÿ�.\n");
	scanf("%f", &fahrenheit);
	
	celsius=(5.0/9.0)*(fahrenheit-32.0);
		
	printf("ȭ���� %f ���� ���� %f �� �Դϴ�.\n", fahrenheit, celsius);
	return 0;
}
