#include <stdio.h>

int main(){
	
	int n, fact=1;
	
	printf("n!�� ���ϴ� ���α׷��Դϴ�.\n n�� �Է��ϼ���.\n");
	scanf("%d", &n);
	
	while(1<=n){
		fact = fact*n;
		n= n-1;
	}
	
	printf("%d �Դϴ�.\n",fact);
}
