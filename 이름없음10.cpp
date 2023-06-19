#include <stdio.h>

#define MaxSiz 1000

int main()
{
	int A[MaxSiz];
	int i, j, n, temp;
	
	printf("몇개의 정수를 입력하 것인지요?\n");
	scanf("%d", &n);
	
	printf("%d개의 정수를 차례로 입력하세요.\n", n);
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	
	i=0;
	for (j=1; j<n; j++)
	if(A[j]>A[0]) {
		i++;
		temp=A[i]; A[i]=A[j], A[j]=temp;
	}
	
	temp=A[0]; A[0]=A[i]; A[i]=temp;
	
	printf("분할된 결과를 보여 드리겠습니다.\n");
	for (i=0; i<n; i++) printf("%d, ", A[i]);
	printf("\n");
	
	return 0;
}
