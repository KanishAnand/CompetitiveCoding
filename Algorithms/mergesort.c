#include <stdio.h>
int arr[1000000];
int divide(int l, int r);
int merge(int l, int mid, int r);
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	divide(1, n);
	for (int k = 1; k <= n; k++)
	{
		printf("%d\n", arr[k]);
	}

	return 0;
}
// done on 1 based indexing...

int divide(int l, int r)
{
	int mid;
	if (l < r)
	{
		mid = l + (r - l) / 2;
		divide(l, mid);
		divide(mid + 1, r);
		//	printf("l = %d r = %d\n",l,r);
		merge(l, mid, r);
	}
	return 0;
}

int merge(int l, int mid, int r)
{
	int n1, n2, i, j, k;

	n1 = mid - l + 1;
	n2 = r - mid;
	int left[n1], right[n2];

	for (i = 1; i <= n1; i++)
	{
		left[i] = arr[l + i - 1]; //see?
	}

	for (i = 1; i <= n2; i++)
	{
		right[i] = arr[i + mid];
	}

	i = 1;
	j = 1;
	k = l;

	while (i <= n1 && j <= n2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i <= n1)
	{
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j <= n2)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
	return 0;
}
