#include <stdio.h>
#include <malloc.h>

char* concat(char **s, int n)
{
	int lg=0, g[n];
	for(int i=0,h=0;i<n;i++)
	{
		h=0;
		while(s[i][h]!='\0')
			h++;
		g[i]=h;
		lg+=h;
		
	}

	char* new_s=malloc((lg+1)*sizeof(char));

	for(int i=0,h=0;i<n;i++)
		for(int j=0;j<g[i];j++)
		{
			new_s[h]=s[i][j];
			h++;	
		}
	new_s[lg]='\0';
	return new_s;
}
int main()
{
    int n;
    scanf("%d ", &n);
    char** arr = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) 
		arr[i] = malloc(1000 * sizeof(char));
    
	for (int i = 0; i < n; i++) 
		scanf("%s", arr[i]);
    char *s = concat(arr, n);
    printf("%s", s);
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    free(s);
    return 0;
}
