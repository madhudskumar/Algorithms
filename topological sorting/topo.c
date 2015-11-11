#include "pre.h"

int main(int argc, char const *argv[])
{
	int a[SIZE][SIZE],n;
	int i,j;
	int count = 0,k = 1;
	int rem[SIZES] = 0;
	int topo[SIZES];
	int done = FALSE;
	int indegree;

	printf("enter n\n");
	 scanf("%d",&n);
	 
	printf("Enter the matrix\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	while(done == FALSE)
	{
		done == TRUE;
		for (i = 0; i < n; i++)
		{
			if(rem[i] == 0)
			{
				indegree = 0;
				for (j = 0; j < n; j++)
				{
					if(a[i][j] != 0 && rem[j] == 0)
					{
						indegree = 1;
						break;
					}
				}

				if (indegree == 0)
				{
					rem[i] = 1;
					topo[k++] = i+1;
					count++;
					done = FALSE;
					break;
				}
			}
		}
	}

	if(count != n) printf("!EXISTS\n");
	
	else
	{
		for (i = count; i > 0; i--)
		{
			printf(" %d ", topo[i]);
		}
	}

	getch();
	return 0;
}