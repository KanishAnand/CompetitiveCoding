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
lli arr[1000000] = {0};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,a,steps=0;
	vector<lli> v1,v2;	cin>>n;	
	fr(i,0,n){
		cin>>a;
		v1.pb(a);
		arr[a] = 1;
	}
	fr(i,0,n){
		cin>>a;
		v2.pb(a);
		arr[a] = 2;
	}
	// fr(i,0,n){
	// 	cout<<v2[i]<<" ";
	// }
	//cout<<v2[1]<<endl;

	lli in=0;
	if(arr[1] == 2){
		fr(i,0,n){
			if(v2[i] == 1){
				arr[1] = 2;
				in = i;
				++in;
				steps++;
				break;
			}
			else{
				steps++;
				arr[v2[i]] = 1;
			}
		}
	}

	lli flag=0;
	if(arr[1] == 2){
		for(lli j=in-1;j<n;j++){
			if(v2[j] == 1 + j - (in - 1)){
				continue;
			}
			else{
				flag = 1;
				break;
			}
		}
		//cout<<flag<<endl;
		if(flag == 0){

			lli t = v2[n-1];
			for(lli p=0;p<in-1;p++){
				if(v2[p] != 0){
					if(p < v2[p] - t - 1){
						continue;
					}
					else{
						flag = 1;
						//cout<<p<<endl;
						break;
					}
				}
			}

			if(flag == 0){
				cout<<n - t<<endl;
				rt;
			}
		}
	}


	//++in;
	//cout<<in<<endl;
	//cout<<v2[1]<<endl;
	lli steps2 = 0;
	for(lli i=in;i<n;i++){
		if(v2[i] != 0){
	//		cout<<v2[i]<<endl;
			if(i - in < v2[i] - 1){
			//	cout<<"FD"<<endl;
				continue;
			}
			else{
				//cout<<"dd"<<endl;
				steps2 += i - in - (v2[i] - 2);
				in += i - in - (v2[i] - 2);
			}
		}
	}

	lli ans = steps2 + steps + n;
	//cout<<steps2<<endl;
	//cout<<steps<<endl;
	cout<<ans<<endl;
rt;
}


