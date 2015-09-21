#include "pre.h"

int a[10][10],n;
int rear,front;
int queue[20];
int source;
int s[20] = {0};
int k = 2,order[20];

void bfs();

void main()
{
	int i,j;
	printf("Enter n\n");
	 scanf("%d",&n);

	printf("ENter cam\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	source = 1;

	bfs();

	for (i = 1; i <= n; i++)
	{
		printf(" %d ",order[i] );
	}

	getch();
}

void bfs()
{
	int u;
   int i;
   int min;
	u = source;
	s[u] = 1;
	order[1] = 1;
	front = rear = -1;
	while(TRUE)
	{
		for (i = 1; i <= n; i++)
		{
			if (a[u][i] == 1 && s[i] != 1)
			{
				order[k++] = i;
				s[i] = 1;
				queue[++rear] = i;
			}
		}

		if(front == rear) break;
		u = queue[++front];
	}
}