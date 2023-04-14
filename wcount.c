#include <stdio.h>

int wcount(char *s)
{
    int k=0;
	for(int i=0; s[i]!='\0'; i++)
	{
		
		if((s[i]!='\n')&&(s[i]!='\t')&&(s[i]!=' '))
			if(i==0)
				k++;
			else if((s[i-1]=='\n')||(s[i-1]=='\t')||(s[i-1]==' '))
				k++;
	}
	return k;
}
int main()
{
    char* str[1000];
	gets(str);

	printf("%d", wcount(str));

    return 0;
}
