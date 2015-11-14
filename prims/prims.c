#include "pre.h"

int ca[SIZE][SIZE],n;
int s[SIZES] = {0};
int count = 0;
int min,minCost = 0;
int u,v,a,b;

void main()
{
	int i,j;
	printf("n:\n");
	 scanf("%d",&n);

	printf("cam\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d",&ca[i][j]);
         if(ca[i][j] == 0)ca[i][j] = INFINITY;
		}
	}

	s[1] = 1;
	while(count <= n+1)
	{
		min = INFINITY;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if(s[i] == 0) continue;

				else if(ca[i][j] < min)
				{
					min = ca[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}

		if(s[u] == 0 || s[v] == 0)
		{
			printf("%d-> %d : %d\n",a,b,min );
			minCost += min;
			s[v] = 1;
		}
		count++;
		ca[a][b] = ca[b][a] = INFINITY;
	}

	printf("%d\n",minCost );

	getch();
}