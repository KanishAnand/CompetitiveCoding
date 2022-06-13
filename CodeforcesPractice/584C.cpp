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
	lli n,t;
	vector<lli> arr1(26,0),arr2(26,0),arr3(26,0),arr4(26,0),arr5(26,0);
	string s,p;
	lli c=0,d=0;
	cin>>n>>t;
	cin>>s>>p;
	fr(i,0,n){
		++arr1[s[i] - 'a'];
	}

	fr(i,0,n){
		++arr2[p[i] - 'a'];
	}	

	fr(i,0,26){
		if(arr1[i] >= 1 && arr2[i] >= 1){
			arr3[i] = min(arr1[i],arr2[i]);
			++c;
		}
	}
cerr<<c<<endl;
	lli x = n - t,common = 0;
	if(x > n/2){
		common = x - n/2;
		x -= common;
	}
cerr<<x<<common<<endl;
	string ans;
	fr(i,0,26){
		if(arr3[i] != 0){
			while(common > 0 && arr3[i] > 0){
				ans.pb(i + 'a');
				--arr3[i];
				--arr1[i];
				--arr2[i];
				--common;
			}
		}
		if(common == 0){
			break;
		}
	}

	if(common != 0){
		cout<<"-1"<<endl;
		rt;
	}

	lli a=0,b=0;
	fr(i,0,26){
		if(arr1[i] >= 1 && arr2[i] == 0){
			arr4[i] += arr1[i];
			a += arr1[i];
		}
		if(arr1[i] == 0 && arr2[i] >= 1){
			arr5[i] += arr2[i];
			b += arr2[i];
		}
	}

	cerr<<a<<b<<endl;
	lli y = min(a,b);
	y = min(y,x);
	lli o = y;
	x -= y;
	cerr<<x<<y<<endl;

	fr(i,0,26){
		if(y == 0){
			break;
		}
		while(arr4[i] > 0 && y > 0){
			ans.pb(i + 'a');
			--arr4[i];
			--arr1[i];
			--y;
		}
	}

	y = o;

	fr(i,0,26){
		if(y == 0){
			break;
		}
		while(arr5[i] > 0 && y > 0){
			ans.pb(i + 'a');
			--arr5[i];
			--arr2[i];
			--y;
		}
	}

	cerr<<ans<<endl;
	//cout<<x<<endl;
	fr(i,0,26){
		if(x == 0){
			break;
		}
		while(x > 0 && arr3[i] > 0){
			ans.pb(i + 'a');
			--x;
			--arr3[i];
		}
	}

	if(x != 0){
		cout<<"-1"<<endl;
		rt;
	}

	t = n - ans.size();
	fr(i,0,26){
		if(arr1[i] == 0 && arr2[i] == 0){
			while(t > 0){
				ans.pb(i + 'a');
				--t;
			}
		}
	}

	if(t != 0){
		cout<<"-1"<<endl;
		rt;
	}

	cout<<ans<<endl;
rt;
}








	
