#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i=1, sum=0;
	
	while(i<=10){
		sum = sum + i;
		i++; 
	}
	printf("1~10������ ���� %d �Դϴ�.\n", sum);
	
	return 0;
}
