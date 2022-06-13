#include <stdio.h>
int divide(int l, int r);
int merge(int l, int r);
int arr[100];
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	divide(0, n - 1);
	for (int i = 0; i <= n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

//0 based indexing...

int divide(int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		divide(l, mid);
		divide(mid + 1, r);
		merge(l, r);
	}
	return 0;
}

int merge(int l, int r)
{
	int mid = (l + r) / 2;
	int n1 = mid - l + 1, n2 = r - mid;
	int left[n1], right[n2];

	for (int i = 0; i < n1; i++)
	{
		left[i] = arr[l + i];
	}
	for (int j = 0; j < n2; j++)
	{
		right[j] = arr[mid + j + 1];
	}
	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			++i;
		}
		else
		{
			arr[k] = right[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		arr[k] = left[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		arr[k] = right[j];
		++j;
		++k;
	}
	return 0;
}
