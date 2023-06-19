#include <stdio.h>

int main(){
	
	int n, fact=1;
	
	printf("n!을 구하는 프로그램입니다.\n n을 입력하세요.\n");
	scanf("%d", &n);
	
	while(1<=n){
		fact = fact*n;
		n= n-1;
	}
	
	printf("%d 입니다.\n",fact);
}
