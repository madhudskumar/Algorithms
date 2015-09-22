#include "pre.h"

int a[SIZE][SIZE],n;
int source;
int u;
int count = 0;
int s[20] = {0};

void dfs(int source)
{
   int i;
	u = source;
   s[u] = 1;
	for (i = 1; i <= n; i++)
	{
		if(a[u][i] != 0 && s[i] != 1)
		{
			count++;
			dfs(i);
		}
	}
}

int main(int argc, char const *argv[])
{
  	int i,j;
	printf("n : \n");
	 scanf("%d",&n);

	printf("cam\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	source = 1;

	dfs(source);

	if((count) == n-1) printf("succ\n");
	
	else printf("fail\n");
	getch();
	return 0;
}