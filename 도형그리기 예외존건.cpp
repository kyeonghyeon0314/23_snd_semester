#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int width, height;
	char symbol;
	int i, k;
	
	printf("직사각형을 그리는 프로그램입니다. 너비와 높이를 입력하세요.\n");
	scanf("%d%d", &width, &height);
	
		if(width<0||height<0){
		printf("너비와 높이는 양수이어야 합니다.\n");
		exit(0);
	}
	
	printf("테두리 기호를 입력하세요.\n");
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
