#include <stdio.h>

#define MaxSiz 1000

int main()
{
	int A[MaxSiz];
	int i, j, n, temp;
	
	printf("��� ������ �Է��� ��������?\n");
	scanf("%d", &n);
	
	printf("%d���� ������ ���ʷ� �Է��ϼ���.\n", n);
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	
	i=0;
	for (j=1; j<n; j++)
	if(A[j]>A[0]) {
		i++;
		temp=A[i]; A[i]=A[j], A[j]=temp;
	}
	
	temp=A[0]; A[0]=A[i]; A[i]=temp;
	
	printf("���ҵ� ����� ���� �帮�ڽ��ϴ�.\n");
	for (i=0; i<n; i++) printf("%d, ", A[i]);
	printf("\n");
	
	return 0;
}
