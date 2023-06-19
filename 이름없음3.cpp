#include <stdio.h>

#define START -100.0
#define END 100.0
#define DELTA 5.0

int main()
{
	float celsius, fahrenheit=START;
	
	printf("È­¾¾  ¼·¾¾ ");
	while(fahrenheit<=END){
		celsius = (5.0/9.0)*(fahrenheit-32.0);
		printf("%f %f\n", fahrenheit, celsius);
		fahrenheit = fahrenheit + DELTA;
	}
	return 0;
}
