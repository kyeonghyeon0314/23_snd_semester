#include <stdio.h>
#include <stdlib.h>
#define MaxSiz 100

float find_min(float [], int);
float find_max(float [], int);

int main()
{
	float d[MaxSiz], min, max;
	int i, no;
	
	printf("�Է��� �����ʹ� ��Դϱ�\n");
	scanf("%d", &no);
	
	if(no>MaxSiz) exit (0);
	
	for(i=0; i<no; i++) scanf("%f", &d[i]);
	
	min=find_min(d,no);
	max=find_max(d, no);
	
	printf("�ּ�ȭ�� �ִ�� %f�� %f�Դϴ�.\n", min, max);
	return 0;
}

float find_min(float arr[], int n)
{
	float minimum;
	int i;
	
	minimum=arr[0];
	for(i=1;i<n;i++)
	if(arr[i]<minimum) minimum=arr[i];
	
	return minimum;
}
