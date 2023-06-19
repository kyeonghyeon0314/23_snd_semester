#include <stdio.h>
#include <stdlib.h>
#define MaxSiz 100

float find_min(float [], int);
float find_maz(float [], int);

int main()

{
	float d[MaxSiz], min, max;
	int i, no;
	
	printf("입력할 데이터는 몇개입니까\n");
	scanf("%d", &no);
	
	if (no>MaxSiz) exit (0);
	
	for(i=0;i<no; i++) scanf("%f", &d[i]);
	
	min=max=d[0];
	for(i=1;i<no;i++){
		if(d[i]<min) min=d[i];
		if(d[i]>max) max=d[i];
	}
	
	printf("최소와 최대는 %f와 %f입니다.\n", min, max);
	return 0;
}

