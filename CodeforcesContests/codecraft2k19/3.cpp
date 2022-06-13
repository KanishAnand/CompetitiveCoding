#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long int llu;
llu arr[50][50]={0},val,n,k,a,b,c;
llu fun(llu l,llu r);
llu min(llu p,llu q);
llu dp[50][50]={0};

llu fun(llu l,llu r){
	if(l > r){
		return 0;
	}
	if(l == r){
		if(arr[l][r] == 0){
			dp[l][r] = a;
			return a;
		}
		else{
			dp[l][r] = b*arr[l][r]*1;
			return dp[l][r];
		}
	}

	if(arr[l][r] != 0){
		val = (r-l+1)*b*arr[l][r];
	}
	else{
		val = a;
	}

	if(dp[l][r] == 0){
		return dp[l][r] = min(val,(fun(l,(l+r)/2) + fun((l+r+1)/2,r)));
	}
	else{
		return dp[l][r];
	}

return dp[l][r];
}


llu min(llu p,llu q){
	return p < q ? p : q;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	llu arr[50][50]={0},n,k,a,b,a;
	cin>>n>>k>>a>>b;
	vector<llu> v;
	for(int i=0;i<k;i++){
		cin>>c;
		--c;
		v.push_back(c);
	}

	llu len=pow(2,n);
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			for(int l=0;l<k;l++){
				if(v[l] >= i && v[l] <= j){
					++arr[i][j];
				}
			}
		}
	}

//	llu len=pow(2,n);
	//	cout<<arr[0][0]<<endl;
	cout<<fun(0,len-1)<<endl;
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			cout<<i<<" "<<j<<endl;
			cout<<dp[i][j]<<" ";
		}
	}
return 0;
}




