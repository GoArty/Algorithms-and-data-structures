#include <stdio.h>
#include <string.h>

int bool_pword(const char* S, const char* T, int size_S, int size_T) 
{
    int sup_arr[size_S];
    sup_arr[0] = 0;
    for(int i = 1, index = 0; size_S > i; i++) 
    {
        while(S[index] != S[i] && index > 0) 
            index = sup_arr[index - 1];
        if(S[i] == S[index]) 
	    index++;
    	sup_arr[i] = index;
    }
    for(int i = 0, index = 0; size_T > i; i++) 
    {
        while(S[index] != T[i] && index > 0) 
	    index = sup_arr[index - 1];	
        if(T[i] == S[index]) 
	    index++;		
        if(index == 0) 
	    return 0;
        if(index == size_S) 
            index = 0;
    }
    return 1;
}


int main(int argc, char** argv) 
{
    char* S = argv[1];
    char* T = argv[2];
    int size_S = strlen(S), size_T = strlen(T);
    if(bool_pword(S, T, size_S, size_T))
	printf("yes");
    else 
	printf("no");
    return 0;
}
