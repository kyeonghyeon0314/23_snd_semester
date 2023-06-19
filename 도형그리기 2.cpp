#include <stdio.h>
#include <conio.h>

int main()
{
	int width, height, number;
	char symbol;
	int i, k, n;
	
	printf("직사각형을 그리는 프로그램입니다. 너비와 높이를 입력하세요.\n");
	scanf("%d%d", &width, &height);
	
	printf("개수 입력");
	scanf("%d",&number);
	
	printf("테두리 기호를 입력하세요.\n");
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
