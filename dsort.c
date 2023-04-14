#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dsort(char* string, long n)
{
    const int Number_of_Letters = 26;
    long letter_count[26] = {0};	
    for(long i = 0, index = 0; n > i; i++) 
    {
    	index = (long)((char)string[i] - 'a');
    	letter_count[index]++;
    }
    for(int i = 0; Number_of_Letters > i; i++)
        for(;letter_count[i]!=0; letter_count[i]--)
        {
    	    *string = (char)i + 'a';
    	    string+=sizeof(char);
        }
}

int main() 
{
    char string[1000000];
    scanf("%s", string);
    dsort(string, strlen(string));
    printf("%s", string);

  return 0;
}

