#include <stdio.h>

int main()
{
	int i,j,array[4][3];
	
	for (i=0;i<4; i++){
		for(j=0; j<3; j++){
			printf("�������� �Է��ϼ��� : ");
			scanf("%d",&array[i][j]);
		}
	}
	
	for(i=0;i<4;i++){
		for(j=0; j<3; j++){
			printf("%3d", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
