#include "pre.h"

int v[SIZE][SIZE];
int n;
int w[SIZES],p[SIZES];
int maxWeight;
int x[SIZES] = {0};

int maxval(int a,int b)
{
	return a>b?a:b;
}

int knap()
{
	int i,j;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= maxWeight; j++)
		{
			if(i == 0 || j == 0) v[i][j] = 0;

			else if(j < w[i]) v[i][j] = v[i-1][j];

			else v[i][j] = maxval(v[i-1][j],p[i] + v[i-1][j-w[i]]);
		}
	}

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= maxWeight; j++)
		{
			printf(" %d ", v[i][j]);
		}
      printf("\n");
	}

	return v[n][maxWeight];
}

int main(int argc, char const *argv[])
{
   int opt;
   int i,j;
	printf("Enter n\n");
	 scanf("%d",&n);

	printf("enter relevant weight and cost\n");
	for (i = 0; i < n; i++)
	{
		printf("%d > ", i+1 );
		 scanf("%d%d",&w[i],&p[i]);
	}

   printf("Enter max w\n");
    scanf("%d",&maxWeight);

   opt = knap();

	printf("opt sol = %d\n",opt );

	i = n;
	j = maxWeight;

	do
	{
		if(v[i][j] != v[i-1][j])
		{
			x[i] = 1;
			j -= w[i];
		}
      i -= 1;
	} while (i != 0 && j != 0);

	for (i = 0; i < n; i++)
	{
		printf(" %d ", x[i]);
	}

	getch();
	return 0;
}