#include <stdio.h>

int main()
{
	float inch, centimetre;
	
	printf("��ġ�� ��Ƽ���ͷ� ��ȯ�ϴ� ���α׷��Դϴ�.\n");
	printf("��Ȱ�� ��ġ ���� �Է��ϼ���.\n");
	scanf("%f", &inch);
	
	centimetre= inch*2.54;
	
	printf("��ȯ�� ��Ƽ���� ���� %f �Դϴ�.\n", centimetre);
	
	return 0;
}
