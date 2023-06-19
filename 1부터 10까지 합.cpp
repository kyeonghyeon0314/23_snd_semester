#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, sum;
	
	i=1;
	sum=0;
	
	while (i<=10){
		sum = sum + i;
		i = i + 1;
	}
	
	printf("1~10까지의 합은 %d 입니다.\n", sum);
	
	system("pause");
	return 0;
}
