#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int width, height;
	char symbol;
	int i, k;
	
	printf("���簢���� �׸��� ���α׷��Դϴ�. �ʺ�� ���̸� �Է��ϼ���.\n");
	scanf("%d%d", &width, &height);
	
		if(width<0||height<0){
		printf("�ʺ�� ���̴� ����̾�� �մϴ�.\n");
		exit(0);
	}
	
	printf("�׵θ� ��ȣ�� �Է��ϼ���.\n");
	symbol=getch();
	
	
	if(width==0 || width==0);
	else if(height==1){
		for(i=0; i<width; i++) printf("%c", symbol);
		printf("\n");
	}
	else{
		for(i=0; i<width;i++) printf("%c", symbol);
		printf("\n");
		
		for(k=0; k<height-2;k++){
			printf("%c", symbol);
			for(i=0;i<width-2; i++) printf(" ");
			printf("%c\n", symbol);
		}
		
		for (i=0; i<width; i++)printf("%c", symbol);
		printf("\n");
	}
	return 0;
}
