#include <stdio.h>
#include <conio.h>

int main()
{
	int width, height, number;
	char symbol;
	int i, k, n;
	
	printf("���簢���� �׸��� ���α׷��Դϴ�. �ʺ�� ���̸� �Է��ϼ���.\n");
	scanf("%d%d", &width, &height);
	
	printf("���� �Է�");
	scanf("%d",&number);
	
	printf("�׵θ� ��ȣ�� �Է��ϼ���.\n");
	symbol=getch();
	
	for(n=0;n<number; n++){
	for(i=0;i<width; i++) printf("%c", symbol);
	printf(" ");}
	printf("\n");
	
	
	for (i=0; k<height-2; k++){
		for(n=0;n<number; n++){
		printf("%c", symbol);
		for (i=0; i<width-2;i++) printf(" ");
		printf("%c ", symbol);
	}
	printf("\n");}
	
	for(n=0;n<number; n++){
	for (i=0; i<width; i++) printf("%c", symbol);
	printf(" ");}

	return 0 ;
}
