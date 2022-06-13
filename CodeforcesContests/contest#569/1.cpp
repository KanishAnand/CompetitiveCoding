#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
lli input(lli n);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	vector<lli> arr(120,0);
	cin>>n;	
    arr[1] = 1;
    arr[2] = 5;
    if(n == 1){
        cout<<"1"<<endl;
    }
    else{
        for(lli i=3;i<=100;i++){
            arr[i] = arr[i-1] + (i-2)*4 + 4;
        }
        cout<<arr[n]<<endl;
    }
rt;
}
	
