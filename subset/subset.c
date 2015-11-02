#include "pre.h"

int a[20],n;
int sum = 0;
int d;

void subset();

void main()
{
 	int i;
 	printf("n:\n");
 	 scanf("%d",&n);
 	
 	printf("enter elements\n");
 	for (i = 1; i <= n; i++)
 	{
 		scanf("%d",&a[i]);
 		sum += a[i];
 	}

 	printf("enter sum\n");
 	 scanf("%d",&d);

 	if (d < a[1] || d > sum)
 	{
 		printf("error\n");
 	}

 	else subset();

 	getch();

}

void subset()
{
	int k = 1,x[20] = {0};
	int i;
	sum = 0;
	
	x[k] = 1;

	while(1)
{

	if(k <= n && x[k] == 1)
	{
		if (sum + a[k] == d)
		{
			for(i = 1; i <= n; i++) if(x[i] == 1)printf(" %d ",a[i] );
		   printf("\n");
			x[k] = 0;
		}

		else if(sum + a[k] < d)
		{
			sum += a[k];
		}

		else x[k] = 0;
	}

	else
	{
		k--;
		while( k > 0 && x[k] == 0) k--;

		if(k == 0) break;
		 
		 x[k] = 0;

		 sum -= a[k];
	}

	k++;
	x[k] = 1;
}
}