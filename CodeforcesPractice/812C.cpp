#include <bits/stdc++.h> 
/*#include<iostream>
#include<algorithm>*/
typedef unsigned long long int lli;
using namespace std;
lli n,a[100005],b[100005];
lli cal(lli j);
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli s,min=100005,p,k;
	cin>>n>>s;
	for(lli i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] < min){
			min = a[i];
		}
	}
	
	for(lli i=n;i>=1;i--){
		p = i*(min + (i*(i+1))/2);
		if(p > s){
			if(i == 1){
				cout<<"0 0\n";
				return 0;
			}
			continue;
		}
		else{
			k = i;
			break;
		}
	}

	for(lli j = k; j >=1 ;j--){
		lli ans; 
		ans = cal(j);
		if(ans <= s){
			cout<<j<<" "<<ans<<"\n";
			return 0;
		}
	}
return 0;
}

//why cant we use void main in c++

lli cal(lli j){
	lli ans=0;
	for(lli i=1;i<=n;i++){
		b[i] = a[i] + i*j;
	}
	ans=0;
	sort(b,b+n);
	for(lli i=1;i<=j;i++){
		ans += b[i];
	}	
return ans;
}

