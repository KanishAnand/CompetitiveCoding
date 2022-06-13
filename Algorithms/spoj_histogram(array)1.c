#include <stdio.h>
typedef long long int lli;
lli stack[100005], top = -1;
lli push(lli val);
lli pop();
int main(void)
{
	lli n, arr[100005], l[100005], r[100005], ans;
	while (1)
	{
		scanf("%lld", &n);
		if (n == 0)
		{
			return 0;
		}
		top = -1;
		for (lli i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}

		push(0);
		l[0] = 0;
		for (lli i = 1; i < n; i++)
		{
			if (arr[i] > arr[stack[top]])
			{
				l[i] = i;
			}
			else
			{
				while (top != -1 && arr[stack[top]] >= arr[i]){
					l[i] = l[stack[top]];
					pop();
				}
			}
			push(i);
		}

/*
		for (lli i = 0; i < n; i++)
		{
			printf("%lld ", l[i]);
		}
		printf("\n");
*/
		top = -1;
		push(n - 1);
		r[n - 1] = n - 1;

		for (lli i = n - 2; i >= 0; i--)
		{
			if (arr[i] > arr[i+1])
			{
				r[i] = i;
			}
			else
			{
				while (top != -1 && arr[i] <= arr[stack[top]])
				{
					r[i] = r[stack[top]];
					pop();
				}
			}
			push(i);
		}

/*		for (lli i = 0; i < n; i++)
		{
			printf("%lld ", r[i]);
		}
		printf("\n");
*/		lli max = 0;
		for (lli i = 0; i < n; i++)
		{
			ans = (r[i] - l[i] + 1) * arr[i];
			if (ans > max)
			{
				max = ans;
			}
		}
		printf("%lld\n", max);
	}
	return 0;
}

lli push(lli val)
{
	stack[++top] = val;
}

lli pop()
{
	--top;
}
