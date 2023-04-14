#include <stdio.h>
#include <malloc.h>
#include <string.h>

void reverse(char s[])
{
    int length = strlen(s) ;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

char sup_new_s[100];
char* sup_concat(char **s, int n)
{
	int lg=0, g[n];
	for(int i=0,h=0;i<n;i++)
	{
		h=0;
		while(s[i][h]!='\0') h++;
		g[i]=h;
		lg+=h;
	}
	char* new_s=(char*)malloc((lg+1)*sizeof(char));
	for(int i=0;i<lg+1;i++)
	    new_s[i]='\0';
	for(int h=0, i=0, j=0, flag=0, y=0;i<n;i++)
	{
		for(;(h<lg+1)&&(j<g[i]);j++, h++)
			new_s[h]=s[i][j];	
		
		for(int v=g[i]-1, a=0;(i!=n-1)&&(a>-1)&&(a<g[i+1]);)
		{
			if((v>-1)&&(s[i+1][a]==s[i][v]))
			{
				if(!flag)
					y=a;
				flag=1;
				a--;
				v--;
			}
			else if(flag==1)
			{
				flag=0;
				break;
			}
			else
			{
				flag=0;
				a++;
			}
		}	
		if(flag==1)
			j=y+1;
		else
			j=0;
		flag=0;
	}
	new_s[lg]='\0';
	strncpy(sup_new_s,new_s, 100);
	free(new_s);
	return sup_new_s;
}
int main()
{
    for(int i=0;i<100;i++)
        sup_new_s[i]='\0';
    int n;
    scanf("%d ", &n);
    if(n!=0)
    {
    	char** arr_1 =(char**) malloc(n * sizeof(char*));
    	for (int i = 0; i < n; i++) 
			arr_1[i] =(char*) malloc(100 * sizeof(char));

		for (int i = n-1; -1 < i; i--) 
			scanf("%s", arr_1[i]);
    	char *s_1=(char *)malloc(100*n*sizeof(char));
		strncpy (s_1, sup_concat(arr_1, n), 100*n);
		for(int i=strlen(s_1)+1;i<n*100;i++)
    		s_1[i]=' '; 
		int h_1=0;
    	for(int j=0;(j<100)&&(s_1[j]!='\0');j++)
    			h_1++;
    	
    	int min=10000;
    	if(n>3)
    	for(int f=0;f<n;f++)
    	    for(int m=0;m<n;m++)
    	        for(int c=0;c<n;c++)
    	            for(int z=0; z<n;z++)
    	    {
    	        if((m==f)||(m==c)||(m==z)||(c==z)||(c==f)||(z==f))
    	            continue;
        	    for(int i=0;i<100;i++)
                    sup_new_s[i]='\0';	
	    	    char** arr_3 =(char**) malloc(n * sizeof(char*));
	    	    for (int i = 0; i < n; i++) 
	    		    arr_3[i]=arr_1[i];
	    		char sup_arr_3[100];
	    		strcpy(sup_arr_3,arr_3[f]);
	    		strcpy(arr_3[f], arr_3[z]);
	    		strcpy(arr_3[z], arr_3[m]);
	    		strcpy(arr_3[m], arr_3[c]);
	    		strcpy(arr_3[c], sup_arr_3);
        	    char *s_3=(char *)malloc(100*n*sizeof(char));
	    	    strncpy (s_3, sup_concat(arr_3, n), 100*n);
	    	    for(int i=strlen(s_3)+1;i<n*100;i++)
            		s_3[i]=' '; 
        	    int h_3=0;
        	    for(int b=0;(b<100)&&(s_3[b]!='\0');b++)
    	       		h_3++;
    	        if(min>h_3)
    	            min=h_3;
    	        free(arr_3);
    	        free(s_3);
    	    }
    	else
    	for(int f=0;f<n;f++)
    	    for(int m=0;m<n;m++)
    	    {
    	        if(m==f)
    	        continue;
		    char** arr_3 =(char**) malloc(n * sizeof(char*));
		    for (int i = 0; i < n; i++) 
			    arr_3[i]=arr_1[i];
			char sup_arr_3[100];
			strcpy(sup_arr_3,arr_3[f]);
			strcpy(arr_3[f],arr_3[m]);
			strcpy(arr_3[m], sup_arr_3);
    	    char *s_3=(char *)malloc(100*n*sizeof(char));
		    strncpy (s_3, sup_concat(arr_3, n), 100*n);
		    for(int i=strlen(s_3)+1;i<n*100;i++)
        		s_3[i]=' '; 
    	    int h_3=0;
    	    for(int b=0;(b<100)&&(s_3[b]!='\0');b++)
    	    		h_3++;
    	    if(min>h_3)
    	        min=h_3;
    	    free(arr_3);
    	    free(s_3);
    	    }

		for (int i = 0; i < n; i++) free(arr_1[i]);
		free(arr_1);
		free(s_1);
		if(h_1<min)
			printf("%d", h_1);
		else
		    printf("%d", min);
	}
	else
		printf("0");
    return 0;
}
