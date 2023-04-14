#include <stdio.h>
#include <string.h>
#include <malloc.h>
void csort(char *src, char *dast)
{
	char **sup_str=(char **)malloc(1000*sizeof(char*));
	for(int i=0;i<1000;i++)
	    sup_str[i]=(char *)malloc(1000*sizeof(char));
	for(int i =0;i<1000;i++)
	   for(int j=0;j<1000;j++)
	        sup_str[i][j]=' ';
	int k=0;
	for(int i=0, h=0, t=0;src[i]!='\0';i++)
	{
		if((src[i]==' ')&&(src[i-1]==' '))
			continue;
		
		if(src[i]==' ')
		{
			sup_str[t][h]='\0';
			t++;
			k++;
			h=0;
		}
		else
		{
			sup_str[t][h]=src[i];
			h++;
		}
	}

	for(int i=0;i<1000;i++)
	{
	    if(sup_str[k][i]==' ')
	    {
	        sup_str[k][i]='\0';
	        break;
	    }
	}
	int i=1;
	while(i<1000)
	{
		if(sup_str[i][0]==' ')
			break;
		if((i>0)&&(strlen(sup_str[i-1])>strlen(sup_str[i])))
		{
			char intermediate_str [1000];
			strcpy(intermediate_str, sup_str[i-1]);
			strcpy(sup_str[i-1],sup_str[i]);
			strcpy(sup_str[i],intermediate_str);
			i--;
		}
		else
		i++;
	}

	k=0;
	for(int i=0, h=0, t=0;(h<1000)&&(i<1000)&&(t<1000)&&(sup_str[t][h]!=' ');i++,k++)
	{
		if(sup_str[t][h]=='\0')
		{
			dast[i]=' ';
			t++;
			h=0;
		}
		else
		{
			dast[i]=sup_str[t][h];
			h++;
		}
	}
	dast[k-1]='\0';
	
	for(int i=0;i<1000;i++)
		free(sup_str[i]);
	free(sup_str);
}

int main()
{
	char *str=(char*)malloc(1000*sizeof(char));
	char *new_str=(char *)malloc(1000*sizeof(char));	
	fgets(str, 999,stdin);
	str[strlen(str)-1]='\0';
	csort(str, new_str);
	printf("%s\n", new_str);
	free(str);
	free(new_str);
	return 0;
}
