#include <iostream>
using namespace std;
int divide(int l, int r);
int merge(int l, int r);
int L[100005], R[100005], p[100005], q[100005];
int main(void)
{
	int t, n, key;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		int arr[n + 5];
		for (int j = 0; j < n; j++)
		{
			arr[j] = 2;
		}

		for (int j = 0; j < n; j++)
		{
			cin >> L[j] >> R[j];
			p[j] = L[j];
			q[j] = R[j];
		}

		divide(0, n - 1);

		int minv = p[n-1],min[100005],count=1;
		
		for(int j=n-1;j>=0;j--){
			if(p[j] < minv){
				minv = p[j];
			}
			min[j] = minv;
		}		

		arr[0] = 1;

		for (int j = 0; j < n-1; j++)
		{
			if (min[j+1] <= q[j])
			{
				++count;
				arr[j+1] = 1;
			}
			else{
				break;
			}
		}

		if (count == n)
		{
			cout << "-1";
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				cout << arr[j] << " ";
			}
		}
		cout << endl;
	}
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
	int ll[n1], rr[n2];

	for (int i = 0; i < n1; i++)
	{
		left[i] = q[l + i];
		ll[i] = p[l + i];
	}
	for (int j = 0; j < n2; j++)
	{
		right[j] = q[mid + j + 1];
		rr[j] = p[mid + j + 1];
	}
	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			q[k] = left[i];
			p[k] = ll[i];
			++i;
		}
		else
		{
			q[k] = right[j];
			p[k] = rr[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		q[k] = left[i];
		p[k] = ll[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		q[k] = right[j];
		p[k] = rr[j];
		++j;
		++k;
	}
	return 0;
}
