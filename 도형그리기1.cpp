#include <stdio.h>
#include <conio.h>

int main()
{
	int width, height;
	char symbol;
	int i, k;
	
	printf("���簢���� �׸��� ���α׷��Դϴ�. �ʺ�� ���̸� �Է��ϼ���.\n");
	scanf("%d%d", &width, &height);
	
	printf("�׵θ� ��ȣ�� �Է��ϼ���.\n");
	symbol=getch();
	
	for(i=0;i<width; i++) printf("%c", symbol);
	printf("\n");
	
	for (i=0; k<height-2; k++){
		printf("%c", symbol);
		for (i=0; i<width-2;i++) printf(" ");
		printf("%c\n", symbol);
	}
	
	for (i=0; i<width; i++) printf("%c", symbol);
	printf("\n");
	
	return 0 ;
}
