#include "pre.h"

int ca[SIZE][SIZE] , n;

void kruskal();

int main(int argc, char const *argv[])
{
	int i,j;

	printf("enter n\n");
	 scanf("%d",&n);

	printf("enter cam\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d",&ca[i][j]);
         if(ca[i][j] == 0) ca[i][j] = INFINITY;
		}
	}

	kruskal();

	getch();
	return 0;
}

void kruskal()
{
	int i,j;
	int a,b,u,v;
	int parent[SIZES] = {0};
	int min,minCost = 0;
	int count = 1;

	while(count < n)
	{
		min = INFINITY;

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if(ca[i][j] < min)
				{
					min = ca[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}

		while(parent[u]) u = parent[u];

		while(parent[v]) v = parent[v];

		if(u != v)
		{
			printf("\n%d->%d : %d\n",a,b,min );
		    minCost += min;
		    count++;
		    parent[v] = u;
		}
		ca[a][b] = ca[b][a] = INFINITY;
	}

   printf("\nmin %d",minCost);

}
