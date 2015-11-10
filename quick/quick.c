#include "pre.h"

void quick(int a[],int l,int h);
int part(int a[],int l,int h);

int main(int argc, char const *argv[])
{
	int a[SIZE],n;
	int i;
	clock_t start,end;

	printf("Enter the no of elements\n");
	 scanf("%d",&n);

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}

	printf("unsorted elemets\n");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
	}

	start = clock();

	quick(a,0,n-1);

	end = clock();

	printf("sorted elemets : %d\n",(end - start)/CLK_TCK);
	for (i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
	}

	return 0;
}

void quick(int a[],int l,int h)
{
	int j;
	if (l < h)
	{
		j = part(a,l,h);
		quick(a,l,j-1);
		quick(a,j+1,h);
	}
}

int part(int a[],int l,int h)
{
	int right = h,left = l;
	int key = a[l];
	void swap(int *a,int *b);

	while(TRUE)
	{
		while(left < right && key >= a[left]) left++;
		while(key < a[right]) right--;

		if (left < right)
		{
			swap(&a[left],&a[right]);
		}

		else
		{
			swap(&a[right],&a[l]);
			return right;
		}
	}
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}