#include "pre.h"

int a[SIZE][SIZE],n;
int d[SIZES];
int s[SIZES] = {0};
int min;
int source;

void dijkstra();

int main(int argc, char const *argv[])
{
	int i,j;

	printf("Enter n\n");
	 scanf("%d",&n);

   printf("Enter cam \n");

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	printf("Enter source\n");
	 scanf("%d",&source);

	dijkstra();

	for (i = 1; i <= n; i++)
	{
		printf("\n%d -> %d : %d\n",source,i,d[i] );
	}

	getch();
	return 0;
}

void dijkstra()
{
	int i,j;
	int u,w;

	for (i = 1; i <= n; i++)
	{
		d[i] = a[source][i];
	}

	s[source] = 1;
	d[source] = 0;

	for (j = 2; j <= n; j++)
	{
		min = INFINITY;

		for (i = 1; i <= n; i++)
		{
			if (!s[i])
			{
				if (d[i] < min)
				{
					min = d[i];
					u = i;
				}
			}
		}

		s[u] = 1;

		for( w = 1; w <= n; w++)
		{
			if(a[u][w] != INFINITY && s[w] != 1)
			{
				if(d[w] > d[u] + a[u][w]) d[w] = d[u] + a[u][w];
			}
		}
	}
}
