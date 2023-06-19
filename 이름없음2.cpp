#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i=1, sum=0;
	
	while(i<=10){
		sum = sum + i;
		i++; 
	}
	printf("1~10까지의 합은 %d 입니다.\n", sum);
	
	return 0;
}
