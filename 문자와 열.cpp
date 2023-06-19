#include <stdio.h>
#include <string.h>
#define MaxLen 1000

int main()
{
	char line[MaxLen];
	int i, histogram[26]={0}, Histogram[26]={0};
	
	gets(line);
	
	for(i=0; i<strlen(line); i++)
	if(line[i]>='a'&& line[i]<='z') histogram[line[i]-'a']++;
	else if(line[i]>='A'&& line[i]<'Z') Histogram[line[i]-'A']++;
	
	for(i=0;i<26; i++)
	printf("%c: %d  %c: %d\n", 'a'+i, histogram[i],'A'+i,Histogram[i]);
	
	return 0; 
}
