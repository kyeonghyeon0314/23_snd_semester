#include <stdio.h>

int main()
{
	int m, n, A, B, R, x=0;
	
	printf("두개의 정수를 입력하라.\n");
	scanf("%d%d", &m, &n);
	
	if(m>n){
		A=m; 
		B=n;
	}
	else {
		A=n;
		B=m;
	}
	while (1) {
		R=A%B;
		x++;
		if(R==0) break;
		else{
			A=B;
			B=R;
		}
	}
	printf("%d와 %d의 최대공약수는 %d이다.\n %d", m, n, B, x);
	return 0;
}
