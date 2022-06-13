#include<iostream>
#include<cstring>
using namespace std;
typedef long long int lli;
lli mod=1000000007;

// lli invmod(lli val){


// }


int main(void){
	char s[100];
	lli hash[100000],revhash[100000];
	cin>>s;
	lli len=strlen(s),no,p=101;

	hash[0] = s[0];
	no=1;
	for(int i=1;i<len;i++){
		hash[i] = (hash[i-1] + (s[i]*no*p)%mod)%mod;
		hash[i] %= mod;
		no = no*p;
	}

	revhash[len-1] = s[len-1];
	no = 1;
	
	for(int i=len-2;i>=0;i--){
		revhash[i] = (revhash[i+1] + (s[i]*no*p)%mod)%mod;
		revhash[i] %= mod;
		no *= p;
	}

	lli k,h,l,r,q;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>l>>r;
		h = hash[r] - hash[l-1];
		//h = invmod(h);
		k = hash[len - r - 1] - hash[len - l - 1];
		//k = invmod(k);
		if(h == k){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
return 0;
}