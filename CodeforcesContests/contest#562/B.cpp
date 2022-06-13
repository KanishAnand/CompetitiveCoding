#include<bits/stdc++.h>
using namespace std;
typedef long long int int1;
int main()
{
	int1 n,m,k,y1,y2,x1,x2;
	cin >> m>>n;
	vector<int1> a;
	for(int1 i=0;i<2*n;i++)
	{
		cin >>k;
		a.push_back(k);
	}
	int1 f=0;
	 x1= a[0];
	 x2=a[1];
	for(int1 i=0;i<2*n;i+=2)
	{
		if(a[i] == x1|| a[i+1] ==x1)
		{
			continue;
		}
		else
		{
			y1=a[i];
			 y2=a[i+1];
			 f=1;
		}
	}
	if(f==0)
	{
		cout << "YES" << endl;
		return 0;
	}
	f=0;
	for(int1 i=0;i<2*n;i+=2)
	{
		if(a[i] == x1 || a[i+1] ==x1 || a[i]==y1 || a[i+1]==y1)
		{
			continue;
		}
		else
		{
			 f=1;
		}
	}
	if(f==0)
	{
		cout << "YES" << endl;
		return 0;
	}
	f=0;
	for(int1 i=0;i<2*n;i+=2)
	{
		if(a[i] == x1 || a[i+1] ==x1 || a[i]==y2 || a[i+1]==y2)
		{
			continue;
		}
		else
		{
			 f=1;
		}
	}
	if(f==0)
	{
		cout << "YES" << endl;
		return 0;
	}
	f=0;
	for(int1 i=0;i<2*n;i+=2)
	{
		if(a[i] == x2|| a[i+1] ==x2)
		{
			continue;
		}
		else
		{
			y1=a[i];
			 y2=a[i+1];
			 f=1;
		}
	}
	if(f==0)
	{
		cout << "YES" << endl;
		return 0;
	}
	f=0;
	for(int1 i=0;i<2*n;i+=2)
	{
		if(a[i] == x2 || a[i+1] ==x2 || a[i]==y1 || a[i+1]==y1)
		{
			continue;
		}
		else
		{
			 f=1;
		}
	}
	if(f==0)
	{
		cout << "YES" << endl;
		return 0;
	}
	f=0;
	for(int1 i=0;i<2*n;i+=2)
	{
		if(a[i] == x2 || a[i+1] ==x2 || a[i]==y2 || a[i+1]==y2)
		{
			continue;
		}
		else
		{
			 f=1;
		}
	}
	if(f==0)
	{
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;





}